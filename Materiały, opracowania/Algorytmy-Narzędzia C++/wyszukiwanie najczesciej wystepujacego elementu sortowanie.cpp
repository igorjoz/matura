#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template<typename T>
T getMostCommonElement(std::vector<T> vec);

int main()
{
    std::vector<int> vec {-5, 0 , -5, 3, 4, 3, -5, 11, 0, 2, 9, 6, 7, 13};
    std::vector<std::string> vec2{"damian", "dawid", "olaf", "daniel", "dawid", "damian", "karolina", "dawid"};

    std::cout << getMostCommonElement(vec) << '\n';
    std::cout << getMostCommonElement(vec2) << '\n';

    return 0;
}

template<typename T>
T getMostCommonElement(std::vector<T> vec)
{
    std::sort(vec.begin(), vec.end());
    std::size_t index = 0;
    unsigned count = 1;
    unsigned max = 0;

    for (std::size_t i = 1; i < vec.size(); ++i) {
        if (vec.at(i) == vec.at(i - 1))
            count++;
        else {
            if (count > max){
                max = count;
                index = i - 1;
            }

            count = 1;
        }
    }

    return vec.at(index);
}
