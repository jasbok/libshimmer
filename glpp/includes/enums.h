#ifndef GLPP_ENUMS_H
#define GLPP_ENUMS_H

#include <GL/glew.h>
#include <iostream>

namespace glpp
{
enum class usage : GLenum {
    stream_draw  = GL_STREAM_DRAW,
    stream_read  = GL_STREAM_READ,
    stream_copy  = GL_STREAM_COPY,
    static_draw  = GL_STATIC_DRAW,
    static_read  = GL_STATIC_READ,
    static_copy  = GL_STATIC_COPY,
    dynamic_draw = GL_DYNAMIC_DRAW,
    dynamic_read = GL_DYNAMIC_READ,
    dynamic_copy = GL_DYNAMIC_COPY
};

enum class access : GLenum {
    read_only  = GL_READ_ONLY,
    write_only = GL_WRITE_ONLY,
    read_write = GL_READ_WRITE
};

constexpr size_t size_of ( GLenum type ) {
    switch ( type ) {
    case GL_BYTE:

        return sizeof(GLbyte);

    case GL_FIXED:

        return sizeof(GLfixed);

    case GL_FLOAT:

        return sizeof(GLfloat);

    case GL_SHORT:

        return sizeof(GLshort);

    case GL_UNSIGNED_BYTE:

        return sizeof(GLubyte);

    case GL_UNSIGNED_SHORT:

        return sizeof(GLushort);
    }

    return 0;
}

template<typename T>
constexpr bool is_gltype() {
    return false;
}

template<>
constexpr bool is_gltype<GLbyte>() {
    return true;
}

template<>
constexpr bool is_gltype<GLfixed>() {
    return true;
}

template<>
constexpr bool is_gltype<GLfloat>() {
    return true;
}

template<>
constexpr bool is_gltype<GLshort>() {
    return true;
}

template<>
constexpr bool is_gltype<GLubyte>() {
    return true;
}

template<>
constexpr bool is_gltype<GLushort>() {
    return true;
}

template<>
constexpr bool is_gltype<GLuint>() {
    return true;
}

template<typename T>
constexpr GLenum to_glenum() {
    static_assert ( is_gltype<T>(), "T is not a valid OpenGL type." );

    return 0;
}

template<>
constexpr GLenum to_glenum<GLbyte>() {
    return GL_BYTE;
}

template<>
constexpr GLenum to_glenum<GLfixed>() {
    return GL_FIXED;
}

template<>
constexpr GLenum to_glenum<GLfloat>() {
    return GL_FLOAT;
}

template<>
constexpr GLenum to_glenum<GLshort>() {
    return GL_SHORT;
}

template<>
constexpr GLenum to_glenum<GLubyte>() {
    return GL_UNSIGNED_BYTE;
}

template<>
constexpr GLenum to_glenum<GLushort>() {
    return GL_UNSIGNED_SHORT;
}

template<>
constexpr GLenum to_glenum<GLuint>() {
    return GL_UNSIGNED_INT;
}
}

#endif // ifndef GLPP_ENUMS_H
