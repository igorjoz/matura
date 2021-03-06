#include <iostream>
#include <cmath>
#include <fstream>

double fun1(double x);
double fun2(double x);
double obliczPole(double a, double b, unsigned n, double(*f)(double));
int wyznaczNajmniejszeC();

int main()
{
    std::ofstream figura{ "figura.txt" };

    double result = obliczPole(0, 10, 1, fun1);
    result += obliczPole(0, 10, 1, fun2);

    std::cout << "a) " << result << '\n';
    figura << "a) " << result << '\n';

    int c = wyznaczNajmniejszeC();

    std::cout << "\nb) najmniejsze C = " << c << '\n';
    figura << "b) najmniejsze C = " << c << '\n';

    int y = fun1(c);

    std::cout << "\nwspolrzedne:\n";
    std::cout << "(" << c << "; " << y << ")\n";
    std::cout << "(" << c << "; " << y - 26 << ")\n";
    std::cout << "(" << c + 100 << "; " << y << ")\n";
    std::cout << "(" << c + 100 << "; " << y - 26 << ")\n";

    figura << "\nwspolrzedne:\n";
    figura << "(" << c << "; " << y << ")\n";
    figura << "(" << c << "; " << y - 26 << ")\n";
    figura << "(" << c + 100 << "; " << y << ")\n";
    figura << "(" << c + 100 << "; " << y - 26 << ")\n";


    return 0;
}

double fun1(double x)
{
    return 1 + (x * x / 100) - (x / 200);
}

double fun2(double x)
{
    return -1 * (x * x) / 50;
}

double obliczPole(double a, double b, unsigned n, double(*f)(double))
{
    double s = 0;
    double dx = (b - a) / n;

    for (unsigned i = 1; i <= n; ++i)
        s += (dx / 6) * (std::abs((f)(a + dx * (i - 1))) + 4 * std::abs((f)(a - dx / 2 + i * dx)) + std::abs((f)(a + i * dx)));

    return s;
}

int wyznaczNajmniejszeC()
{
    unsigned x = 0;

    while (std::trunc(std::abs(fun1(x))) + std::trunc(std::abs(fun2(x))) < 26)
        x++;

    return x;
}
