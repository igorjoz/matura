#include <iostream>
#include <utility>

unsigned gcd(unsigned a, unsigned b);

int main()
{
    std::cout << gcd(24, 12);

    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
    while (b != 0)
        std::swap(a %= b, b);

    return a;
}
