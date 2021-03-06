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
    std::size_t first = 0;
    std::size_t last = vec.size();

    while (first != last && first != --last) {
            std::swap(vec.at(first++), vec.at(last));
    }
}
