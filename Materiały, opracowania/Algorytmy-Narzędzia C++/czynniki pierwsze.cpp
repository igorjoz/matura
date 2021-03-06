#include <iostream>
#include <vector>
#include <cmath>

std::vector<unsigned> getPrimeFactors(unsigned num);

int main()
{
    auto primeFactors = getPrimeFactors(1520);

    for (const auto& val : primeFactors)
        std::cout << val << ' ';

    return 0;
}

std::vector<unsigned> getPrimeFactors(unsigned num)
{
    std::vector<unsigned> primeFactors;

    while (num % 2 == 0) {
        primeFactors.emplace_back(2);
        num /= 2;
    }

    for (std::size_t i = 3; i <= std::sqrt(num); i += 2)
        while (num % i == 0) {
            primeFactors.emplace_back(i);
            num /= i;
        }

    if (num > 2)
        primeFactors.emplace_back(num);

    return primeFactors;
}
