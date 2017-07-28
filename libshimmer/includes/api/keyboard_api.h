#ifndef LIBSHIMMER_API_KEYBOARD_API_H
#define LIBSHIMMER_API_KEYBOARD_API_H

namespace shimmer
{
class keyboard_api
{
public:
    virtual ~keyboard_api() {}

    virtual void grab ( bool* do_grab ) = 0;

    virtual void key_down ( int* key ) = 0;

    virtual void key_up ( int* key ) = 0;
};
}

#endif // ifndef LIBSHIMMER_API_KEYBOARD_API_H
