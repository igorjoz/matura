#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec{-15, -10, -5, 0, 5, 10, 15};
    int val = -5;

    if (std::binary_search(vec.begin(), vec.end(), -5))
        std::cout << "Wartosc " << val << " zostala znalesiona\n";
    else
        std::cout << "Wartosc " << val << " nie zostala znalesiona\n";

    return 0;
}
