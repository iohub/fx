
#ifndef FXENV_H
#define FXENV_H

#include <stack>
#include "type.h"
#include "ast.h"

namespace fx {

template<class T>
class Scope {
public:
    Scope() { scope_.push_back(std::map<std::string, T>()); }

    void enter() { scope_.push_back(std::map<std::string, T>()); }
    void leave() { scope_.pop_back(); }

    T lookup(std::string const &k) {
        if (scope_.size() == 0) return T();
        for (int i = scope_.size()-1; i >= 0; i--){
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

template<class V, class F>
class Env {
public:
    V lookup_var(std::string const &nominal) {
        return vars_.lookup(nominal);
    }
    F lookup_func(std::string const &nominal) {
        return funs_.lookup(nominal);
    }
    void put_var(const std::string &varname, V value) {
        vars_.put(varname, value);
    }
    void put_func(const std::string &fnname, F value) {
        funs_.put(fnname, value);
    }
    void enter() {
        vars_.enter(); funs_.enter();
    }
    void leave() {
        vars_.leave(); funs_.leave();
    }
private:
    Scope<V> vars_;
    Scope<F> funs_;
};





};

#endif
