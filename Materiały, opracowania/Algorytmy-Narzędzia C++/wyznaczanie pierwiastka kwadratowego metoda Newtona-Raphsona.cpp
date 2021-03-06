#include <iostream>
#include <cmath>

double squareRoot(const double& x, const double& accuracy);

int main()
{
    //std::cout.precision(10);
    std::cout << squareRoot(9, 0.0001);

    return 0;
}

double squareRoot(const double& x, const double& accuracy)
{
    double a = x;

    while (std::abs(a - (x / a)) > accuracy)
        a = (a + (x / a)) / 2;

    return a;
}
