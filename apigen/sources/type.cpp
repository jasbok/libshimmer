#include "type.h"

#include "common.h"

namespace apigen
{
type::type( const clang::QualType& ctype )
    : _str ( ctype.getAsString() )
{}

type::type( const clang::SourceManager&  source_manager,
            const clang::TypeSourceInfo* ctype )
    : _str ( retrieve_source ( source_manager,
              ctype->getTypeLoc().getSourceRange() ) )
{}

type::type( const clang::SourceManager& source_manager,
            const clang::SourceRange&   source_range )
    : _str ( retrieve_source ( source_manager, source_range ) )
{}

std::string type::str() const {
    return _str;
}

std::ostream& operator<<( std::ostream& os, const type& type ) {
    os << type._str;

    return os;
}
}
