#include "json.h"

#include "str.h"

namespace common::json
{
auto _find ( const nlohmann::json&           obj,
             const std::vector<std::string>& path ) {
    auto json = &obj;

    try {
        for ( const auto& seg : path ) {
            if ( json && json->is_object() ) {
                json = &( *json ).at ( seg );
            }
            else if ( json && json->is_array() ) {
                json = &( *json ).at ( std::stoul ( seg ) );
            }
            else {
                throw field_absent_exception ( path );
            }
        }
    }
    catch ( const field_absent_exception& ex1 ) {
        throw ex1;
    }
    catch ( const std::exception& ex2 ) {
        throw field_absent_exception ( path, ex2.what() );
    }
    return json;
}

std::string as_string ( const nlohmann::json&           obj,
                        const std::vector<std::string>& path ) {
    auto json = _find ( obj, path );

    using namespace nlohmann::detail;

    try {
        switch ( json->type() ) {
        case  value_t::number_float:

            return std::to_string ( json->get<float>() );

        case  value_t::number_integer:
        case  value_t::number_unsigned:

            return std::to_string ( json->get<int>() );

        case  value_t::string:

            return json->get<std::string>();

        case  value_t::boolean:

            return std::to_string ( json->get<bool>() );

        default:
            throw could_not_parse_exception ( path, "string" );
        }
    }
    catch ( const could_not_parse_exception& ex1 ) {
        throw ex1;
    }
    catch ( const std::exception& ex2 ) {
        throw could_not_parse_exception ( path, "string", ex2.what() );
    }
}

field_absent_exception::field_absent_exception(
    const std::vector<std::string>& path )
    : runtime_error ( "JSON field absent: " + str::join ( path, "." ) )
{}

field_absent_exception::field_absent_exception(
    const std::vector<std::string>& path,
    const std::string&              inner )
    : runtime_error ( "JSON field absent: " + str::join ( path, "." )
          + "\n" + inner )
{}

could_not_parse_exception::could_not_parse_exception(
    const std::vector<std::string>& path,
    const std::string&              type )
    : runtime_error ( "Could not parse field as a " + type
          + ": " + str::join ( path, "." ) )
{}

could_not_parse_exception::could_not_parse_exception(
    const std::vector<std::string>& path,
    const std::string&              type,
    const std::string&              inner )
    : runtime_error ( "Could not parse field as a " + type
          + ": " + str::join ( path, "." )
          + "\n" + inner )
{}
}
