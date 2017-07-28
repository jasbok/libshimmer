#include "gl_pixel.h"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

using namespace shimmer;
using namespace std;

/* *INDENT-OFF* */
TEST_CASE ( "Check if bytes per pixel is correctly calculated from the "
            "pixel format and type GLenums.",
            "[gl_pixel]" )
{
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_BYTE               ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_BYTE                        ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT              ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_SHORT                       ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_INT                ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_INT                         ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_FLOAT                       ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_BYTE_3_3_2         ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_5_6_5        ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_4_4_4_4      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_5_5_5_1      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_INT_8_8_8_8        ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_INT_10_10_10_2     ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED, GL_UNSIGNED_INT_2_10_10_10_REV ) == 1*4);

    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_BYTE               ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_BYTE                        ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT              ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_SHORT                       ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_INT                ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_INT                         ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_FLOAT                       ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_BYTE_3_3_2         ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_5_6_5        ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_4_4_4_4      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_5_5_5_1      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_INT_8_8_8_8        ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_INT_10_10_10_2     ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG, GL_UNSIGNED_INT_2_10_10_10_REV ) == 2*4);

    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_BYTE               ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_BYTE                        ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT              ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_SHORT                       ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_INT                ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_INT                         ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_FLOAT                       ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_BYTE_3_3_2         ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_5_6_5        ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_5_5_5_1      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_INT_8_8_8_8        ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_INT_10_10_10_2     ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB, GL_UNSIGNED_INT_2_10_10_10_REV ) == 3*4);

    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_BYTE               ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_BYTE                        ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT              ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_SHORT                       ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_INT                ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_INT                         ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_FLOAT                       ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_BYTE_3_3_2         ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_5_6_5        ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_4_4_4_4      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_5_5_5_1      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_INT_8_8_8_8        ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_INT_10_10_10_2     ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR, GL_UNSIGNED_INT_2_10_10_10_REV ) == 3*4);

    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_BYTE               ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_BYTE                        ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT              ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_SHORT                       ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_INT                ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_INT                         ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_FLOAT                       ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_BYTE_3_3_2         ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_5_6_5        ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_5_5_5_1      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_INT_8_8_8_8        ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_INT_10_10_10_2     ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA, GL_UNSIGNED_INT_2_10_10_10_REV ) == 4*4);

    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_BYTE               ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_BYTE                        ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT              ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_SHORT                       ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_INT                ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_INT                         ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_FLOAT                       ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_BYTE_3_3_2         ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_5_6_5        ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_4_4_4_4      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_5_5_5_1      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_INT_8_8_8_8        ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_INT_10_10_10_2     ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA, GL_UNSIGNED_INT_2_10_10_10_REV ) == 4*4);

    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_BYTE               ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_BYTE                        ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT              ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_SHORT                       ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_INT                ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_INT                         ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_FLOAT                       ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 1*4);

    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_BYTE               ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_BYTE                        ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT              ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_SHORT                       ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_INT                ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_INT                         ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_FLOAT                       ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 2*4);

    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_BYTE               ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_BYTE                        ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT              ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_SHORT                       ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_INT                ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_INT                         ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_FLOAT                       ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 3*4);

    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_BYTE               ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_BYTE                        ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT              ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_SHORT                       ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_INT                ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_INT                         ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_FLOAT                       ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 3*1);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 3*2);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 3*4);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 3*4);

    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_BYTE               ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_BYTE                        ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT              ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_SHORT                       ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_INT                ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_INT                         ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_FLOAT                       ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 4*4);

    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_BYTE               ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_BYTE                        ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT              ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_SHORT                       ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_INT                ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_INT                         ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_FLOAT                       ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_BYTE_3_3_2         ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 4*1);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_5_6_5        ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_5_5_5_1      ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 4*2);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_INT_8_8_8_8        ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_INT_10_10_10_2     ) == 4*4);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER, GL_UNSIGNED_INT_2_10_10_10_REV ) == 4*4);

    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_BYTE               ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_BYTE                        ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT              ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_SHORT                       ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_INT                ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_INT                         ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_FLOAT                       ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_BYTE_3_3_2         ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_5_6_5        ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_4_4_4_4      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_5_5_5_1      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_INT_8_8_8_8        ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_INT_10_10_10_2     ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX, GL_UNSIGNED_INT_2_10_10_10_REV ) == 1*4);

    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE               ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_BYTE                        ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT              ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_SHORT                       ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_INT                ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_INT                         ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_FLOAT                       ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE_3_3_2         ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 1*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_5_6_5        ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_4_4_4_4      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_5_5_5_1      ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 1*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_INT_8_8_8_8        ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_INT_10_10_10_2     ) == 1*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT, GL_UNSIGNED_INT_2_10_10_10_REV ) == 1*4);

    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_BYTE               ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_BYTE                        ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT              ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_SHORT                       ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_INT                ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_INT                         ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_FLOAT                       ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_BYTE_3_3_2         ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_BYTE_2_3_3_REV     ) == 2*1);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_5_6_5        ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_5_6_5_REV    ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_4_4_4_4      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_5_5_5_1      ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 2*2);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_INT_8_8_8_8        ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_INT_8_8_8_8_REV    ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_INT_10_10_10_2     ) == 2*4);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL, GL_UNSIGNED_INT_2_10_10_10_REV ) == 2*4);
}

TEST_CASE ( "Check if the bytes per pixel function returns 0 for invalid "
            "parameters.",
            "[gl_pixel]" )
{
    spdlog::set_level(spdlog::level::off);

    CHECK(opengl::bytes_per_pixel( GL_RED             , GL_RED             ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RG              , GL_RG              ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RGB             , GL_RGB             ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BGR             , GL_BGR             ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RGBA            , GL_RGBA            ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BGRA            , GL_BGRA            ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RED_INTEGER     , GL_RED_INTEGER     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RG_INTEGER      , GL_RG_INTEGER      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RGB_INTEGER     , GL_RGB_INTEGER     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BGR_INTEGER     , GL_BGR_INTEGER     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_RGBA_INTEGER    , GL_RGBA_INTEGER    ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BGRA_INTEGER    , GL_BGRA_INTEGER    ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_STENCIL_INDEX   , GL_STENCIL_INDEX   ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_COMPONENT , GL_DEPTH_COMPONENT ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_DEPTH_STENCIL   , GL_DEPTH_STENCIL   ) == 0);

    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE               , GL_UNSIGNED_BYTE               ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BYTE                        , GL_BYTE                        ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT              , GL_UNSIGNED_SHORT              ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_SHORT                       , GL_SHORT                       ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT                , GL_UNSIGNED_INT                ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_INT                         , GL_INT                         ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_FLOAT                       , GL_FLOAT                       ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE_3_3_2         , GL_UNSIGNED_BYTE_3_3_2         ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE_2_3_3_REV     , GL_UNSIGNED_BYTE_2_3_3_REV     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_6_5        , GL_UNSIGNED_SHORT_5_6_5        ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_6_5_REV    , GL_UNSIGNED_SHORT_5_6_5_REV    ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_4_4_4_4      , GL_UNSIGNED_SHORT_4_4_4_4      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_4_4_4_4_REV  , GL_UNSIGNED_SHORT_4_4_4_4_REV  ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_5_5_1      , GL_UNSIGNED_SHORT_5_5_5_1      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_1_5_5_5_REV  , GL_UNSIGNED_SHORT_1_5_5_5_REV  ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT_8_8_8_8        , GL_UNSIGNED_INT_8_8_8_8        ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT_8_8_8_8_REV    , GL_UNSIGNED_INT_8_8_8_8_REV    ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT_10_10_10_2     , GL_UNSIGNED_INT_10_10_10_2     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT_2_10_10_10_REV , GL_UNSIGNED_INT_2_10_10_10_REV ) == 0);

    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE              , GL_RED              ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_BYTE                       , GL_RG               ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT             , GL_RGB              ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_SHORT                      , GL_BGR              ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_INT               , GL_RGBA             ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_INT                        , GL_BGRA             ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_FLOAT                      , GL_RED_INTEGER      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE_3_3_2        , GL_RG_INTEGER       ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_BYTE_2_3_3_REV    , GL_RGB_INTEGER      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_6_5       , GL_BGR_INTEGER      ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_6_5_REV   , GL_RGBA_INTEGER     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_4_4_4_4     , GL_BGRA_INTEGER     ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_4_4_4_4_REV , GL_STENCIL_INDEX    ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_5_5_5_1     , GL_DEPTH_COMPONENT  ) == 0);
    CHECK(opengl::bytes_per_pixel( GL_UNSIGNED_SHORT_1_5_5_5_REV , GL_DEPTH_STENCIL    ) == 0);

    spdlog::set_level(spdlog::level::warn);
}

/* *INDENT-ON* */
