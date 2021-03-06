#include <iostream>

double fun(double x);
double calcIntegral(double a, double b, unsigned n, double(*f)(double));

int main()
{
    std::cout << calcIntegral(1, 4, 35, fun);

    return 0;
}

double fun(double x)
{
    return 1 / (x * x);
}

double calcIntegral(double a, double b, unsigned n, double(*f)(double))
{
    if (n % 2 != 0)
        n++;

    double s = 0.0;
    double dx = (b - a) / n;

    for (std::size_t i = 1; i <= n; ++i)
        s += (f(a + (i - 1) * dx) + 4 * f(a - dx / 2 + i * dx) + f(a + i * dx));

    return (dx / 6) * s;
}
