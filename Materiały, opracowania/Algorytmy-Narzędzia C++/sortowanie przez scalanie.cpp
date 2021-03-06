#include <iostream>
#include <iterator>
#include <vector>

template<typename T>
void merge(std::vector<T>& vec, std::size_t begin, std::size_t middle, std::size_t end);
template<typename T>
void mergeSort(std::vector<T>& vec, std::size_t begin, std::size_t end);

int main()
{
    std::vector<int> vec{-6, 7, 11, 3, -4, 0, 5, 0, 23, 21, -2, 4};

    mergeSort(vec, 0, vec.size() - 1);

    for (const auto& val : vec)
        std::cout << val << ' ';

    return 0;
}

template<typename T>
void merge(std::vector<T>& vec, std::size_t begin, std::size_t middle, std::size_t end)
{
    std::size_t n1 = middle - begin + 1;
    std::size_t n2 = end - middle;
    std::vector<T> left(n1);
    std::vector<T> right(n2);

    for (std::size_t i = 0; i < n1; ++i)
        left.at(i) = vec.at(begin + i);

    for (std::size_t i = 0; i < n2; ++i)
        right.at(i) = vec.at(middle + i + 1);

    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = begin;

	while (i < n1 && j < n2)
		if (left.at(i) <= right.at(j))
			vec.at(k++) = left.at(i++);
		else
			vec.at(k++) = right.at(j++);

	while (i < n1)
		vec.at(k++) = left.at(i++);

	while (j < n2)
		vec.at(k++) = right.at(j++);

}

template<typename T>
void mergeSort(std::vector<T>& vec, std::size_t begin, std::size_t end)
{
    if (begin != end) {
        std::size_t middle = (begin + end) / 2;
        mergeSort(vec, begin, middle);
        mergeSort(vec, middle + 1, end);
        merge(vec, begin, middle, end);
    }
}
