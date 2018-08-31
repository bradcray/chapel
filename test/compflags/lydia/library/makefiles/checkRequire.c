#include <stdio.h>

#include "lib/requireStmt.h"

extern void chpl_library_init(int argc, char* argv[]);
extern void chpl_library_finalize(void);

// Test of calling an exported function involving require statements
int main(int argc, char* argv[]) {
  // Initialize the Chapel runtime and standard modules
  chpl_library_init(argc, argv);
  chpl__init_requireStmt(0, 0);

  callsFoo();

  chpl_library_finalize();
  return 0;
}
