#include "type.h"


namespace fx {

Ty Ty::convert_from_typename(std::string tname) {
    ID tid = ID::Invalid;
    auto itr = detail::TypeIDMappings.find(tname);
    if (itr != detail::TypeIDMappings.end()) {
        tid = itr->second;
    }
    return Ty(tid);
}

Ty::Ty(std::string tname) {
    ID tid = ID::Invalid;
    auto itr = detail::TypeIDMappings.find(tname);
    if (itr != detail::TypeIDMappings.end()) {
        tid = itr->second;
    }
    id = tid;
}

std::string Ty::type_name() {
    auto itr  = detail::TypeNameMappings.find(id);
    return itr != detail::TypeNameMappings.end() ? itr->second : "Nil";
}


}
