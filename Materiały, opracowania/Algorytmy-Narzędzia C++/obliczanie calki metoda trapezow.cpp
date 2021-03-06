#include <iostream>

double fun(double x);
double calcIntegral(double a, double b, unsigned n, double(*f)(double));

int main()
{
    std::cout << calcIntegral(0, 4, 4, fun);

    return 0;
}

double fun(double x)
{
    return -x + 4;
}

double calcIntegral(double a, double b, unsigned n, double(*f)(double))
{
    auto height = (b - a) / n;
    auto result  = 0.0;

    for (std::size_t i = 1; i <= n; ++i)
        result += f(a + i * height);

    return (height / 2) * (f(a) + 2 * result + f(b));
}
