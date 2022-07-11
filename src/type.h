
#ifndef FXTYPE_H_
#define FXTYPE_H_

#include <stdint.h>
#include <string>
#include <map>

namespace fx {

struct Ty {
    enum class ID: uint32_t {
        Nil,
        Int, Float, Bool, Str, Void,
        Arrow,
        Object,
        UnResolved,
    };
    ID id = ID::Nil;

    Ty(ID k): id(k) {}
    Ty(): id(ID::Nil) {}
    Ty(std::string tname);
    std::string str();

    bool operator==(const Ty& b) { return id == b.id; }
    bool operator==(const ID tid) { return id == tid; }
    bool operator!=(const Ty& b) { return id != b.id; }
    Ty operator=(const ID TypeID) { return Ty(TypeID); }
    bool unresolved() const { return id == ID::UnResolved; }
    bool nil() const { return id == ID::Nil; }
    bool is(ID tid) const { return tid == id; }
    static Ty from_typename(std::string tname);
};

typedef Ty::ID TypeID;

namespace detail {
    const static std::map<std::string, TypeID> TypeIDMappings = {
        {"int", TypeID::Int},
        {"str", TypeID::Str},
        {"bool", TypeID::Bool},
        {"void", TypeID::Void},
        {"float", TypeID::Float},
    };
    const static std::map<TypeID, std::string> TypeNameMappings = {
        {TypeID::Int, "int"},
        {TypeID::Str, "str"},
        {TypeID::Bool, "bool"},
        {TypeID::Float, "float"},
        {TypeID::Void, "void"},
    };
};


}; // namespace fx



#endif
