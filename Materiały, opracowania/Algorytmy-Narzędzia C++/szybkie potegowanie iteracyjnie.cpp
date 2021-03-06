#include <iostream>

long double fastPower(double base, unsigned exp);

int main()
{
    std::cout.precision(20);
    std::cout << fastPower(2, 32);

    return 0;
}

long double fastPower(double base, unsigned exp)
{
    long double result = 1.0;

    while (exp > 0) {
        if (exp & 1)
            result *= base;

        base *= base;
        exp >>= 1;
    }

    return result;
}
