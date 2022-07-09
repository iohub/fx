
#ifndef FXENV_H
#define FXENV_H

#include "type.h"
#include "astnode.h"

namespace fx {

class Env {
public:
    AstNodePtr lookup_var(std::string const &nominal) const {
        auto itr = vars_.find(nominal);
        return itr == vars_.end() ? AstNodePtr(nullptr): itr->second;
    }

    AstNodePtr lookup_func(std::string const &nominal) const {
        auto itr = funs_.find(nominal);
        return itr == funs_.end() ? AstNodePtr(nullptr) : itr->second;
    }

    void put(AstNodePtr node) {
        if (VarDecl *nn = dynamic_cast<VarDecl*>(node.get())) {
            vars_[nn->nominal()] = node;
        } else if (FuncDecl *nn = dynamic_cast<FuncDecl*>(node.get())) {
            funs_[node->nominal()] =  node;
        }
    }


private:
    std::map<std::string, AstNodePtr> vars_;
    std::map<std::string, AstNodePtr> funs_;

};



};

#endif
