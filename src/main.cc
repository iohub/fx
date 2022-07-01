#include <stdio.h>
#include <fstream>
#include <memory>

#include <fmt/core.h>
#include <CLI/CLI.hpp>

#include "util.h"
#include "astnode.h"
#include "parser.hh"
#include "typecheck.h"

using namespace fx;

extern FILE *yyin;
extern fx::AstNode* Program;

int parse(const char* fname) {
    FILE *fobj = fopen(fname, "r");
    if (!fobj) return -1;
    yyin = fobj;
    do {
        yyparse();
    } while (!feof(yyin));

    return 0;
}

fx::Logging::Level fx::Logging::level;

int main(int argc, const char *argv[]) {
    fx::Logging::level = fx::Logging::Level::INFO;

    CLI::App app{"fx compiler"};
    std::string fname;
    app.add_option("-f,--file", fname, "source file");
    CLI11_PARSE(app, argc, argv);

    if (int err = parse(fname.c_str()) != 0) {
        fmt::print("parse file:{}, err:{}\n", fname, err);
    } else {
        fmt::print("parsed ast:\n{}\n", Program->sexp());
        Program->print();
    }
    if (Program != nullptr) {
        Env emptyCtx;
        Decls *decls = dynamic_cast<Decls*>(Program);
        fx::TypeCheckResult result = fx::TypeChecker::check(emptyCtx, decls);
        fmt::print("TypeCheckResult {}\n", result.errmsg);
        delete Program;
    }
}

