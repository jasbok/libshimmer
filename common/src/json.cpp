#include "json.h"

#include "str.h"

#include <sstream>

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

std::string to_json ( const std::vector<std::string>& vec ) {
    std::stringstream ss;

    ss << "[";

    if ( vec.size() > 0 ) {
        for ( unsigned int i = 0; i < vec.size() - 1; i++ ) {
            ss << "\"" << vec[i] << "\",";
        }
        ss << "\"" << vec[vec.size() - 1] << "\"";
    }

    ss << "]";

    return ss.str();
}

std::string to_json ( const std::string& str ) {
    return "\"" + str + "\"";
}

std::string to_json ( bool val ) {
    return val ? "true" : "false";
}

std::string as_string ( const nlohmann::json& json )  {
    using namespace nlohmann::detail;

    switch ( json.type() ) {
    case  value_t::number_float:

        return std::to_string ( json.get<float>() );

    case  value_t::number_integer:
    case  value_t::number_unsigned:

        return std::to_string ( json.get<int>() );

    case  value_t::string:

        return json.get<std::string>();

    case  value_t::boolean:

        return std::to_string ( json.get<bool>() );

    case value_t::array:
        throw could_not_parse_exception ( "array", "string" );

    case value_t::discarded:
        throw could_not_parse_exception ( "discarded", "string" );

    case value_t::null:
        throw could_not_parse_exception ( "null", "string" );

    case value_t::object:
        throw could_not_parse_exception ( "object", "string" );
    }

    throw could_not_parse_exception ( "unknown", "string" );
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

// std::vector<std::string> as_string_vector ( const nlohmann::json&
//           obj,
//                                            const std::vector<std::string>&
// path )
// {
//    auto field = _find ( obj, path );

//    if ( field->is_array() ) {
//        std::vector<std::string> strings;

//        for ( const auto& item : field->items() ) {
//            strings.push_back ( as_string ( item ) );
//        }

//        return strings;
//    }

//    throw could_not_parse_exception ( path, "array" );
// }

std::unordered_map<std::string, std::string> as_properties (
    const nlohmann::json& obj ) {
    std::unordered_map<std::string, std::string> properties;

    auto flat = obj.flatten();

    for ( auto& prop : flat.items() ) {
        std::string key =
            common::str::replace ( prop.key().substr ( 1, prop.key().length() ),
                                   "/",
                                   "." );

        std::string value = as_string ( prop.value() );

        properties.insert ( { key, value } );
    }

    return properties;
}

bool exists ( const nlohmann::json&           obj,
              const std::vector<std::string>& path ) {
    try {
        _find ( obj, path );

        return true;
    }
    catch ( const std::exception& ) {}

    return false;
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
    const std::string& type,
    const std::string& expected )
    : runtime_error ( "Could not parse" + type + " as a " + expected + "." )
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
