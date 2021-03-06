#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    std::reverse(vec.begin(), vec.end());

    for (const auto& el: vec)
        std::cout << el << ' ';

    return 0;
}
