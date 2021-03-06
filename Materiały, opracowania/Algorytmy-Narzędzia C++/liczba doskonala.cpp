#include <iostream>
#include <numeric>
#include <cmath>
#include <set>

std::set<unsigned> getDivisors(unsigned n);
bool isPerfect(unsigned n);

int main()
{
    std::cout << isPerfect(33550336);

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

bool isPerfect(unsigned n)
{
    auto divisors = getDivisors(n);
    auto sum = std::accumulate(divisors.begin(), divisors.end(), 0) - n;

    return sum == n;
}
