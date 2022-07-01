#include <stdio.h>
#include <fstream>
#include <memory>

#include <fmt/core.h>
#include <CLI/CLI.hpp>

#include "astnode.h"
#include "parser.hh"
#include "typecheck.h"

extern FILE *yyin;
extern fx::AstNode* Program;

int parse(const char* fname) {
    FILE *fobj = fopen(fname, "r");
    if (!fobj) {
        return -1;
    }
    yyin = fobj;
    do {
        yyparse();
    } while (!feof(yyin));
    return 0;
}


int main(int argc, const char *argv[]) {

    CLI::App app{"fx compiler"};
    std::string fname;
    app.add_option("-f,--file", fname, "source file");
    CLI11_PARSE(app, argc, argv);

    fx::TypeChecker ck;
    fx::Ty ty(fx::TypeID(100));

    if (int err = parse(fname.c_str()) != 0) {
        fmt::print("parse file:{}, err:{}\n", fname, err);
    } else {
        fmt::print("parsed ast:\n{}\n", Program->str());
        Program->print();
    }
    if (Program != nullptr) delete Program;
}

