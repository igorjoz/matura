#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>

void podpunktA(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn);
void podpunktB(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn);
void podpunktC(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn);
void podpunktD(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn);
void podpunktE(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn);

int main()
{
    std::ifstream plik{"telefony.txt"};
    std::ofstream wyniki{"wyniki_konkursu.txt"};
    std::vector<std::pair<std::string, std::string>> telefony;
    std::string tel;
    std::string odp;

    while (plik >> tel >> odp)
        telefony.emplace_back(std::make_pair(tel, odp));

    podpunktA(telefony, wyniki);
    podpunktB(telefony, wyniki);
    podpunktC(telefony, wyniki);
    podpunktD(telefony, wyniki);
    podpunktE(telefony, wyniki);

    return 0;
}

void podpunktA(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn)
{
    auto lambda = [](std::pair<std::string, std::string>& p) { return p.second == "Tak"; };
    auto naTak = std::count_if(vec.begin(), vec.end(), lambda);
    auto naNie = vec.size() - naTak;

    wyn << "a)\n";
    wyn << "tak: " << naTak << '\n';
    wyn << "nie: " << naNie << '\n';
}

void podpunktB(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn)
{
    auto na5 = std::count_if(vec.begin(), vec.end(), [](std::pair<std::string, std::string>& p){ return p.first.front() == '5'; });
    auto na6 = std::count_if(vec.begin(), vec.end(), [](std::pair<std::string, std::string>& p){ return p.first.front() == '6'; });
    auto na7 = std::count_if(vec.begin(), vec.end(), [](std::pair<std::string, std::string>& p){ return p.first.front() == '7'; });
    auto na8 = vec.size() - na5 - na6 - na7;

    wyn << "b)\n";
    wyn << "grupa 5: " << na5 << '\n';
    wyn << "grupa 6: " << na6 << '\n';
    wyn << "grupa 7: " << na7 << '\n';
    wyn << "grupa 8: " << na8 << '\n';
}

void podpunktC(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn)
{
    std::map<unsigned, std::string> map;
    auto sumaCyfr = [](std::string str) {
        auto liczba = strtol(str.c_str(), NULL, 10);
        auto suma = 0u;
        while (liczba > 0) {
            suma += liczba % 10;
            liczba /= 10;
        }
        return suma; };

    for (const auto& el : vec)
        map[sumaCyfr(el.first)] = el.first;

    wyn << "c)\n";
    wyn << "nr. telefonu: " << map.rbegin()->second << '\n';
    wyn << "suma cyfr: " << map.rbegin()->first << '\n';
}

void podpunktD(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn)
{
    auto najdluzszyCiag = [](std::string str) {
        auto licz = 1u;
        for (std::size_t i = 1; i < str.size(); ++i)
            if (str.at(i) < str.at(i - 1))
                licz++;
            else
                break;
        return licz; };

    std::multimap<unsigned, std::string> map;

    for (const auto& el : vec)
    map.insert({{najdluzszyCiag(el.first)},{el.first}});

    auto najdluzszy = map.rbegin()->first;

    wyn << "d)\n";
    wyn << "dlugosc: " << najdluzszy << '\n';
    wyn << "nr. telefonow: \n";
    for (auto it = map.rbegin(); it != map.rend(); ++it)
        if (it->first == najdluzszy)
            wyn << it->second << '\n';
        else
            break;
}

void podpunktE(std::vector<std::pair<std::string, std::string>> vec, std::ofstream& wyn)
{
    std::vector<std::string> telefony;

    for(const auto& el : vec)
        telefony.emplace_back(el.first);

    std::sort(telefony.begin(), telefony.end());
    std::size_t index = 0;
    unsigned licz = 1;
    unsigned max = 0;

    for (std::size_t i = 1; i < telefony.size(); ++i)
        if (telefony.at(i) == telefony.at(i - 1))
            licz++;
        else {
            if (licz > max) {
                max = licz;
                index = i - 1;
            }
            licz = 1;
        }

    wyn << "e)\n";
    wyn << "liczba smsow: " << max << '\n';
}
