#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <map>

std::vector<std::string> pobierzDaneZPliku(std::ifstream &file);
unsigned wyznaczIloscSlowWystepujacychWiecejNizJedenRaz(std::vector<std::string> &vec);
std::string wyznaczSlowoONajwiekszejIlosciWystapien(std::vector<std::string> vec, unsigned &iloscWystapien);
unsigned wyznaczIloscLiczbParzystych(std::vector<std::string> vec);
bool czyPalindrom(std::string str);
unsigned wyznaczIloscPalindromow(std::vector<std::string> vec);

int main()
{
    std::ifstream plik{ "dane.txt" };
    std::ofstream wyniki{ "wyniki.txt" };
    auto slowa = pobierzDaneZPliku(plik);
    unsigned iloscWystapien;

    std::cout << "a)\n";
    std::cout << wyznaczIloscSlowWystepujacychWiecejNizJedenRaz(slowa) << '\n';
    wyniki << "a)\n";
    wyniki << wyznaczIloscSlowWystepujacychWiecejNizJedenRaz(slowa) << '\n';

    std::cout << wyznaczSlowoONajwiekszejIlosciWystapien(slowa, iloscWystapien) << '\n';
    std::cout << iloscWystapien << '\n';
    wyniki << wyznaczSlowoONajwiekszejIlosciWystapien(slowa, iloscWystapien) << '\n';
    wyniki << iloscWystapien << '\n';

    std::cout << "\nb)\n";
    std::cout << wyznaczIloscLiczbParzystych(slowa) << '\n';
    wyniki << "\nb)\n";
    wyniki << wyznaczIloscLiczbParzystych(slowa) << '\n';

    std::cout << "\nc)\n";
    std::cout << wyznaczIloscPalindromow(slowa) << '\n';
    wyniki << "\nc)\n";
    wyniki << wyznaczIloscPalindromow(slowa) << '\n';

    return 0;
}

std::vector<std::string> pobierzDaneZPliku(std::ifstream &file)
{
    std::vector<std::string> vec;
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(vec));

    return vec;
}

unsigned wyznaczIloscSlowWystepujacychWiecejNizJedenRaz(std::vector<std::string> &vec)
{
    std::map<std::string, unsigned> map;

    for (const auto &el: vec)
        if (map.find(el) != map.end())
            map[el]++;
        else
            map[el] = 1;

    return std::count_if(map.begin(), map.end(), [](std::pair<std::string, unsigned> el) { return el.second > 1;});
}

std::string wyznaczSlowoONajwiekszejIlosciWystapien(std::vector<std::string> vec, unsigned &iloscWystapien)
{
    std::sort(vec.begin(), vec.end());
    unsigned sizeVec = vec.size();
    unsigned index;
    unsigned licz = 1;
    unsigned max = 0;

    for (unsigned i = 1; i < sizeVec; ++i)
    {
        if (vec.at(i) == vec.at(i - 1))
            licz++;
        else {
            if (licz > max) {
                iloscWystapien = licz;
                max = licz;
                index = i - 1;
            }

            licz = 1;
        }
    }

    return vec.at(index);
}

unsigned wyznaczIloscLiczbParzystych(std::vector<std::string> vec)
{
    return std::count_if(vec.begin(), vec.end(), [](std::string str) { char c = str.back(); return ( c == 'A' || c == 'C' || c == 'E'); });
}

unsigned wyznaczIloscPalindromow(std::vector<std::string> vec)
{
    return std::count_if(vec.begin(), vec.end(), [](std::string str) { auto str2 = str; std::reverse(str2.begin(), str2.end()); return str == str2; });
}
