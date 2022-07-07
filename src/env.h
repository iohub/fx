
#ifndef FXENV_H
#define FXENV_H

#include "type.h"
#include "astnode.h"

namespace fx {

class Env {
public:
    Ty lookup(std::string const &nominal) const {
        auto itr = vars_.find(nominal);
        return itr == vars_.end() ? Ty(TypeID::Nil) : itr->second;
    }

    void put(AstNodePtr node) {
        std::map<std::string, Ty> &ref = vars_;
        ref[node->nominal()] = node->Type();
    }


private:
    std::map<std::string, Ty> vars_;
    std::map<std::string, Ty> funs_;

};



};

#endif
