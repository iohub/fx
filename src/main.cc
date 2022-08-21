#include <stdio.h>
#include <fstream>
#include <iostream>
#include <memory>

#include <fmt/core.h>
#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>

#include "exception.h"
#include "util.h"
#include "ast.h"
#include "typecheck.h"
#include "codegen.h"

#include "antlr4-runtime.h"
#include "fxLexer.h"
#include "fxParser.h"
#include "fxParserImpl.h"

using namespace fx;
using json = nlohmann::json;

Logging::Level Logging::level;

Decls* parse(const std::string &fname){
    std::ifstream ifs;
    ifs.open(fname);
    antlr4::ANTLRInputStream input(ifs);
    fxLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    fxParser parser(&tokens);
    antlr4::tree::ParseTree *top = parser.program();
    AstVisitor visitor;
    visitor.visit(top);
    ifs.close();
    return visitor.ast;
}

void compile(const std::string &fname) {
    AstNodePtr wrap(parse(fname));
    TypeChecker checker;

    TypeCheckResult result = checker.check(wrap);
    json jsonExp = wrap->tojson();
    wrap->print() ;
    fmt::print("typed ast (sexp):\n{}\n", wrap->dump());
    fmt::print("\ntyped ast (json):\n{}\n", jsonExp.dump());
    Logging::info("TypeCheckResult {}\n", result.errmsg);

    CodeGen gen(fname);
    try {
        gen.emit(wrap);
        // Logging::info("llvm ir:{}\n", gen.llvm_ir());
        gen.dump(fname + ".ll");
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
    parse(fname);
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

