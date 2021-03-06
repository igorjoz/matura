#include <iostream>
#include <cstddef>
#include <vector>
#include <cmath>

std::vector<unsigned> getPrimerNumbers(std::size_t n);
void sphenic(unsigned n);

int main()
{
    sphenic(114u);

    return 0;
}

std::vector<unsigned> getPrimerNumbers(std::size_t n)
{
    std::vector<unsigned> numbers(n + 1, 0);
    std::vector<unsigned> primeNumbers;

    for (std::size_t i = 2; i < std::sqrt(n); ++i)
        if (numbers.at(i) == 0)
            for (std::size_t j = i * i; j < n; j += i)
                numbers.at(j) = 1;

    for (std::size_t i = 2; i <= n; ++i)
        if (numbers.at(i) != 1)
            primeNumbers.emplace_back(i);

    return primeNumbers;
}

void sphenic(unsigned n)
{
    auto primeNumbers = getPrimerNumbers(114);
    auto notSphenic = true;

    for (std::size_t i = 0; i < primeNumbers.size() && notSphenic; ++i)
        for (std::size_t j = i + 1; j < primeNumbers.size() && notSphenic; ++j)
            for (std::size_t k = j + 1; k < primeNumbers.size() && notSphenic; ++k)
                if (primeNumbers.at(i) * primeNumbers.at(j) * primeNumbers.at(k) == n) {
                    std::cout << primeNumbers.at(i) << " * " << primeNumbers.at(j) << " * " << primeNumbers.at(k) << '\n';
                    notSphenic = false;
                }

    if (notSphenic)
        std::cout << "NO\n";
}
