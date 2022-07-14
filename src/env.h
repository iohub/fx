
#ifndef FXENV_H
#define FXENV_H

#include <stack>
#include "type.h"
#include "astnode.h"

namespace fx {

template<class T>
class Scope {
public:
    Scope() { scope_.push_back(std::map<std::string, T>()); }

    void enter() { scope_.push_back(std::map<std::string, T>()); }
    void leave() { scope_.pop_back(); }

    T lookup(std::string const &k) {
        if (scope_.size() == 0) return T();
        for (size_t i = scope_.size()-1; i >= 0; i--){
            std::map<std::string, T> &current = scope_[i];
            if (current.find(k) != current.end()) {
                return current[k];
            }
        }
        return T();
    }

    void put(std::string k, T v) {
        if (scope_.size() == 0) { enter(); }
        std::map<std::string, T> &current = scope_.back();
        current[k] = v;
    }

private:
    std::vector<std::map<std::string, T> > scope_;
};





};

#endif
