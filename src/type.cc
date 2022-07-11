#include "type.h"


namespace fx {

Ty Ty::from_typename(std::string tname) {
    ID tid = ID::Nil;
    auto itr = detail::TypeIDMappings.find(tname);
    if (itr != detail::TypeIDMappings.end()) {
        tid = itr->second;
    }
    return Ty(tid);
}

Ty::Ty(std::string tname) {
    ID tid = ID::Nil;
    auto itr = detail::TypeIDMappings.find(tname);
    if (itr != detail::TypeIDMappings.end()) {
        tid = itr->second;
    }
    id = tid;
}

std::string Ty::str() {
    auto itr  = detail::TypeNameMappings.find(id);
    return itr != detail::TypeNameMappings.end() ? itr->second : "Nil";
}


}
