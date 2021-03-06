#include <iostream>
#include <utility>
#include <vector>

template<typename T>
void quicksort(std::vector<T>& vec, std::size_t left, std::size_t right);
template<typename T>
std::size_t partition(std::vector<T>& vec, std::size_t left, std::size_t right);

int main()
{
    std::vector<int> vec{-6, 7, 11, 3, -4, 0, 5, 0, 23, 21, -2, 4};

    quicksort(vec, 0, vec.size() - 1);

    for (const auto& val : vec)
        std::cout << val << ' ';

    return 0;
}

template<typename T>
void quicksort(std::vector<T>& vec, std::size_t left, std::size_t right)
{
    if (left < right) {
        auto q = partition(vec, left, right);
        quicksort(vec, left, q);
        quicksort(vec, q + 1, right);
    }
}

template<typename T>
std::size_t partition(std::vector<T>& vec, std::size_t left, std::size_t right)
{
    std::size_t p = left;
    T val = vec.at(left);

    for (std::size_t i = left + 1; i <= right; ++i)
        if (vec.at(i) < val) // < grows, > decreases
            std::swap(vec.at(i), vec.at(++p));

    std::swap(vec.at(p), vec.at(left));

    return p;
}
