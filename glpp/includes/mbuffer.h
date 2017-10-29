// #ifndef GLPP_MBUFFER_H
// #define GLPP_MBUFFER_H
//
// #include "buffer.h"
//
// namespace glpp
// {
// template<GLenum TARGET>
// class mbuffer : public buffer<TARGET, mbuffer>
// {
//     static_assert (
//         TARGET == GL_ARRAY_BUFFER
//         || TARGET == GL_ELEMENT_ARRAY_BUFFER
//         || TARGET == GL_PIXEL_PACK_BUFFER
//         || TARGET == GL_PIXEL_UNPACK_BUFFER,
//         "Unsupported TARGET for mbuffer.");
//
// public:
//     mbuffer() : buffer<TARGET>() {}
//
//     mbuffer( mbuffer&& move )
//         : buffer<TARGET>( std::move ( move ) )
//     {}
//
//     ~mbuffer() {}
//
//     mbuffer& operator=( mbuffer&& move ) {
//         buffer<TARGET>::operator=( std::move (
//                                        move ) );
//
//         return *this;
//     }
//
//     buffer_data map ( enum access access ) {
//         auto ptr = glMapBuffer ( static_cast<GLenum>(TARGET),
//                                  static_cast<GLenum>(access) );
//
//         return buffer_data{ptr,
//                            buffer<TARGET>::size() };
//     }
//
//     bool unmap() {
//         return glUnmapBuffer ( static_cast<GLenum>(TARGET) );
//     }
// };
// }
//
// #endif // ifndef GLPP_MBUFFER_H
