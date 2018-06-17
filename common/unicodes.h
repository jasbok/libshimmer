#ifndef COMMON_UNICODES_H
#define COMMON_UNICODES_H

#include "range.h"

namespace common::unicodes{
static range_uint control_character { 0x00000, 0x00020 };
static range_uint basic_latin { 0x00020, 0x00080 };
static range_uint latin_1_supplement { 0x00080, 0x00100 };
static range_uint latin_extended_a { 0x00100, 0x00180 };
static range_uint latin_extended_b { 0x00180, 0x00250 };
static range_uint greek_and_coptic { 0x00370, 0x00400 };
}

#endif
