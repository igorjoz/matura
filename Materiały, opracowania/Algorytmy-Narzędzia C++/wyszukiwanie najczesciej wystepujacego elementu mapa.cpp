#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

template<typename T>
T getMostCommonElement(const std::vector<T>& vec);

int main()
{
    std::vector<int> vec {-5, 0 , -5, 3, 4, 3, -5, 11, 0, 2, 9, 6, 7, 13};
    std::vector<std::string> vec2{"damian", "dawid", "olaf", "daniel", "dawid", "damian", "karolina", "dawid"};

    std::cout << getMostCommonElement(vec) << '\n';
    std::cout << getMostCommonElement(vec2) << '\n';

    return 0;
}

template<typename T>
T getMostCommonElement(const std::vector<T>& vec)
{
    std::unordered_map<T, unsigned> map;
    unsigned max = 0;
    T mostCommonElement;

    for (const auto& val : vec)
        if (map.find(val) != map.end())
            map[val]++;
        else
            map[val] = 1;

    for (const auto& val : map)
        if (val.second > max) {
            max = val.second;
            mostCommonElement = val.first;
        }

    return mostCommonElement;
}
