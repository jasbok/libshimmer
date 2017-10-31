#include "utils.h"

#include <fstream>
#include <iterator>

using namespace glpp;
using namespace std;

string utils::read_all ( const string& path ) {
    ifstream fstream ( path );

    return string (std::istreambuf_iterator<char>(fstream), {});
}

