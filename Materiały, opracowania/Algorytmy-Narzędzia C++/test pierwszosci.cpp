#include <iostream>
#include <cmath>

bool isPrime(unsigned long n);

int main()
{
    std::cout << isPrime(97);

    return 0;
}

bool isPrime(unsigned long n)
{
    if (n == 2)
        return true;

    if (n < 2 || (n % 2 == 0 && n != 2))
        return false;

    for (std::size_t i = 3; i <= std::sqrt(n); i += 2)
        if (n % i == 0)
            return false;

    return true;
}
