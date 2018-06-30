#ifndef SHIMMER_PIPELINE_BUILDER_H
#define SHIMMER_PIPELINE_BUILDER_H

#include "glpp.h"
#include "pipeline.h"

namespace shimmer
{
class pipeline_builder
{
public:
    glpp::program program_from ( const shader& shader );

private:
};
}

#endif // ifndef SHIMMER_PIPELINE_BUILDER_H
