#ifndef SHIMMER_GENERATOR_COMMON_H
#define SHIMMER_GENERATOR_COMMON_H

#include "clang/Tooling/Tooling.h"

#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

namespace apigen
{
const static clang::LangOptions LANG_OPTIONS;

std::string retrieve_source ( const clang::SourceManager& source_manager,
                              const clang::SourceRange&   source_range );
}

#endif // ifndef SHIMMER_GENERATOR_COMMON_H
