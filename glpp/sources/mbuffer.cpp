#include "mbuffer.h"

using namespace glpp;
using namespace std;

mbuffer::mbuffer( enum target target )
    : buffer ( static_cast<enum buffer::target>(target) )
{}

mbuffer::mbuffer( mbuffer&& move )
    : buffer ( std::move ( move ) )
{}

mbuffer::~mbuffer() {}

mbuffer& mbuffer::operator=( mbuffer&& move ) {
         buffer::operator=( std::move( move ) );

    return *this;
}

buffer_data mbuffer::map ( enum access access ) {
    auto ptr = glMapBuffer ( static_cast<GLenum>(target()),
                         static_cast<GLenum>(access) );

    return buffer_data{ptr, size()};
}

bool mbuffer::unmap() {
    return glUnmapBuffer ( static_cast<GLenum>(target()) );
}
