#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>

std::string sortujLiczbe(std::string& str);

int main()
{
    std::ifstream dane{"dane_anagramy.txt"};
    std::ofstream wyniki{"wyniki_anagramy.txt"};
    std::map<std::string, unsigned> liczby;
    unsigned liczbaWierszy = 0;
    unsigned max = 0;
    std::string str1;
    std::string str2;

    while (dane >> str1 >> str2) {
        auto x = sortujLiczbe(str1);
        auto y = sortujLiczbe(str2);

        if (x == y)
            liczbaWierszy++;

        liczby[x]++;
        liczby[y]++;

        max = std::max(max, liczby[x]);
        max = std::max(max, liczby[y]);
    }

    wyniki << "a) " << liczbaWierszy << '\n';
    wyniki << "b) " <<  max << '\n';

    return 0;
}

std::string sortujLiczbe(std::string& str)
{
    auto nowy = str;
    std::sort(nowy.begin(), nowy.end());
    return nowy;
}
