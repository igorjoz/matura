#include <iostream>
#include <cmath>

double fun(double x);
bool bisection(double a, double b, const double accuracy, double(*f)(double), double &root);

int main()
{
    double root = 0;

    if (bisection(1, 6, 0.000001, fun, root))
        std::cout << "Miejsce zerowe: " << root << '\n';
    else
        std::cout << "Brak miejsca zerowego lub brak mozliwosci wyznaczenia w podanym przedziale\n";

    return 0;
}

double fun(double x)
{
    return (x - 5) * (x + 3);
}

bool bisection(double a, double b, const double accuracy, double(*f)(double), double &root)
{
    if (f(a) * f(b) > 0)
        return false;

    double c;

    while (std::abs(a - b) >= accuracy) {
        c = (a + b) / 2;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    root = c;
    return true;
}
