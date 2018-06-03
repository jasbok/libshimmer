#include "function.h"

#include "common.h"

namespace apigen
{
function::function( const clang::SourceManager& source_manager,
                    const clang::FunctionDecl*  decl )
    : _name ( decl->getNameAsString() ),
      _ret ( decl->getReturnType() ),
      _parameters()
{
    for ( unsigned int i = 0; i < decl->getNumParams(); i++ ) {
        parameter param (
            source_manager,
            decl->getParamDecl ( i ),
            "param" + std::to_string ( i ) );

        _parameters.push_back ( param );
    }
}

std::ostream& operator<<( std::ostream&   os,
                          const function& function ) {
    os << function._ret << " " << function._name << "( ";

    for ( unsigned int i = 0; i < function._parameters.size(); i++ ) {
        os << function._parameters[i];

        if ( i < function._parameters.size() - 1 ) os << ",";

        os << " ";
    }

    os << ")";

    return os;
}

std::string function::name() const {
    return _name;
}

type function::ret() const {
    return _ret;
}

std::string function::parameters_as_string ( const std::string& delimiter )
const {
    std::string params = "";

    for ( unsigned int i = 0; i < _parameters.size(); i++ ) {
        params += _parameters[i].declaration_str();

        if ( i < _parameters.size() - 1 ) params += delimiter;
    }

    return params;
}

std::vector<parameter> function::parameters() const {
    return _parameters;
}
}
