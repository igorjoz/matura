#include <iostream>
#include <vector>
#include <utility>

template<typename T>
void bubbleSort(std::vector<T>& vec);

int main()
{
    std::vector<int> vec{-6, 7, 11, 3, -4, 0, 5, 0, 23, 21, -2, 4};

    bubbleSort(vec);

    for (const auto& val : vec)
        std::cout << val << ' ';

    return 0;
}

template<typename T>
void bubbleSort(std::vector<T>& vec)
{
    std::size_t n = vec.size();
    bool swapped = true;

    for (std::size_t i = 0; i < n - 1 && swapped; ++i) {
        swapped = false;

        for (std::size_t j = 0; j < n - i - 1; ++j)
            if (vec.at(j) > vec.at(j + 1)){
                std::swap(vec.at(j), vec.at(j + 1));
                swapped = true;
            }
    }
}
