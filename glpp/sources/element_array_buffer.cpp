#include "element_array_buffer.h"

using namespace glpp;
using namespace std;

element_array_buffer& element_array_buffer::data ( const vector<GLuint>& vec )
{
    return _buffer::data<GLuint>( vec );
}

element_array_buffer& element_array_buffer::data ( const vector<GLuint>& vec,
                                                   enum usage            usage )
{
    return _buffer::data<GLuint>( vec, usage );
}
