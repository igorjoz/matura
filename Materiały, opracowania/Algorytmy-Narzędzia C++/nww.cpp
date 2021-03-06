#include <iostream>
#include <utility>

unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);

int main()
{
    std::cout << lcm(192, 348);

    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
    while (b != 0)
        std::swap(a %= b, b);

    return a;
}

unsigned lcm(unsigned a, unsigned b)
{
    return a / gcd(a, b) * b;
}
