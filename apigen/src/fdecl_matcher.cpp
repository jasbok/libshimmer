#include "fdecl_matcher.h"

#include "common.h"

#include "common/str.h"

#include "external/fmt/format.h"

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

fdecl_matcher::fdecl_matcher( std::vector<struct function_decl>& out )
    : _out ( out )
{}

void fdecl_matcher::run ( const match& match ) {
    const auto& decl = match.Nodes.getNodeAs<clang::FunctionDecl>( BINDING );

    if ( decl ) {
        struct function_decl func;

        auto ret = decl->getReturnType();
        func.ret.type = ret.getAsString();

        func.name = decl->getNameAsString();

        for ( unsigned int i = 0; i < decl->getNumParams(); i++ ) {
            auto parm_decl = decl->getParamDecl ( i );

            struct parameter_decl parm;
            parm.type.type = parm_decl->getOriginalType().getAsString();
            parm.name      = parm_decl->getNameAsString();

            if ( parm.name.empty() ) {
                parm.name = "parm_" + std::to_string ( i );
            }

            if ( common::str::contains ( parm.type.type,
                                         "\\(\\s*\\*\\s*\\)" ) ) {
                parm.type_name = common::str::replace ( parm.type.type,
                                                        "\\(\\s*\\*\\s*\\)",
                                                        "(*" + parm.name +
                                                        ")" );
            }
            else {
                parm.type_name = parm.type.type + " " + parm.name;
            }

            func.parameters.emplace_back ( parm );
        }

        _out.emplace_back ( func );
    }
}
}
