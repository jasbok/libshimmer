#ifndef SHIMMER_CONFIG_H
#define SHIMMER_CONFIG_H

#include "environment.h"
#include "event_connector.h"
#include "options.h"

#include <string>
#include <vector>

namespace shimmer
{
class config
{
public:
    const environment env;

    options opts;

    config( event_connector& connector );

    virtual ~config() = default;

    void load();

    void save() const;


    const general_options& general() const;

    const video_options& video() const;

    config&              general ( const general_options& general );

    config&              video ( const video_options& video );

private:
    event_connector* _connector;

    general_options _general;

    video_options _video;
};
}

#endif // ifndef SHIMMER_CONFIG_H
