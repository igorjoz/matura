#include <iostream>
#include <fstream>
#include <cmath>

double f(const double x);
double g(const double x);
double calcInt(double a, double b, unsigned n, double(*f)(const double));
double calcArcLength(double a, double b, unsigned n, double(*f)(const double));
double designateLength(double a, double b);

int main()
{
    std::cout << (calcInt(2, 10, 1000, f) - calcInt(2, 10, 1000, g)) << '\n';
    std::cout << std::ceil(8 + 8 + 0.488 + 19 + 32 + 2.0 / 3.0 + calcArcLength(2, 10, 1000, f) + calcArcLength(2, 10, 1000, g)) << '\n';
    std::cout << designateLength(2, 10) << '\n';

    return 0;
}

double f(const double x)
{
    return std::pow(x, 4) / 500 - std::pow(x, 2) / 200 - 0.012;
}
double g(const double x)
{
    return -1 * std::pow(x, 3) / 30 + x / 20 + 1.0 / 6.0;
}

double calcInt(double a, double b, unsigned n, double(*f)(double))
{
    if (n % 2 != 0)
        n++;

    double s {0.0};
    double dx = (b - a) / n;

    for (std::size_t i = 1; i <= n; ++i)
        s += (f(a + (i - 1) * dx) + 4 * f(a - dx / 2 + i * dx) + f(a + i * dx));

    return (dx / 6) * s;
}

double calcArcLength(double a, double b, unsigned n, double(*f)(const double))
{
    double length {0};
    double dx = (b - a) / n;

    for (std::size_t i = 1; i <= n; ++i)
        length += std::sqrt(std::pow((a + dx * i) - (a + dx * (i - 1)), 2) + std::pow(f(a + dx * i) - f(a + dx * (i - 1)) , 2));

    return length;
}

double designateLength(double a, double b)
{
    double len {0};

    for (double x = a; x < b; x += 0.25)
        len += std::floor(f(x) - g(x));

    return len;
}
