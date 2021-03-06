#include <iostream>
#include <algorithm>

struct point
{
    float x;
    float y;
};

bool checkEquation(point A, point B, point C);
bool checkValue(point A, point B, point C);

int main()
{
    point A{1, 1};
    point B{3, 5};
    point C{2, 3};

    std::cout << (checkEquation(A, B, C) && checkValue(A, B, C));

    return 0;
}

bool checkEquation(point A, point B, point C)
{
    float result = (B.x * C.y) +(A.x * B.y) + (C.x * A.y) - (A.x * C.y) - (B.x * A.y) - (C.x * B.y);

    return result == 0;
}

bool checkValue(point A, point B, point C)
{
    if (C.x < std::min(A.x, B.x))
        return false;

    if (C.x > std::max(A.x, B.x))
        return false;

    if (C.y < std::min(A.x, B.x))
        return false;

    if (C.y > std::max(A.x, B.x))
        return false;

    return true;
}
