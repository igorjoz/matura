#include <iostream>
#include <vector>

double horner(std::vector<double>& coefficients, double x);

int main()
{
    std::vector<double> coefficients{6, 3, 2, 1}; // 6x^3+3x^2+2x+1

    std::cout << horner(coefficients, 2);

    return 0;
}

double horner(std::vector<double>& coefficients, double x)
{
    double result = coefficients.front();

    for (std::size_t i = 1; i < coefficients.size(); ++i)
        result = result * x + coefficients.at(i);

    return result;
}
