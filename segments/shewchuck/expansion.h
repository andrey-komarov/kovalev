#ifndef EXPANSION_H
#define EXPANSION_H

#include <vector>
#include <utility>
#include <ostream>

#define private public

const std::size_t MANTISS = 52;

struct expansion
{
    expansion(double = 0);
    expansion(const expansion&);
    expansion(const std::vector<double>&);
    expansion& operator=(const expansion&);

    void add(double);
    void add(std::pair<double, double>);
    void add(expansion);
    int sign() const;
    int size() const;
    double approximate_sum() const;

private:
    std::vector<double> values_;

    void grow_expantion(double);

    static int sign(double);
    static std::pair<double, double> sum_two(double, double);

    friend std::ostream& operator<<(std::ostream&, const expansion&);

};

std::pair<double, double> split(double a, int s);

std::pair<double, double> two_product(double a, double b);

std::ostream& operator<<(std::ostream&, const expansion&);

#endif // EXPANSION_H
