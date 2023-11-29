# `chplcheck`: A Chapel Linter

`chplcheck` is a linter for the Chapel programming language implemented in
Python using the [Python bindings for the compiler frontend](https://github.com/chapel-lang/chapel/tree/main/tools/chapel-py).
It is intended to catch stylistic mistakes and bad practices in Chapel programs.
It is also intended to be customizable and extensible, using a system of named
'rules' that lead to warnings.

`chplcheck` supports the Language Server Protocol, allowing it to be used as
part of your favorite editor. The following image demonstrates its use in Neovim:

![Screenshot of code using `chplcheck`](./ineditor.png)

## Getting Started

The easiest way to make `chplcheck` available on your command line is by using the
`chplcheck` Makefile target. This will build the Dyno compiler frontend and the
Python bindings for Dyno if needed, and place `chplcheck` into `$CHPL_HOME/bin`.
In from-source builds, this directory should already be in your `PATH`;
this means you should be invoke `chplcheck` from the command-line without any
additional work.

```
cd $CHPL_HOME
make chplcheck -j32
chplcheck --help
```

Saving the following file into `myfile.chpl`:

```Chapel
record MyRecord {}

for i in 1..10 do {
  writeln("Hello, world!");
}
```

we can run the linter as follows:

```
> chplcheck myfile.chpl
path/to/myfile/myfile.chpl:1: node violates rule CamelCaseRecords
path/to/myfile/myfile.chpl:3: node violates rule DoKeywordAndBlock
path/to/myfile/myfile.chpl:3: node violates rule UnusedLoopIndex
```

## Enabling / Disabling Rules

Each rule, such as `CamelCaseRecords`, can be individually enabled or disabled
from the command line using `--enable-rule` and `--disable-rule`. Thus, if
we don't want to hear about unused loop indices such as `i` in the above code,
we can invoke `chplcheck` as follows:

```
> chplcheck myfile.chpl --disable-rule UnusedLoopIndex
path/to/myfile/myfile.chpl:1: node violates rule CamelCaseRecords
path/to/myfile/myfile.chpl:3: node violates rule DoKeywordAndBlock
```

Some rules are disabled by default. One such rule is `UseExplicitModules`, which
warns against letting Chapel automatically create the top-level module in a file.

```
> chplcheck myfile.chpl --enable-rule UseExplicitModules
path/to/myfile/myfile.chpl:1: node violates rule CamelCaseRecords
path/to/myfile/myfile.chpl:1: node violates rule UseExplicitModules
path/to/myfile/myfile.chpl:3: node violates rule DoKeywordAndBlock
path/to/myfile/myfile.chpl:3: node violates rule UnusedLoopIndex
```

All of the rules present in `chplcheck` right now are defined in `./src/rules.py`.
Thus, you may reference this file to get a complete list of available rules.
Rules marked with `default=False` are not enabled by default, and need to
be turned on using the `--enable-rule` flag; rules without the above setting
are enabled by default, and can be turned off using `--disable-rule`.

## Setting Up In Your Editor

`chplcheck` uses the Language Server Protocol to integrate with compatible clients.
Thus, if your editor supports LSP, you can configure it to display linting warnings
via `chplcheck`. The linter hasn't yet been set up in many different editors;
this section will be updated with more editors as they are tested.

### Neovim

In Neovim, the built-in LSP API can be used to configure `chplcheck` as
follows:

```Lua
local lspconfig = require 'lspconfig'
local configs = require 'lspconfig.configs'
local util = require 'lspconfig.util'

configs.chplcheck = {
  default_config = {
    cmd = {"chplcheck", "--lsp"},
    filetypes = {'chpl'},
    autostart = true,
    single_file_support = true,
    root_dir = function(fname)
      local res = util.find_git_ancestor(fname)
      print(res)
      return res
    end,
    settings = {},
  },
}

lspconfig.chplcheck.setup{}
vim.cmd("autocmd BufRead,BufNewFile *.chpl set filetype=chpl")
```

## Writing Rules

Rules are written using the Python bindings for Chapel's compiler frontend.
You might want to consult the [`README` file](https://github.com/chapel-lang/chapel/tree/main/tools/chapel-py#readme)
for `chapel-py` to see examples of Python code working with the AST. In
essence, a rule is a Python function that's used to detect issues with the
AST. When registered with `chplcheck`, the name of the function becomes the name
of the rule (which can be used to enable and disable the rule, as per the
above sections). To mark a Python function as representing a rule, `chplcheck`'s
Python API provides two decorators. These decorators correspond to the two
'flavors' of rules in the linter. The two 'flavors' of rules in `chplcheck` are
'basic' and 'advanced'.

### Basic Rules

Basic rules are specified using a pattern (see the [pattern matching section of the `chapel-py` `README`](https://github.com/chapel-lang/chapel/tree/main/tools/chapel-py#chapelmatch_pattern)).
This pattern represents which AST nodes should be scrutinized to check if something.
The `driver.basic_rule` decorator is used to specify such rules. For instance,
the following basic rule checks that explicit modules have `PascalCase` naming:

```Python
@driver.basic_rule(Module)
def PascalCaseModules(context, node):
    return node.kind() == "implicit" or check_pascal_case(node)
```

The `Module` argument to `basic_rule` specifies that the linter should call
the `PascalCaseModules` function with each `Module` node it encounters. If
the function returns `True`, all is well, and no warning should be emitted.
On the other hand, if the function returns `False`, the linter should produce
a warning. The conditional returns `True` for all implicit modules, regardless
of their name: this is because implicit modules are named after the file they
are in, so the user cannot "fix" the code by editing it. For explicit modules,
a helper function `check_pascal_case` is used to ensure that the node's name
is appropriately cased.

As described in the `chapel-py` `README`, patterns can be more advanced than
simply specifying an AST node type. The following rule makes more use of
patterns by specifying that it should be applied only to `if`-statements
that just have a boolean literal as their condition.

```Python
@driver.basic_rule([Conditional, BoolLiteral, chapel.rest])
def BoolLitInCondStmt(context, node):
    return False
```

### Advanced Rules

Sometimes, specifying a pattern is not precise enough to implement a rule.
Alternatively, a linting check might require considering two sibling nodes,
or other less-straightforward relationships than "does it match the pattern?".
This is the purpose of advanced rules. These functions are called with the
_root_ AST node (usually one of the top-level `Module`s). Then, it's the
responsibility of the function to find and `yield` AST nodes that should be
warned about. For instance, at the time of writing, the following rule
implements checking for unused formals.

```Python
@driver.advanced_rule
def UnusedFormal(context, root):
    formals = dict()
    uses = set()

    for (formal, _) in chapel.each_matching(root, Formal):
        # For now, it's harder to tell if we're ignoring 'this' formals
        # (what about method calls with implicit receiver?). So skip
        # 'this' formals.
        if formal.name() == "this":
            continue

        # extern functions have no bodies that can use their formals.
        if formal.parent().linkage() == "extern":
            continue

        formals[formal.unique_id()] = formal

    for (use, _) in chapel.each_matching(root, Identifier):
        if refersto := use.to_node():
            uses.add(refersto.unique_id())

    for unused in formals.keys() - uses:
        yield formals[unused]
```

This function performs _two_ pattern-based searches: one for formals, and one
for identifiers that might reference the formals. It then emits a warning for
each formal for which there wasn't a corresponding identifier.
