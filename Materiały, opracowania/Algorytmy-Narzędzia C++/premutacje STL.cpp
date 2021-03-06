#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> numbers{1, 2, 3, 4};

    do {

        for (const auto& num : numbers)
            std::cout << num << ' ';

        std::cout << '\n';

    } while (std::next_permutation(numbers.begin(), numbers.end()));

    return 0;
}
