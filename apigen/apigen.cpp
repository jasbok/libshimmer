#include "fdecl_matcher.h"
#include "output.h"

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"

#include <experimental/filesystem>
#include <iostream>
#include <string>

using namespace apigen;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace clang;
using namespace llvm::cl;
using namespace llvm;

static OptionCategory options_category ( "shim generator options" );

static llvm::cl::opt<std::string> out_dir (
    "o",
    desc ( "Specify the output directory." ),
    value_desc ( "path" ),
    cl::cat ( options_category ) );

static llvm::cl::opt<std::string> header_dest (
    "header",
    desc ( "Specify the output header file." ),
    value_desc ( "path" ),
    cl::cat ( options_category ) );

static llvm::cl::opt<std::string> source_dest (
    "source",
    desc ( "Specify the output source file." ),
    value_desc ( "path" ),
    cl::cat ( options_category ) );


int main ( int argc, const char** argv ) {
    CommonOptionsParser args_parser ( argc, argv, options_category );

    std::string in = args_parser.getSourcePathList()[0];
    printf ( "Generating API headers and tracers for: %s\n", in.c_str() );

    class output out ( in, header_dest.getValue(), source_dest.getValue() );

    std::vector<function> functions;
    functions.reserve ( 256 );

    fdecl_matcher matcher ( functions );

    MatchFinder finder;
    finder.addMatcher ( fdecl_matcher::MATCHER, &matcher );

    ClangTool tool (
        args_parser.getCompilations(),
        args_parser.getSourcePathList() );

    tool.run ( newFrontendActionFactory ( &finder ).get() );

    for ( const auto& func : functions ) out << func;

    return 0;
}
