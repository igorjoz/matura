#include <iostream>
#include <utility>
#include <vector>

template<typename T>
void selectionSort(std::vector<T>& vec);

int main()
{
    std::vector<int> vec{-6, 7, 11, 3, -4, 0, 5, 0, 23, 21, -2, 4};

    selectionSort(vec);

    for (const auto& val : vec)
        std::cout << val << ' ';

    return 0;
}

template<typename T>
void selectionSort(std::vector<T>& vec)
{
    std::size_t n = vec.size();

    for (std::size_t i = 0; i < n; ++i) {
        std::size_t indexMin = i;

        for (std::size_t j = i + 1; j < n; ++j)
            if (vec.at(j) < vec.at(indexMin))
                indexMin = j;

        std::swap(vec.at(i), vec.at(indexMin));
    }
}
