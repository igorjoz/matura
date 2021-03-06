#include <iostream>

long double fastPower(double base, unsigned exp);

int main()
{
    std::cout.precision(20);
    std::cout << fastPower(6, 21);

    return 0;
}

long double fastPower(double base, unsigned exp)
{
    if (exp == 0)
        return 1;

    if (exp & 1)
        return base * fastPower(base, (exp - 1) >> 1) * fastPower(base, (exp - 1) >> 1);

    return fastPower(base, exp >> 1) * fastPower(base, exp >> 1);
}
