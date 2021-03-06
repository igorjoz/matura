#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

std::string odwrocSlowo(std::string word)
{
    std::reverse(word.begin(), word.end());
    return word;
}

bool czyPalindrom(std::string word)
{
    auto word2 = odwrocSlowo(word);
    return word == word2;
}

std::string stworzHaslo(std::string word)
{
    if(czyPalindrom(word))
    {
        return odwrocSlowo(word);
    }
    else
    {
        auto len = word.length() - 1;
        std::string palindrom;

        for (auto i = len; i !=0; --i)
        {
            auto temp = word.substr(0, i);

            if(czyPalindrom(temp))
            {
                palindrom = temp;
                break;
            }
        }

        auto resztaSlowa = word.substr(palindrom.length(), word.length());
        return odwrocSlowo(resztaSlowa) +  word;
    }
}

int main()
{
    std::ifstream slowa{ "slowa.txt" };
    std::string slowo;

    // zadanie 5a

    std::ofstream hasla_a{ "hasla_a.txt" };
    std::ofstream slowa_a{ "slowa_a.txt" };
    std::map<unsigned, std::string> mapaSlowA;

    // zadanie 5b

    std::map<unsigned, std::string> mapaSlowB;
    std::ofstream hasla_b{ "hasla_b.txt" };
    std::ofstream slowa_b{ "slowa_b.txt" };
    unsigned long sumaDlHasel = 0;

    slowa_b << "1.\n";

    while (slowa >> slowo)
    {
        // zadanie 5a

        auto odwroconeSlowo = odwrocSlowo(slowo);
        mapaSlowA[slowo.length()] = odwroconeSlowo;
        hasla_a << odwroconeSlowo << '\n';

        // zadanie 5b
        auto haslo = stworzHaslo(slowo);
        auto dlHasla = haslo.length();
        mapaSlowB[dlHasla] = haslo;

        hasla_b << haslo << '\n';

        if (dlHasla == 12)
        {
            slowa_b << haslo << '\n';
        }

        sumaDlHasel += dlHasla;
    }

    // zadanie 5a

    auto najdluzszeA = mapaSlowA.end();
    najdluzszeA--;
    auto najkrotszeA = mapaSlowA.begin();

    slowa_a << "Najdluzsze slowo: " << najdluzszeA->second << ", znakow: " << najdluzszeA->first << '\n';
    slowa_a << "Najkrotsze slowo: " << najkrotszeA->second << ", znakow: " << najkrotszeA->first << '\n';

    // zadanie 5b

    auto najdluzszeB = mapaSlowB.end();
    najdluzszeB--;
    auto najkrotszeB = mapaSlowB.begin();

    slowa_b << "2.\n";
    slowa_b << "Najdluzsze slowo: " << najdluzszeB->second << ", znakow: " << najdluzszeB->first << '\n';
    slowa_b << "Najkrotsze slowo: " << najkrotszeB->second << ", znakow: " << najkrotszeB->first << '\n';

    slowa_b << "3.\n" << sumaDlHasel << '\n';

    return 0;
}
