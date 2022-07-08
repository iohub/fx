#ifndef FX_AST_LOC_
#define FX_AST_LOC_

#include <stdint.h>

namespace fx {

struct Loc {
    Loc(int line, int colmn): lineno(line), colmnno(colmn) {}
    Loc() {}
    int lineno;
    int colmnno;
};



};

#endif
