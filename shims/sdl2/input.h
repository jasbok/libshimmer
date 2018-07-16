#ifndef SHIMS_SDL2_INPUT_H
#define SHIMS_SDL2_INPUT_H

class input
{
    class shim* _shim;

public:
    input( class shim* shim );

    virtual ~input() = default;
};

#endif // ifndef SHIMS_SDL2_INPUT_H
