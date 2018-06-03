#include "parameter.h"

#include <regex>

namespace apigen
{
parameter::parameter( const clang::SourceManager& source_manager,
                      const clang::ParmVarDecl*   param,
                      const std::string&          default_name )
    : _type ( source_manager, param->getTypeSourceInfo() ),
      _name ( param->getNameAsString().length() > 0
          ? param->getNameAsString()
          : default_name ),

      _declaration_str ( _compile_declaration_str (
              _type.str(), _name, param ) )
{}

std::ostream& operator<<( std::ostream&    os,
                          const parameter& param ) {
    os << param._declaration_str;

    return os;
}

class type parameter::type() const {
    return _type;
}

std::string parameter::name() const {
    return _name;
}

std::string parameter::source() const
{
    return _source;
}

std::string parameter::definition() const
{
    return _definition;
}

std::string parameter::declaration_str() const
{
    return _declaration_str;
}

std::string parameter::_compile_declaration_str (
    const std::string&        type,
    const std::string&        name,
    const clang::ParmVarDecl* param )
{
    const auto type_ptr = param->getType().getTypePtr();

    if ( type_ptr ) {
        if ( type_ptr->isFunctionPointerType() ) {
            const static std::regex regex_replace ( "\\(\\*\\)" );

            if ( std::regex_search ( type, regex_replace ) ) {
                std::regex_replace ( type, regex_replace, "(*" + name + ")" );
            }

            return type;
        }
        else if ( type_ptr->isFunctionType() ||
                  type_ptr->isFunctionNoProtoType() ||
                  type_ptr->isFunctionProtoType() ) {
            const static std::regex regex_replace ( "\\(\\)" );

            if ( std::regex_search ( type, regex_replace ) ) {
                std::regex_replace ( type, regex_replace, "(" + name + ")" );
            }

            return type;
        }
    }

    return type + " " + name;
}
}
