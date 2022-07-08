
#ifndef FXENV_H
#define FXENV_H

#include "type.h"
#include "astnode.h"

namespace fx {

class Env {
public:
    Ty lookup_var(std::string const &nominal) const {
        auto itr = vars_.find(nominal);
        return itr == vars_.end() ? Ty(TypeID::Nil) : itr->second;
    }

    Ty lookup_func(std::string const &nominal) const {
        auto itr = funs_.find(nominal);
        return itr == funs_.end() ? Ty(TypeID::Nil) : itr->second;
    }

    void put(AstNodePtr node) {
        if (VarDecl *nn = dynamic_cast<VarDecl*>(node.get())) {
            vars_[nn->nominal()] = nn->Type();
        } else if (FuncDecl *nn = dynamic_cast<FuncDecl*>(node.get())) {
            funs_[node->nominal()] = node->Type();
        }
    }


private:
    std::map<std::string, Ty> vars_;
    std::map<std::string, Ty> funs_;

};



};

#endif
