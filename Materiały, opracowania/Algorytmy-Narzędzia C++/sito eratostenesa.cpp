#include <iostream>
#include <cstddef>
#include <vector>
#include <cmath>

std::vector<unsigned> getPrimerNumbers(std::size_t n);

int main()
{
    auto primeNumbers = getPrimerNumbers(97);

    for (const auto& el : primeNumbers)
        std::cout << el << ' ';

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
