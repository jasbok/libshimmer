#ifndef LIBSHIMMER_SHIMMER_H
#define LIBSHIMMER_SHIMMER_H

#include "api/init_api.h"
#include "api/keyboard_api.h"
#include "api/mouse_api.h"
#include "api/renderer_api.h"
#include "api/window_api.h"

#include <memory>

namespace shimmer
{
class shimmer
{
public:
    shimmer();

    virtual ~shimmer();

    std::shared_ptr<keyboard_api> keyboard();

    std::shared_ptr<mouse_api> mouse();

    std::shared_ptr<renderer_api> renderer();

    std::shared_ptr<window_api> window();

};
}

#endif
