#include "env.h"

namespace common::env
{
std::string evar ( const std::string& evar, const std::string& defaultt ) {
    auto val = getenv ( evar.c_str() );

    return val ?  std::string ( val ) : defaultt;
}
}
