
#include "astnode.h"

namespace fx {

void AstNode::print() {
    std::string tab = "";
    std::string ctree = sexp();
    std::string out = "";
    for (char c: ctree) {
        if (c == '(') {
            tab.push_back('\t');
            out += "\n" + tab;
        } else if (c == ')') {
            tab.pop_back();
        } else {
            out.push_back(c);
        }
    }
    fmt::print("{}\n", out.c_str());
}

}

