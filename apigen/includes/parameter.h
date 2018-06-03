#ifndef APIGEN_PARAMETER_H
#define APIGEN_PARAMETER_H

#include "type.h"

namespace apigen
{
class parameter
{
public:
    parameter( const parameter& param ) = default;

    parameter( const clang::SourceManager& source_manager,
               const clang::ParmVarDecl*   param,
               const std::string&          default_name );

    virtual ~parameter() = default;

    friend std ::ostream& operator<<( std::ostream&    os,
                                      const parameter& param );

    class type  type() const;

    std::string name() const;

    std::string source() const;

    std::string definition() const;

    std::string declaration_str() const;

private:
    class type _type;

    std::string _name;

    std::string _source;

    std::string _definition;

    std::string _declaration_str;

    std::string _compile_declaration_str ( const std::string&        type,
                                           const std::string&        name,
                                           const clang::ParmVarDecl* param );
};
}

#endif // ifndef APIGEN_PARAMETER_H
