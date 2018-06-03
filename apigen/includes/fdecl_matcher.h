#ifndef SHIMMER_GENERATOR_FDECL_MATCHER_H
#define SHIMMER_GENERATOR_FDECL_MATCHER_H

#include "function.h"
#include "output.h"

#include "clang/ASTMatchers/ASTMatchFinder.h"

namespace apigen
{
class fdecl_matcher : public clang::ast_matchers::MatchFinder::MatchCallback
{
    typedef clang::ast_matchers::MatchFinder::MatchResult match;

public:
    const static char* BINDING;

    const static clang::ast_matchers::DeclarationMatcher MATCHER;

    fdecl_matcher( std::vector<function>& out );

    virtual ~fdecl_matcher() = default;

    virtual void run ( const match& match );

private:
    std::vector<function>& _out;
};
}

#endif // ifndef SHIMMER_GENERATOR_FDECL_MATCHER_H
