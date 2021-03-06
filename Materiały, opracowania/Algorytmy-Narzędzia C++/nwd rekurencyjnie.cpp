#include <iostream>
#include <utility>

unsigned gcd(unsigned a, unsigned b);

int main()
{
    std::cout << gcd(12, 24);
    return 0;
}

unsigned gcd(unsigned a, unsigned b)
{
    if (b != 0)
        return gcd(b, a % b);

    return a;
}
