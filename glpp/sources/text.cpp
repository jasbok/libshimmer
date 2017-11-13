#include "text.h"

using namespace glpp;
using namespace std;

text::text( const string& content )
    : _content ( content ),
      _mesh()
{
    _update();
}

text::text( text&& move )
    : _content ( std::move ( move._content ) ),
      _mesh ( std::move ( move._mesh ) )
{}

text::~text() {}

text& text::operator=( text&& move )
{
    _content = std::move ( move._content );
    _mesh    = std::move ( move._mesh );

    return *this;
}

text& text::bind()
{
    _mesh.bind();

    return *this;
}

text& text::unbind()
{
    _mesh.unbind();

    return *this;
}

text& text::content ( const string& content )
{
    _content = content;

    return *this;
}

string text::content() const
{
    return _content;
}

text& text::draw()
{
    _mesh.draw<GL_TRIANGLE_STRIP>();

    return *this;
}

void text::_update()
{}
