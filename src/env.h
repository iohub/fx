
#ifndef FXENV_H
#define FXENV_H

#include "type.h"

namespace fx {

struct Env : public std::map<std::string, Ty> {
public:
    Ty lookup(std::string const &nominal) const {
        auto itr = this->find(nominal);
        return itr == this->end() ? Ty(TypeID::Nil) : itr->second;
    }

};



};

#endif
