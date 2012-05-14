#ifndef SITE_EVENT_H
#define SITE_EVENT_H

#include "event_impl.h"
#include "number.h"
#include "point.h"
#include "voronoi_diagram.h"

struct voronoi_diagram::site_event : event_impl
{
    site_event(const point<mpq_class>&);
    virtual number get_height() const override;
    virtual void process() override;
private:
    point<mpq_class> p;
};

#endif // SITE_EVENT_H
