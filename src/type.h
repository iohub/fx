
#ifndef fx_TYPE_H_
#define fx_TYPE_H_

#include <stdint.h>

namespace fx {


struct Ty {

    enum class ID: uint32_t {
        Invalid,
        Int, Float, Bool, Str, Void,
        Arrow,
        Object,
    };

    Ty(ID k): id(k) {}
    Ty(): id(ID::Invalid) {}

    bool operator==(const Ty& b) {
        return id == b.id;
    }

    bool valid() const {
        return id != ID::Invalid;
    }

    ID id = ID::Invalid;
};

typedef Ty::ID TypeID;



}; // namespace fx



#endif
