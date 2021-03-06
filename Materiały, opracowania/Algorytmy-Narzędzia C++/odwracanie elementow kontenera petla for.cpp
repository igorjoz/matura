#include <iostream>
#include <utility>
#include <vector>

void reverse(std::vector<int>& vec);

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    reverse(vec);

    for (const auto& el: vec)
        std::cout << el << ' ';

    return 0;
}

void reverse(std::vector<int>& vec)
{
    std::size_t len = vec.size();

    for (std::size_t i = 0; i < len / 2; ++i)
        std::swap(vec.at(i), vec.at(len - i - 1));
}
