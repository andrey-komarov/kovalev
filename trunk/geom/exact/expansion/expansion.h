#ifndef EXPANSION_H
#define EXPANSION_H

#include <vector>
#include <utility>
#include <ostream>

#include "geom/enum.h"
#include "geom/utils.h"

//#define private public

namespace geom
{

const std::size_t MANTISS = 52;

struct expansion
{
    expansion(double = 0);
    expansion(const expansion&);
    expansion(const std::vector<double>&);
    expansion& operator=(const expansion&);

    bool operator==(const expansion&) const;
    bool operator<(const expansion&) const;

    expansion& operator+=(double);
    expansion& operator+=(const std::pair<double, double>&);
    expansion& operator+=(const expansion&);
    expansion& operator*=(double);
    expansion& operator*=(const expansion&);

    geom::Sign sign() const;
    size_t size() const;

    bool is_double() const;
    double approximate_sum() const;

    void swap(expansion&);
private:
    std::vector<double> values_;

    void grow_expansion(double);

    static int sign(double);
    static std::pair<double, double> sum_two(double, double);

    friend expansion operator-(expansion);
    friend std::ostream& operator<<(std::ostream&, const geom::expansion&);
};

expansion operator-(expansion);
expansion& operator-=(expansion&, const expansion&);
expansion operator-(expansion, const expansion&);
expansion operator+(expansion, const expansion&);
expansion operator*(expansion, double);
expansion operator*(expansion, const expansion&);

bool operator!=(const expansion&, const expansion&);

std::pair<double, double> split(double a, int s);

std::pair<double, double> two_product(double a, double b);

std::ostream& operator<<(std::ostream&, const expansion&);

}

namespace std
{
template<>
inline void swap<geom::expansion>(geom::expansion& a, geom::expansion& b)
{
    a.swap(b);
}
}



#endif // EXPANSION_H
