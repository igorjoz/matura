#include <iostream>
#include <vector>

double horner(std::vector<double>& coefficients, std::size_t degree, const double x);

int main()
{
    std::vector<double> coefficients{6, 3, 2, 1}; // 6x^3+3x^2+2x+1

    std::cout << horner(coefficients, coefficients.size() - 1, 2);

    return 0;
}

double horner(std::vector<double>& coefficients, std::size_t degree, double x)
{
    if (degree == 0)
        return coefficients.front();

    return horner(coefficients, degree - 1, x) * x + coefficients.at(degree);
}
