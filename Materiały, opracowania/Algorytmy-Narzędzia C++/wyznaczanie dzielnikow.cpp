#include <iostream>
#include <cmath>
#include <set>

std::set<unsigned> getDivisors(unsigned n);

int main()
{
    auto divisors = getDivisors(36);

    for (const auto& el : divisors)
        std::cout << el << ' ';

    return 0;
}

std::set<unsigned> getDivisors(unsigned n)
{
    std::set<unsigned> divisors;

    for (std::size_t i = 1; i <= std::sqrt(n); ++i)
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }

    return divisors;
}
