/*
 * Copyright 2021-2022 Hewlett Packard Enterprise Development LP
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "chpl/resolution/resolution-types.h"

#include "chpl/parsing/parsing-queries.h"
#include "chpl/framework/global-strings.h"
#include "chpl/framework/query-impl.h"
#include "chpl/framework/update-functions.h"
#include "chpl/resolution/resolution-queries.h"
#include "chpl/types/TupleType.h"
#include "chpl/uast/Builder.h"
#include "chpl/uast/FnCall.h"
#include "chpl/uast/OpCall.h"
#include "chpl/uast/Formal.h"
#include "chpl/uast/Identifier.h"
#include "chpl/uast/For.h"
#include "chpl/uast/VarArgFormal.h"

namespace chpl {
namespace resolution {

using namespace uast;
using namespace types;

const owned<UntypedFnSignature>&
UntypedFnSignature::getUntypedFnSignature(Context* context, ID id,
                                          UniqueString name,
                                          bool isMethod,
                                          bool isTypeConstructor,
                                          bool isCompilerGenerated,
                                          asttags::AstTag idTag,
                                          uast::Function::Kind kind,
                                          std::vector<FormalDetail> formals,
                                          const AstNode* whereClause) {
  QUERY_BEGIN(getUntypedFnSignature, context,
              id, name, isMethod, isTypeConstructor, isCompilerGenerated,
              idTag, kind, formals, whereClause);

  owned<UntypedFnSignature> result =
    toOwned(new UntypedFnSignature(id, name,
                                   isMethod, isTypeConstructor,
                                   isCompilerGenerated, idTag, kind,
                                   std::move(formals), whereClause));

  return QUERY_END(result);
}

const UntypedFnSignature*
UntypedFnSignature::get(Context* context, ID id,
                        UniqueString name,
                        bool isMethod,
                        bool isTypeConstructor,
                        bool isCompilerGenerated,
                        asttags::AstTag idTag,
                        uast::Function::Kind kind,
                        std::vector<FormalDetail> formals,
                        const uast::AstNode* whereClause) {
  return getUntypedFnSignature(context, id, name,
                               isMethod, isTypeConstructor,
                               isCompilerGenerated, idTag, kind,
                               std::move(formals), whereClause).get();
}

static const UntypedFnSignature*
getUntypedFnSignatureForFn(Context* context, const uast::Function* fn) {
  const UntypedFnSignature* result = nullptr;

  if (fn != nullptr) {
    // compute the FormalDetails
    std::vector<UntypedFnSignature::FormalDetail> formals;
    for (auto decl : fn->formals()) {
      UniqueString name;
      bool hasDefault = false;
      if (auto formal = decl->toFormal()) {
        name = formal->name();
        hasDefault = formal->initExpression() != nullptr;
      } else if (auto varargs = decl->toVarArgFormal()) {
        name = varargs->name();

        // This should not be possible. Currently varargs with a default value
        // will be considered a syntax error.
        hasDefault = false;
        assert(varargs->initExpression() == nullptr);
      }

      auto fd = UntypedFnSignature::FormalDetail(name, hasDefault,
                                                 decl, decl->isVarArgFormal());
      formals.push_back(fd);
    }

    // find the unique-ified untyped signature
    result = UntypedFnSignature::get(context, fn->id(), fn->name(),
                                     fn->isMethod(),
                                     /* isTypeConstructor */ false,
                                     /* isCompilerGenerated */ false,
                                     /* idTag */ asttags::Function,
                                     fn->kind(),
                                     std::move(formals), fn->whereClause());
  }

  return result;
}

const UntypedFnSignature* UntypedFnSignature::get(Context* context,
                                                  const Function* function) {
  if (function == nullptr) {
    return nullptr;
  }

  return getUntypedFnSignatureForFn(context, function);
}

static const UntypedFnSignature* const&
getUntypedFnSignatureForIdQuery(Context* context, ID functionId) {
  QUERY_BEGIN(getUntypedFnSignatureForIdQuery, context, functionId);

  const UntypedFnSignature* result = nullptr;
  const AstNode* ast = parsing::idToAst(context, functionId);

  if (ast != nullptr && ast->isFunction()) {
    result = getUntypedFnSignatureForFn(context, ast->toFunction());
  }

  return QUERY_END(result);
}

const UntypedFnSignature* UntypedFnSignature::get(Context* context,
                                                  ID functionId) {
  if (functionId.isEmpty()) {
    return nullptr;
  }

  return getUntypedFnSignatureForIdQuery(context, functionId);
}

CallInfo::CallInfo(const uast::FnCall* call) {
  // set the name (simple cases only)
  if (auto called = call->calledExpression()) {
    if (auto id = called->toIdentifier()) {
      name_ = id->name();
      // should not be a valid operator name
      assert(!uast::isOpName(name_));
    }
  }

  isOpCall_ = false;

  int i = 0;
  for (auto actual : call->actuals()) {
    if (isQuestionMark(actual)) {
      hasQuestionArg_ = true;
    } else {
      UniqueString byName;
      if (call->isNamedActual(i)) {
        byName = call->actualName(i);
        if (i == 0 && byName == USTR("this"))
          isMethodCall_ = true;
      }
      actuals_.push_back(CallInfoActual(QualifiedType(), byName));
      i++;
    }
  }
}

void ResolutionResultByPostorderID::setupForSymbol(const AstNode* ast) {
  assert(Builder::astTagIndicatesNewIdScope(ast->tag()));
  vec.resize(ast->id().numContainedChildren());

  symbolId = ast->id();
}
void ResolutionResultByPostorderID::setupForSignature(const Function* func) {
  int maxPostorderId = 0;
  if (func && func->numChildren() > 0)
    maxPostorderId = func->child(func->numChildren() - 1)->id().postOrderId();
  assert(0 <= maxPostorderId);
  vec.resize(maxPostorderId + 1);

  symbolId = func->id();
}
void ResolutionResultByPostorderID::setupForParamLoop(const For* loop, ResolutionResultByPostorderID& parent) {
  int bodyPostorder = 0;
  if (loop && loop->body())
    bodyPostorder = loop->body()->id().postOrderId();
  assert(0 <= bodyPostorder);
  vec.resize(bodyPostorder);

  this->symbolId = parent.symbolId;
}
void ResolutionResultByPostorderID::setupForFunction(const Function* func) {
  setupForSymbol(func);
}

bool ResolutionResultByPostorderID::update(ResolutionResultByPostorderID& keep,
                                           ResolutionResultByPostorderID& addin)
{
  return defaultUpdate(keep, addin);
}

bool FormalActualMap::computeAlignment(const UntypedFnSignature* untyped,
                                       const TypedFnSignature* typed,
                                       const CallInfo& call) {

  // untyped must be provided but typed can be nullptr.
  assert(untyped);

  // create the mapping handling named and default arguments

  // TODO are these reused??
  // clear the current mapping
  byFormalIdx_.clear();
  actualIdxToFormalIdx_.clear();
  mappingIsValid_ = false;
  failingActualIdx_ = -1;

  int numFormals = untyped->numFormals();
  int numEntries = numFormals;

  // The specified number of varargs in the formal isn't known at this point,
  // so we need to build the entries in terms of the number of varargs that the
  // caller is attempting to pass.
  int attemptedNumVarArgs = 0;

  // allocate space in the arrays
  byFormalIdx_.resize(numEntries);
  actualIdxToFormalIdx_.resize(call.numActuals());

  // initialize the FormalActual parts from the Formals
  int entryIdx = 0;
  int numVarArgFormals = 0;
  for (int i = 0; i < numFormals; i++) {

    const Decl* decl = untyped->formalDecl(i);
    QualifiedType formalQT;
    bool formalInstantiated = false;

    if (typed != nullptr) {
      formalQT = typed->formalType(i);
      if (typed->instantiatedFrom() != nullptr) {
        formalInstantiated = typed->formalIsInstantiated(i);
      }
    }

    if (untyped->formalIsVarArgs(i) == false) {
      FormalActual& entry = byFormalIdx_[entryIdx];

      entry.formal_ = decl;
      entry.hasActual_ = false;
      entry.formalIdx_ = i;
      entry.actualIdx_ = -1;
      entry.formalType_ = formalQT;
      entry.formalInstantiated_ = formalInstantiated;
      entry.hasDefault_ = untyped->formalHasDefault(i);

      entryIdx++;
    } else {
      numVarArgFormals += 1;

      if (numVarArgFormals > 1) {
        return false;
      }

      // zero-sized varargs not currently supported
      int numExtra = call.numActuals() - numFormals;
      attemptedNumVarArgs = std::max(numExtra + 1, 1);
      numEntries = numFormals + attemptedNumVarArgs - 1;
      byFormalIdx_.resize(numEntries);

      if (formalQT.type() != nullptr) {
        const TupleType* tup = formalQT.type()->toTupleType();
        formalQT = tup->starType();
      }

      for (int j = 0; j < attemptedNumVarArgs; j++) {
        FormalActual& entry = byFormalIdx_[entryIdx];

        entry.formal_ = decl;
        entry.hasActual_ = false;
        entry.formalIdx_ = i;
        entry.actualIdx_ = -1;
        entry.formalType_ = formalQT;
        entry.formalInstantiated_ = formalInstantiated;
        entry.hasDefault_ = untyped->formalHasDefault(i);
        entry.isVarArgEntry_ = true;

        entryIdx++;
      }
    }
  }

  assert(entryIdx == numEntries);

  // Match named actuals against formal names in the function signature.
  // Record successful matches in actualIdxToFormalIdx.

  // TODO: This should just be a string to int map...
  for (size_t actualIdx = 0; actualIdx < call.numActuals(); actualIdx++) {
    const CallInfoActual& actual = call.actual(actualIdx);
    if (!actual.byName().isEmpty()) {
      bool match = false;
      int entryIdx = 0;
      for (int i = 0; i < numFormals; i++) {
        FormalActual& entry = byFormalIdx_[entryIdx];
        match = actual.byName() == untyped->formalName(i);
        assert(entry.formal_ == untyped->formalDecl(i));

        if (entry.isVarArgEntry_) {
          // TODO: production compiler doesn't support named VarArgs, but
          // that appears to be an implementation limitation...
          if (match) {
            failingActualIdx_ = actualIdx;
            return false;
          }
          // Skip the other VarArgs
          entryIdx += attemptedNumVarArgs;
        } else {
          if (match) {
            entry.hasActual_ = true;
            entry.actualIdx_ = actualIdx;
            entry.actualType_ = actual.type();
            actualIdxToFormalIdx_[actualIdx] = entryIdx;
            break;
          }

          entryIdx++;
        }
      }

      // Fail if no matching formal is found.
      if (match == false) {
        failingActualIdx_ = actualIdx;
        // TODO: track failure type for error messages
        return false;
      }
    }
  }

  // Fill in unmatched formals in sequence with the remaining actuals.
  // Record successful substitutions
  entryIdx = 0;
  int actualIdx = 0;
  for (const CallInfoActual& actual : call.actuals()) {
    if (entryIdx >= numEntries) {
      // too many actuals
      failingActualIdx_ = actualIdx;
      return false;
    }

    if (actual.byName().isEmpty()) {
      // Skip any formals already matched to named arguments
      while (byFormalIdx_[entryIdx].hasActual_) {
        if (entryIdx + 1 >= numEntries) {
          // too many actuals
          failingActualIdx_ = actualIdx;
          return false;
        }
        entryIdx++;
      }
      assert(entryIdx < numEntries);

      // if this is a call to an operator method, skip the 'this' formal
      if (call.isOpCall() && untyped->formalName(entryIdx) == USTR("this")) {
        entryIdx++;
      }

      FormalActual& entry = byFormalIdx_[entryIdx];
      entry.hasActual_ = true;
      entry.actualIdx_ = actualIdx;
      entry.actualType_ = actual.type();
      actualIdxToFormalIdx_[actualIdx] = entryIdx;
    }
    actualIdx++;
  }

  if (!untyped->isTypeConstructor()) {
    // Make sure that any remaining formals are matched by name
    // or have a default value.
    // This is left out for type constructors because presently
    // a partial instantiation is provided by simply leaving out arguments.
    for (;entryIdx < numEntries; entryIdx++) {
      FormalActual& entry = byFormalIdx_[entryIdx];
      if (entry.actualIdx_ < 0) {
        if (entry.hasDefault() == false) {
          // formal was not provided and there is no default value
          failingFormalIdx_ = entry.formalIdx();
          return false;
        }
      }
    }
  }

  return true;
}

void ResolvedFields::finalizeFields(Context* context) {
  bool anyGeneric = false ;
  bool allGenHaveDefault = true; // all generic fields have default init
                                 // -- vacuously true if there are no generic

  std::set<const Type*> ignore;
  ignore.insert(type_);

  // look at the fields and compute the summary information
  for (auto field : fields_) {
    auto g = getTypeGenericityIgnoring(context, field.type, ignore);
    if (g != Type::CONCRETE) {
      if (!field.hasDefaultValue) {
        allGenHaveDefault = false;
      }
      anyGeneric = true;
    }
  }

  isGeneric_ = anyGeneric;
  allGenericFieldsHaveDefaultValues_ = allGenHaveDefault;
}

const owned<TypedFnSignature>&
TypedFnSignature::getTypedFnSignature(Context* context,
                    const UntypedFnSignature* untypedSignature,
                    std::vector<types::QualifiedType> formalTypes,
                    TypedFnSignature::WhereClauseResult whereClauseResult,
                    bool needsInstantiation,
                    const TypedFnSignature* instantiatedFrom,
                    const TypedFnSignature* parentFn,
                    Bitmap formalsInstantiated) {
  QUERY_BEGIN(getTypedFnSignature, context,
              untypedSignature, formalTypes, whereClauseResult,
              needsInstantiation, instantiatedFrom, parentFn,
              formalsInstantiated);

  auto result = toOwned(new TypedFnSignature(untypedSignature,
                                             std::move(formalTypes),
                                             whereClauseResult,
                                             needsInstantiation,
                                             instantiatedFrom,
                                             parentFn,
                                             std::move(formalsInstantiated)));

  return QUERY_END(result);
}

const TypedFnSignature*
TypedFnSignature::get(Context* context,
                      const UntypedFnSignature* untypedSignature,
                      std::vector<types::QualifiedType> formalTypes,
                      TypedFnSignature::WhereClauseResult whereClauseResult,
                      bool needsInstantiation,
                      const TypedFnSignature* instantiatedFrom,
                      const TypedFnSignature* parentFn,
                      Bitmap formalsInstantiated) {
  return getTypedFnSignature(context, untypedSignature,
                             std::move(formalTypes),
                             whereClauseResult,
                             needsInstantiation,
                             instantiatedFrom,
                             parentFn,
                             std::move(formalsInstantiated)).get();
}

void TypedFnSignature::stringify(std::ostream& ss,
                                 chpl::StringifyKind stringKind) const {
  id().stringify(ss, stringKind);
  ss << "(";
  int nFormals = numFormals();
  for (int i = 0; i < nFormals; i++) {
    if (i != 0) {
      ss << ", ";
    }
    formalName(i).stringify(ss, stringKind);
    ss << " : ";
    formalType(i).stringify(ss, stringKind);
  }
  ss << ")";
}

void CallInfoActual::stringify(std::ostream& ss,
                               chpl::StringifyKind stringKind) const {
  if (!byName_.isEmpty()) {
    byName_.stringify(ss, stringKind);
    ss << "=";
  }

  type_.stringify(ss, stringKind);
}

void CallInfo::stringify(std::ostream& ss,
                         chpl::StringifyKind stringKind) const {
  if (stringKind != StringifyKind::CHPL_SYNTAX) {
    ss << "CallInfo with name '";
    name_.stringify(ss, stringKind);
    ss << "'";
  } else {
    name_.stringify(ss, stringKind);
  }
  if (calledType_ != QualifiedType()) {
    ss << " receiver type: ";
    calledType_.stringify(ss, stringKind);
  }
  if (stringKind != StringifyKind::CHPL_SYNTAX) {
    ss << " isMethodCall=" << isMethodCall_;
    ss << " isOpCall=" << isOpCall_;
    ss << " hasQuestionArg=" << hasQuestionArg_;
    ss << " ";
  }
  ss << "(";
  bool first = true;
  for (auto actual: actuals()) {
    if (first) {
      first = false;
    } else {
      ss << ",";
    }
    actual.stringify(ss, stringKind);
  }
  ss << ")";
}

void PoiInfo::accumulate(const PoiInfo& addPoiInfo) {
  poiFnIdsUsed_.insert(addPoiInfo.poiFnIdsUsed_.begin(),
                      addPoiInfo.poiFnIdsUsed_.end());
}

// this is a resolved function
// check is a not-yet-resolved function
bool PoiInfo::canReuse(const PoiInfo& check) const {
  assert(resolved_ && !check.resolved_);

  return false; // TODO -- consider function names etc -- see PR #16261
}

void ResolvedExpression::stringify(std::ostream& ss,
                                   chpl::StringifyKind stringKind) const {
  ss << " : ";
  type_.stringify(ss, stringKind);
  ss << " ; ";
  if (!toId_.isEmpty()) {
    ss << " refers to ";
    toId_.stringify(ss, stringKind);
  } else {
    auto onlyFn = mostSpecific_.only();
    if (onlyFn) {
      ss << " calls ";
      onlyFn->stringify(ss, stringKind);
    } else {
      if (auto sig = mostSpecific_.bestRef()) {
        ss << " calls ref ";
        sig->stringify(ss, stringKind);
      }
      if (auto sig = mostSpecific_.bestConstRef()) {
        ss << " calls const ref ";
        sig->stringify(ss, stringKind);
      }
      if (auto sig = mostSpecific_.bestValue()) {
        ss << " calls value ";
        sig->stringify(ss, stringKind);
      }
    }
  }
}

IMPLEMENT_DUMP(PoiInfo);
IMPLEMENT_DUMP(UntypedFnSignature);
IMPLEMENT_DUMP(UntypedFnSignature::FormalDetail);
IMPLEMENT_DUMP(TypedFnSignature);
IMPLEMENT_DUMP(ResolvedExpression);
IMPLEMENT_DUMP(CallInfoActual);
IMPLEMENT_DUMP(CallInfo);

} // end namespace resolution
} // end namespace chpl
