#include <iostream>
#include <utility>
#include <vector>

template<typename T>
void insertionSort(std::vector<T>& vec);

int main()
{
    std::vector<int> vec{-6, 7, 11, 3, -4, 0, 5, 0, 23, 21, -2, 4};

    insertionSort(vec);

    for (const auto& val : vec)
        std::cout << val << ' ';

    return 0;
}

template<typename T>
void insertionSort(std::vector<T>& vec)
{
    for (std::size_t i = 1; i < vec.size(); ++i) {
        T key = vec.at(i);
        std::size_t j = i - 1;

        while (j >= 0 && vec.at(j) > key) {
            vec.at(j + 1) = vec.at(j);
            j--;
        }

        vec.at(j + 1) = key;
    }
}
