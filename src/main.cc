#include <stdio.h>
#include <fstream>
#include <iostream>
#include <memory>

#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>

#include "exception.h"
#include "util.h"
#include "astnode.h"
#include "parser.hh"
#include "typecheck.h"
#include "codegen.h"

using namespace fx;
using json = nlohmann::json;

extern FILE *yyin;
extern AstNode* Program;

int parse(const char* fname) {
    FILE *fobj = fopen(fname, "r");
    if (!fobj) return -1;
    yyin = fobj;
    do {
        yyparse();
    } while (!feof(yyin));

    return 0;
}

Logging::Level Logging::level;

int main(int argc, const char *argv[]) {
    Logging::level = Logging::Level::INFO;

    CLI::App app{"fx compiler"};
    std::string fname;
    app.add_option("-f,--file", fname, "source file");
    CLI11_PARSE(app, argc, argv);

    if (int err = parse(fname.c_str()) != 0) {
        fmt::print("parse file:{}, err:{}\n", fname, err);
    } else {
        json jsonExp = Program->tojson();
        // print pretty json
        // std::cout << std::setw(2) << jsonExp << std::endl;
        // visualize onsite: https://vanya.jp.net/vtree
        std::cout << jsonExp << std::endl;
    }

    if (Program) {
        AstNodePtr ptr(Program);
        TypeChecker checker;
        TypeCheckResult result = checker.check(ptr);
        fmt::print("typed ast:\n");
        ptr->print();
        fmt::print("TypeCheckResult {}\n", result.errmsg);
        CodeGen gen(fname);
        try {
            gen.emit(ptr);
            gen.print();
        } catch (CodeGenException *ex) {
            Logging::error("catch codegen exception {}", ex->what());
        }
    }
}

