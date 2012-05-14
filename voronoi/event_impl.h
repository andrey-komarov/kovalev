#ifndef EVENT_IMPL_H
#define EVENT_IMPL_H

#include "number.h"
#include "voronoi_diagram.h"

struct voronoi_diagram::event_impl
{
    virtual number get_height() const = 0;
    virtual void process() = 0;
};

#endif // EVENT_IMPL_H
