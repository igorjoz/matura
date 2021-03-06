#include <iostream>
#include <cstddef>
#include <vector>
#include <cmath>
#include <set>

std::set<unsigned> getDivisors(unsigned n);
void sphenic(unsigned n);

int main()
{
    sphenic(51382u);

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

void sphenic(unsigned n)
{
    auto set = getDivisors(n);
    std::vector<unsigned> divisors(set.begin(), set.end());
    auto notSphenic = true;

    for (std::size_t i = 1; i < divisors.size() && notSphenic; ++i)
        for (std::size_t j = i + 1; j < divisors.size() && notSphenic; ++j)
            for (std::size_t k = j + 1; k < divisors.size() && notSphenic; ++k)
                if (divisors.at(i) * divisors.at(j) * divisors.at(k) == n) {
                    std::cout << divisors.at(i) << " * " << divisors.at(j) << " * " << divisors.at(k) << '\n';
                    notSphenic = false;
                }

    if (notSphenic)
        std::cout << "NO\n";
}
