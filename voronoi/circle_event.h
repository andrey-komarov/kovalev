#ifndef CIRCLE_EVENT_H
#define CIRCLE_EVENT_H

#include "voronoi_diagram.h"
#include "event_impl.h"

struct voronoi_diagram::circle_event : event_impl
{
    virtual number get_height () const override;
    virtual void process() override;
private:
    number height;
};

#endif // CIRCLE_EVENT_H
