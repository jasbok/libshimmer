#ifndef LIBSHIMMER_MOUSE_MOUSE_H
#define LIBSHIMMER_MOUSE_MOUSE_H

#include "mouse_api.h"

namespace shimmer
{
class mouse :  public mouse_api {

public:
    mouse ();

    virtual ~mouse () {}

    void cursor ( int* x, int* y ) override;

    void grab ( bool* do_grab ) override;

    void button_down ( int* button ) override;

    void button_up ( int* button ) override;

    void scroll_up ( bool* do_scroll ) override;

    void scroll_down ( bool* do_scroll ) override;
};
}

#endif
