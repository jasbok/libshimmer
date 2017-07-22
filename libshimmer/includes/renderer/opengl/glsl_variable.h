#ifndef LIBSHIMMER_RENDERER_OPENGL_GLSL_VARIABLE_H
#define LIBSHIMMER_RENDERER_OPENGL_GLSL_VARIABLE_H

#include "accessor_macros.h"
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <unordered_map>

namespace shimmer
{
enum class glsl_qualifier
{
    UNKNOWN = 0, ATTRIBUTE, UNIFORM, VARYING
};

enum class glsl_type
{
    UNKNOWN = 0,
    BOOL, INT, UINT, FLOAT, DOUBLE,
    BVEC2, BVEC3, BVEC4,
    IVEC2, IVEC3, IVEC4,
    UVEC2, UVEC3, UVEC4,
    VEC2,  VEC3,  VEC4,
    DVEC2, DVEC3, DVEC4,
    SAMPLER1D, ISAMPLER1D, USAMPLER1D,
    SAMPLER2D, ISAMPLER2D, USAMPLER2D,
    SAMPLER3D, ISAMPLER3D, USAMPLER3D,
    MAT2, MAT3, MAT4,
    MAT2X3, MAT3X2,
    MAT2X4, MAT4X2,
    MAT3X4, MAT4X3
};

class glsl_variable
{
public:
    glsl_variable();

    glsl_variable (
        enum glsl_qualifier qualifier,
        enum glsl_type type,
        const std::string& name );

    glsl_variable (
        enum glsl_qualifier qualifier,
        enum glsl_type type,
        unsigned int size,
        const std::string& name );

    virtual ~glsl_variable() {}

    static glsl_qualifier qualifier_from ( const std::string& str );

    static glsl_type type_from ( const std::string& str );

    static std::string str_from ( glsl_qualifier qualifier );

    static std::string str_from ( glsl_type type );

    friend std::ostream& operator<< (
        std::ostream& os,
        const glsl_variable& var )
    {
        os << "{ qualifier: \"" << str_from ( var._qualifier )
           << "\", type: \"" << str_from ( var._type )
           << "\", size: \"" << var._size
           << "\", name: \"" << var._name
           << "\", location: \"" << var._location << "\" }";

        return os;
    }

private:
    FLUENT ( glsl_variable, glsl_qualifier, qualifier );

    FLUENT ( glsl_variable, glsl_type, type );

    FLUENT ( glsl_variable, unsigned int, size );

    FLUENT ( glsl_variable, std::string, name );

    FLUENT ( glsl_variable, GLint, location );

    static const std::unordered_map<std::string, glsl_type> _type_from_str_map;
};
}

#endif
