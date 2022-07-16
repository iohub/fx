#ifndef FX_EXCEPTION_H
#define FX_EXCEPTION_H

#include <exception>
#include <string>

namespace fx {

class FxException : public std::exception {
private:
    std::string errMsg;
public:
    FxException(std::string msg) : errMsg(msg) {}
    const char* what() const throw() { return errMsg.c_str(); }
};

using ParseException = FxException;
using CodeGenException = FxException;
using TypeCheckException = FxException;






};










#endif
