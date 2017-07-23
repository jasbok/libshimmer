#ifndef LIBSHIMMER_RENDERER_GLSL_GLSL_VARIABLE_H
#define LIBSHIMMER_RENDERER_GLSL_GLSL_VARIABLE_H

#include "accessor_macros.h"
#include "glsl_qualifier.h"
#include "glsl_type.h"
#include <ostream>
#include <string>

namespace shimmer
{
class glsl_variable
{
public:
    glsl_variable (
        glsl::qualifier qualifier,
        glsl::type type,
        unsigned int size,
        const std::string& name );

    glsl_variable ( const glsl_variable& copy );

    glsl_variable ( glsl_variable&& move );

    virtual ~glsl_variable() {}

    glsl_variable& operator = ( const glsl_variable& copy );

    glsl_variable& operator = ( glsl_variable&& move );

    friend std::ostream& operator<< (
        std::ostream& os,
        const glsl_variable& var )
    {
        os << "{ qualifier: \"" << glsl::str_from ( var._qualifier )
           << "\", type: \"" << glsl::str_from ( var._type )
           << "\", size: \"" << var._size
           << "\", name: \"" << var._name
           << "\" }";

        return os;
    }

private:
    GETTER ( glsl_variable, glsl::qualifier, qualifier );

    GETTER ( glsl_variable, glsl::type, type );

    GETTER ( glsl_variable, unsigned int, size );

    GETTER ( glsl_variable, std::string, name );
};
}

#endif
