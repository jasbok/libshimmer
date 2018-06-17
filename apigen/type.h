#ifndef APIGEN_TYPE_H
#define APIGEN_TYPE_H

#include "clang/Tooling/Tooling.h"

#include <string>

namespace apigen
{
class type
{
public:
    type( const type& type ) = default;

    type( const clang::QualType& ctype );

    type( const clang::SourceManager&  source_manager,
          const clang::TypeSourceInfo* ctype );

    type( const clang::SourceManager& source_manager,
          const clang::SourceRange&   source_range );

    virtual ~type() = default;

    friend std ::ostream& operator<<( std::ostream& os,
                                      const type&   type );

    std::string str() const;

private:
    std::string _str;
};
}

#endif // ifndef APIGEN_TYPE_H
