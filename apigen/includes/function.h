#ifndef APIGEN_FUNCTION_H
#define APIGEN_FUNCTION_H

#include "parameter.h"

namespace apigen
{
class function
{
public:
    function( const function& function ) = default;

    function( const clang::SourceManager& source_manager,
              const clang::FunctionDecl*  decl );

    virtual ~function() = default;

    friend std ::ostream& operator<<( std::ostream&   os,
                                      const function& function );

    std::string name() const;

    type        ret() const;

    std::string parameters_as_string (
        const std::string& delimiter = ", " ) const;

    std::vector<parameter> parameters() const;

private:
    std::string _name;

    class type _ret;

    std::vector<parameter> _parameters;
};
}

#endif // ifndef APIGEN_FUNCTION_H
