#ifndef SHIMMER_SHADER_READER_H
#define SHIMMER_SHADER_READER_H

#include "file_reader.h"

#include "glpp/program.h"
#include "glpp/shader.h"

#include <memory>

namespace shimmer
{
class shader_reader : file_reader
{
public:
    shader_reader( const std::vector<std::string>& paths );

    virtual ~shader_reader() = default;

    glpp::shader shader ( const std::string&      path,
                          enum glpp::shader::type type ) const;

    glpp::shader  fragment_shader ( const std::string& path ) const;

    glpp::shader  vertex_shader ( const std::string& path ) const;

    glpp::program program ( const std::string& vertex_path,
                            const std::string& fragment_path ) const;

    std::shared_ptr<glpp::program> shared_program (
        const std::string& vertex_path,
        const std::string& fragment_path ) const;
};

struct shader_read_exception : public std::runtime_error {
    shader_read_exception( const std::string& mesg )
        : std::runtime_error ( mesg ) {}
};

struct program_read_exception : public std::runtime_error {
    program_read_exception( const std::string& mesg )
        : std::runtime_error ( mesg ) {}
};
}

#endif // ifndef SHIMMER_SHADER_READER_H
