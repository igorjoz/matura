#include <iostream>

unsigned long fib(unsigned n);

int main()
{
    std::cout << fib(12);

    return 0;
}

unsigned long fib(unsigned n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 2) + fib(n - 1);
}
