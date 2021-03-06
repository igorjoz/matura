#include <iostream>

double fun(double x);
double calcIntegral(double a, double b, unsigned n, double(*f)(double));

int main()
{
    std::cout << calcIntegral(1, 2, 690, fun);

    return 0;
}

double fun(double x)
{
    return x * x;
}

double calcIntegral(double a, double b, unsigned n, double(*f)(double))
{
    auto width = (b - a) / n;
    auto result  = 0.0;

    for (std::size_t i = 0; i < n; ++i)
        result += f(a + width * i + width / 2);

    return width * result;
}
