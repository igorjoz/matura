#include <iostream>
#include <cmath>

double fun(const double x);
bool regulaFalsi(double a, double b, const double accuracy, double(*f)(double), double &root);

int main()
{
    double root = 0;

    if (regulaFalsi(-6, -2, 0.00001, fun, root))
        std::cout << "Miejsce zerowe: " << root << '\n';
    else
        std::cout << "Brak miejsca zerowego lub nie mozna wyznaczyc\n";

    return 0;
}

double fun(const double x)
{
    return (x + 5) * (x - 3);
}

bool regulaFalsi(double a, double b, const double accuracy, double(*f)(double), double &root)
{
    if (f(a) * f(b) > 0)
        return false;

    double x0 = a;
    double x1 = b;
    double fa = f(a);
    double fb = f(b);
    double fx;

    while (std::abs(x1 - x0) >= accuracy) {
        x1 = x0;
        x0 = a - fa * (b - a) / (fb - fa);

        fx = f(x0);

        if (std::abs(x0) <= accuracy)
            break;

        if (fa * fb < 0) {
            b = x0;
            fb = fx;
        } else {
            a = x0;
            fa = fx;
        }
    }

    root = x0;
    return true;

}
