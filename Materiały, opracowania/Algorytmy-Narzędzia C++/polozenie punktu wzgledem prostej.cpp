#include <iostream>

bool isOnLinear(float a, float b, float x, float y);

int main()
{
    std::cout << isOnLinear(2, 1, 3, 7);

    return 0;
}

bool isOnLinear(float a, float b, float x, float y)
{
    auto result = a * x + b;

    return y == result;
}
