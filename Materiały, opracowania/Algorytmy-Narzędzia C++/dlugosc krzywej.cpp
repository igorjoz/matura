#include <iostream>
#include <cmath>

double f(const double x);
double calcArcLength(double a, double b, unsigned n, double(*f)(const double));

int main()
{
    std::cout << calcArcLength(0, 0.5, 100, f);

    return 0;
}

double f(const double x)
{
    return std::sqrt(1 - x * x);
}

double calcArcLength(double a, double b, unsigned n, double(*f)(const double))
{
    double length {0};
    double dx = 1.0 * (b - a) / n;

    for (std::size_t i = 1; i <= n; ++i)
        length += std::sqrt(std::pow((a + dx * i) - (a + dx * (i - 1)), 2) + std::pow(f(a + dx * i) - f(a + dx * (i - 1)) , 2));

    return length;
}
