#include "type.h"


namespace fx {

Ty Ty::from_typename(std::string tname) {
    ID tid = ID::Nil;
    auto itr = detail::BasicTypeIDMappings.find(tname);
    if (itr != detail::BasicTypeIDMappings.end()) {
        tid = itr->second;
    }
    return Ty(tid);
}

Ty::Ty(std::string tname) {
    auto itr = detail::BasicTypeIDMappings.find(tname);
    if (itr != detail::BasicTypeIDMappings.end()) {
        id = itr->second;
    } else {
        id = ID::Object;
        class_name = tname;
    }
}

std::string Ty::str() {
    auto itr  = detail::BasicTypeNameMappings.find(id);
    return itr != detail::BasicTypeNameMappings.end() ? itr->second : class_name;
}


}
