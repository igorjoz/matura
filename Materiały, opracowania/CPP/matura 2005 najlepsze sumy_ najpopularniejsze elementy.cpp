#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>

std::vector<int> loadData(std::ifstream &file);
long getBestSum(std::vector<int> vec);
int getMostPopularElement(std::vector<int> vec);

int main()
{
    std::ifstream data1{ "dane5-1.txt" };
    std::ifstream data2{ "dane5-2.txt" };
    std::ifstream data3{ "dane5-3.txt" };

    auto data = loadData(data1);

    std::cout << "Nalepsza suma dane5-1: " << getBestSum(data) << '\n';
    std::cout << "Najpopularniejszy element dane5-1: " << getMostPopularElement(data) << "\n\n";

    data = loadData(data2);

    std::cout << "Nalepsza suma dane5-2: " << getBestSum(data) << '\n';
    std::cout << "Najpopularniejszy element dane5-2: " << getMostPopularElement(data) << "\n\n";

    data = loadData(data3);

    std::cout << "Nalepsza suma dane5-3: " << getBestSum(data) << '\n';
    std::cout << "Najpopularniejszy element dane5-3: " << getMostPopularElement(data) << "\n\n";

    return 0;
}

std::vector<int> loadData(std::ifstream &file)
{
    std::vector<int> data;
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(data));

    return data;
}

long getBestSum(std::vector<int> vec)
{
    long bestSum = *vec.begin();
    long sum = 0;
    unsigned sizeVec = vec.size();

    for (unsigned i = 0; i < sizeVec; ++i) {
        sum = vec[i];

        for (unsigned j = i + 1; j < sizeVec; ++j) {
            sum += vec[j];

            if (sum > bestSum)
                bestSum = sum;
        }
    }

    return bestSum;
}

int getMostPopularElement(std::vector<int> vec)
{
    std::sort(vec.begin(), vec.end());
    size_t sizeVec = vec.size();
    unsigned index = 0;
    unsigned count = 1;
    unsigned max = 0;

    for (size_t i = 1; i < sizeVec; ++i)
    {
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
