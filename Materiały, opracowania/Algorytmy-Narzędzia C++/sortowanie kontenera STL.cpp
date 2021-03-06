#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec{-5, 6, 0 , 11, 23, 1, -5, -19, 0, 23, 14, 9, 2, -7};
    std::sort(vec.begin(), vec.end());

    for (const auto& el: vec)
        std::cout << el << ' ';

    return 0;
}
