#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>

bool takaSama(std::string str)
{
    return str[0] == str[str.length() - 1];
}

std::string naDec(std::string &str)
{
    std::string newStr;
    int dec = strtol(str.c_str(), NULL, 8); // ostatni argument to podstawa systemu liczby bedacej napisem, u nas jest 8, a wiec liczba ostatecznie bedzie sys. 10
    std::ostringstream oss;
    oss << dec;
    newStr = oss.str();
    return newStr;
}

bool niemalejaca(std::string str)
{
    for (unsigned i = 0; i != str.size() - 1; ++i)
        if (str[i] > str[i + 1])
            return false;
    return true;
}

int naOct(std::string str)
{
    int oct = strtol(str.c_str(), NULL, 10); // tutaj zamieniamy napis w liczbe o podstawie 8, czyli musimy dac 10, jakbysmy uzyli 8 to zamieniloby nam napis na liczbe 10
    return oct;
}

int main()
{
    std::ifstream plik("dane.txt", std::ios::in);
    std::ofstream odp("wyniki6.txt", std::ios::out);
    std::string liczba;
    std::vector<unsigned> niemalejace;
    unsigned takieSame = 0;
    unsigned takieSameW10 = 0;

    for (unsigned i = 0; i != 5000; ++i)
    {
        plik >> liczba;

        if (takaSama(liczba))
            takieSame++;

        if (takaSama(naDec(liczba)))
            takieSameW10++;

        if(niemalejaca(liczba))
            niemalejace.push_back(naOct(liczba));
    }

    std::cout << "a " << takieSame << '\n';
    odp << "a " << takieSame << '\n';

    std::cout << "b " << takieSameW10 << '\n';
    odp << "b " << takieSameW10 << '\n';

    std::cout << "c " << niemalejace.size() << '\n';
    std::cout << "najmniejsza " << *std::min_element(niemalejace.begin(), niemalejace.end()) << '\n';
    std::cout << "najwieksza " << *std::max_element(niemalejace.begin(), niemalejace.end()) << '\n';
    odp << "c " << niemalejace.size() << '\n';
    odp << "najmniejsza " << *std::min_element(niemalejace.begin(), niemalejace.end()) << '\n';
    odp << "najwieksza " << *std::max_element(niemalejace.begin(), niemalejace.end()) << '\n';

    plik.close();
    odp.close();
    return 0;
}
