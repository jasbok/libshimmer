#ifndef LIBSHIMMER_KEYBOARD_KEYBOARD_H
#define LIBSHIMMER_KEYBOARD_KEYBOARD_H

#include "api/keyboard_api.h"

namespace shimmer
{
class keyboard : public keyboard_api
{
public:
    keyboard ();

    virtual ~keyboard () {}

    void grab ( bool* do_grab ) override;

    void key_down ( int* key ) override;

    void key_up ( int* key ) override;
};
}

#endif
