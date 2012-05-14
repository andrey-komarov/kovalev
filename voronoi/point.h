#ifndef POINT_H
#define POINT_H

template<typename T>
struct point
{
    point(const T& x, const T& y);
    T x, y;

    bool operator==(const point<T>&) const;
    bool operator<(const point<T>&) const;
};

#endif // POINT_H
