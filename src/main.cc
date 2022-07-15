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
Logging::Level Logging::level;


void compile(const std::string &fname) {
    FILE *fobj = fopen(fname.c_str(), "r");
    if (!fobj) {
        throw new ParseException(fmt::format("open {} err", fname));
    }
    yyin = fobj;
    do { yyparse(); } while (!feof(yyin));
    if (!Program) {
        throw new ParseException(fmt::format("parse {} err", fname));
    }
    AstNodePtr ptr(Program);
    TypeChecker checker;

    TypeCheckResult result = checker.check(ptr);
    json jsonExp = Program->tojson();
    Logging::info("typed ast (json format):\n{}\n", jsonExp.dump());
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


int main(int argc, const char *argv[]) {
    Logging::level = Logging::Level::INFO;

    CLI::App app{"fx compiler"};
    std::string fname;
    app.add_option("-f,--file", fname, "source file");
    CLI11_PARSE(app, argc, argv);

    // print pretty json
    // std::cout << std::setw(2) << jsonExp << std::endl;
    // visualize onsite: https://vanya.jp.net/vtree
    try {
        compile(fname);
    } catch (ParseException *ex) {
        Logging::error("catch parse exception {}", ex->what());
    }

    return 0;
}

