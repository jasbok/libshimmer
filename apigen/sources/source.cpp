#include "source.h"

#include "fmt/format.h"
#include "fmt/ostream.h"

namespace apigen
{
source::source( const std::string& header, std::ostream& destination )
    : _header ( header ),
      _destination ( destination )
{
    _include_header();
}

source::~source() {}

source& source::write ( const function& function ) {
    _destination << function << "{\n"
                 << "TRACE();\n"
                 << "return sym::" << function.name() << "(";

    for ( unsigned int i = 0; i < function.parameters().size(); i++ ) {
        _destination << function.parameters()[i].name();

        if ( i < function.parameters().size() - 1 ) _destination << ", ";
    }

    _destination << ");\n"
                 << "}\n\n";

    return *this;
}

source& source::operator<<( const function& function ) {
    write ( function );

    return *this;
}

void source::_include_header() {
    const static char* header =
        R"(#include {0}
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

#define TRACE()                                                           \
    using namespace std::chrono;                                          \
    static unsigned int _COUNTER           = 0;                           \
    static steady_clock::time_point _START = steady_clock::now();         \
    static bool  _FIRST_CALL               = true;                        \
    static float _INTERVAL                 = 1.0f;                        \
                                                                          \
    auto _DURATION = duration_cast<duration<float>>(                      \
        steady_clock::now() - _START );                                   \
                                                                          \
    _COUNTER++;                                                           \
                                                                          \
    if ( _FIRST_CALL ) {{                                                 \
        std::cout << "[[ " << __FUNCTION__ << " ]]" << std::endl;         \
        _FIRST_CALL = false;                                              \
    }}                                                                    \
    else if ( _DURATION.count() > _INTERVAL ) {{                          \
        std::cout << _COUNTER << "x " << __FUNCTION__                     \
                  << "[" << std::setprecision ( 2 )                       \
                  <<  _COUNTER / _DURATION.count()                        \
                  << "/sec]" << std::endl;                                \
                                                                          \
                                                                          \
        _COUNTER   = 0;                                                   \
        _INTERVAL *= 2;                                                   \
        _START     = steady_clock::now();                                 \
    }}

)";

    _destination << fmt::format ( header, _header.filename() );
}
}
