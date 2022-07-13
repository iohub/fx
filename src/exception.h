#ifndef FX_EXCEPTION_H
#define FX_EXCEPTION_H

#include <exception>
#include <string>

namespace fx {

class CodeGenException : public std::exception {
private:
    std::string errMsg;
public:
    CodeGenException(std::string msg) : errMsg(msg) {}
    const char* what() const throw() { return errMsg.c_str(); }
};







};










#endif
