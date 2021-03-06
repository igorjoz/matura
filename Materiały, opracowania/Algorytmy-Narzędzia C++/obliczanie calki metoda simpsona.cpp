#include <iostream>

double fun(double x);
double calcIntegral(double a, double b, double(*f)(double));

int main()
{
    std::cout << calcIntegral(1, 4, fun);

    return 0;
}

double fun(double x)
{
    return x * x * x;
}

double calcIntegral(double a, double b, double(*f)(double))
{
    return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}
