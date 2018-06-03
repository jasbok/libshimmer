#include "fdecl_matcher.h"

#include "common.h"

#include <iostream>
#include <vector>

namespace apigen
{
using namespace clang::ast_matchers;

const char* fdecl_matcher::BINDING = "fdecl";

const DeclarationMatcher fdecl_matcher::MATCHER =
    functionDecl ( allOf ( isExternC(),
                           hasAttr ( clang::attr::Kind::Visibility ) ) )
        .bind ( fdecl_matcher::BINDING );

fdecl_matcher::fdecl_matcher( std::vector<function>& out )
    : _out ( out )
{}

void fdecl_matcher::run ( const match& match ) {
    const auto& decl = match.Nodes.getNodeAs<clang::FunctionDecl>( BINDING );

    if ( decl ) {
        _out.push_back ( { match.Context->getSourceManager(), decl } );

        // decl->dump();
    }
}
}
