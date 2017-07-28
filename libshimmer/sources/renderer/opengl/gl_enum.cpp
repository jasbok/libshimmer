#include "gl_enum.h"

#include <unordered_map>

using namespace shimmer;

/* *INDENT-OFF* */
const std::unordered_map<GLenum, std::string> enum_string_map = {
//
// GL Pixel Format
//
    { GL_RED,                         "GL_RED"              },
    { GL_RG,                          "GL_RG"               },
    { GL_RGB,                         "GL_RGB"              },
    { GL_BGR,                         "GL_BGR"              },
    { GL_RGBA,                        "GL_RGBA"             },
    { GL_BGRA,                        "GL_BGRA"             },
    { GL_RED_INTEGER,                 "GL_RED_INTEGER"      },
    { GL_RG_INTEGER,                  "GL_RG_INTEGER"       },
    { GL_RGB_INTEGER,                 "GL_RGB_INTEGER"      },
    { GL_BGR_INTEGER,                 "GL_BGR_INTEGER"      },
    { GL_RGBA_INTEGER,                "GL_RGBA_INTEGER"     },
    { GL_BGRA_INTEGER,                "GL_BGRA_INTEGER"     },
    { GL_STENCIL_INDEX,               "GL_STENCIL_INDEX"    },
    { GL_DEPTH_COMPONENT,             "GL_DEPTH_COMPONENT"  },
    { GL_DEPTH_STENCIL,               "GL_DEPTH_STENCIL"    },

//
// GL Pixel Type
//
    { GL_UNSIGNED_BYTE,               "GL_UNSIGNED_BYTE"                },
    { GL_BYTE,                        "GL_BYTE"                         },
    { GL_UNSIGNED_SHORT,              "GL_UNSIGNED_SHORT"               },
    { GL_SHORT,                       "GL_SHORT"                        },
    { GL_UNSIGNED_INT,                "GL_UNSIGNED_INT"                 },
    { GL_INT,                         "GL_INT"                          },
    { GL_FLOAT,                       "GL_FLOAT"                        },
    { GL_UNSIGNED_BYTE_3_3_2,         "GL_UNSIGNED_BYTE_3_3_2"          },
    { GL_UNSIGNED_BYTE_2_3_3_REV,     "GL_UNSIGNED_BYTE_2_3_3_REV"      },
    { GL_UNSIGNED_SHORT_5_6_5,        "GL_UNSIGNED_SHORT_5_6_5"         },
    { GL_UNSIGNED_SHORT_5_6_5_REV,    "GL_UNSIGNED_SHORT_5_6_5_REV"     },
    { GL_UNSIGNED_SHORT_4_4_4_4,      "GL_UNSIGNED_SHORT_4_4_4_4"       },
    { GL_UNSIGNED_SHORT_4_4_4_4_REV,  "GL_UNSIGNED_SHORT_4_4_4_4_REV"   },
    { GL_UNSIGNED_SHORT_5_5_5_1,      "GL_UNSIGNED_SHORT_5_5_5_1"       },
    { GL_UNSIGNED_SHORT_1_5_5_5_REV,  "GL_UNSIGNED_SHORT_1_5_5_5_REV"   },
    { GL_UNSIGNED_INT_8_8_8_8,        "GL_UNSIGNED_INT_8_8_8_8"         },
    { GL_UNSIGNED_INT_8_8_8_8_REV,    "GL_UNSIGNED_INT_8_8_8_8_REV"     },
    { GL_UNSIGNED_INT_10_10_10_2,     "GL_UNSIGNED_INT_10_10_10_2"      },
    { GL_UNSIGNED_INT_2_10_10_10_REV, "GL_UNSIGNED_INT_2_10_10_10_REV"  },

};

/* *INDENT-ON* */

std::string opengl::enum_to_string ( GLenum gl_enum )
{
    auto enum_string = enum_string_map.find ( gl_enum );

    return enum_string != enum_string_map.end()
           ? enum_string->second
           : "UNKNOWN";
}
