#include "common.h"

#include <regex>

namespace apigen
{
std::string retrieve_source ( const clang::SourceManager& source_manager,
                              const clang::SourceRange&   source_range ) {
    using namespace clang;

    auto source_begin = source_range.getBegin();
    auto source_end   = source_range.getEnd();

    // Adjust end to the end of the last token.
    source_end = Lexer::getLocForEndOfToken ( source_end,
                                              0,
                                              source_manager,
                                              LANG_OPTIONS );

    return { source_manager.getCharacterData ( source_begin ),
             source_manager.getCharacterData ( source_end ) };
}
}
