#ifndef LIBSHIMMER_API_MOUSE_API_H
#define LIBSHIMMER_API_MOUSE_API_H

namespace shimmer
{
class mouse_api
{
public:
    virtual ~mouse_api () {}

    virtual void cursor ( int* x, int* y ) = 0;

    virtual void grab ( bool* do_grab ) = 0;

    virtual void button_down ( int* button ) = 0;

    virtual void button_up ( int* button ) = 0;

    virtual void scroll_up ( bool* do_scroll ) = 0;

    virtual void scroll_down ( bool* do_scroll ) = 0;
};
}

#endif
