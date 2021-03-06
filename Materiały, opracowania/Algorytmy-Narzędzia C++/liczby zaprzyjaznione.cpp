#include <iostream>
#include <numeric>
#include <cmath>
#include <set>

std::set<unsigned> getDivisors(unsigned n);
bool areAmicable(unsigned a, unsigned b);

int main()
{
    std::cout << areAmicable(220, 284);

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

bool areAmicable(unsigned a, unsigned b)
{
    auto divisorsA = getDivisors(a);
    auto sumA = std::accumulate(divisorsA.begin(), divisorsA.end(), 0) - a;
    auto divisorsB = getDivisors(b);
    auto sumB = std::accumulate(divisorsB.begin(), divisorsB.end(), 0) - b;

    return sumA == b && sumB == a;
}
