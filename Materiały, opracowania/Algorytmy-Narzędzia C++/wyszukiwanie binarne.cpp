#include <iostream>
#include <vector>

template<typename T>
bool binarySearch(const std::vector<T>& vec, std::size_t firstIndex, std::size_t lastIndex, const T& target, std::size_t& outIndex);

int main()
{
    std::vector<int> vec{-15, -10, -5, 0, 5, 10, 15};
    std::size_t index;
    int val = -5;

    if (binarySearch(vec, 0, vec.size(), val, index))
        std::cout << "Wartosc " << val << " zostala znalesiona na pozycji " << index << '\n';
    else
        std::cout << "Wartosc " << val << " nie zostala znalesiona\n";

    return 0;
}

template<typename T>
bool binarySearch(const std::vector<T>& vec, std::size_t firstIndex, std::size_t lastIndex, const T& target, std::size_t& outIndex)
{
    while (firstIndex <= lastIndex) {
        int midIndex = (firstIndex + lastIndex) / 2;

        if (vec.at(midIndex) == target) {
            outIndex = midIndex;
            return true;
        }

        if (vec.at(midIndex) > target)
            lastIndex = midIndex - 1;
        else
            firstIndex = midIndex + 1;
    }

    return false;
}
