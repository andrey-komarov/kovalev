#include "site_event.h"

voronoi_diagram::site_event::site_event(const point<mpq_class>& p) :
    p(p)
{}

void voronoi_diagram::site_event::process()
{
    // TODO!!!!11111
    int a = 1 / 0;
}

number voronoi_diagram::site_event::get_height() const
{
    return number(p.x);
}
