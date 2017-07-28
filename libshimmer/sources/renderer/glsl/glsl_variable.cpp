#include "glsl_variable.h"

#include "spdlog/spdlog.h"

using namespace std;
using namespace shimmer;

glsl_variable::glsl_variable(
    glsl::qualifier qualifier,
    glsl::type      type,
    unsigned int    size,
    const string&   name )
    : _qualifier ( qualifier ),
      _type ( type ),
      _size ( size ),
      _name ( name )
{}

glsl_variable::glsl_variable( const glsl_variable& copy )
    : _qualifier ( copy._qualifier ),
      _type ( copy._type ),
      _size ( copy._size ),
      _name ( copy._name )
{}

glsl_variable::glsl_variable( glsl_variable&& move )
    : _qualifier ( move._qualifier ),
      _type ( move._type ),
      _size ( move._size ),
      _name ( std::move ( move._name ) )
{}

glsl_variable& glsl_variable::operator=( const glsl_variable& copy )
{
    _qualifier = copy._qualifier;
    _type      = copy._type;
    _size      = copy._size;
    _name      = copy._name;

    return *this;
}

glsl_variable& glsl_variable::operator=( glsl_variable&& move )
{
    _qualifier = move._qualifier;
    _type      = move._type;
    _size      = move._size;
    _name      = std::move ( move._name );

    return *this;
}
