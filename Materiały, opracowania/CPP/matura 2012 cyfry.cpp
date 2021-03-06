#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>

bool parzysta(const std::string &str)
{
    char ost = str[str.length() - 1];

    if (ost == '0' || ost == '2' || ost == '4' || ost == '6' || ost == '8') // troche dziwny sposob, ale nie trzeba konwertowac :)
        return true;

    return false;
}

unsigned sumaCyft(const std::string &str)
{
    unsigned suma = 0;

    for (unsigned i = 0; i != str.size(); ++i)
        suma += str[i] - '0';

    return suma;
}

bool rosnacy(std::string &str)
{
    for (unsigned i = 0; i != str.size() - 1; ++i)
        if (str[i] >= str[i + 1])
            return false;

    return true;
}

int main()
{
    std::ifstream plik("cyfry.txt", std::ios::in);
    std::ofstream odp("zadanie4.txt", std::ios::out);
    std::string liczba;
    unsigned parzysych = 0;
    std::map<unsigned, std::string> mapa; // wiemy, ze wystepuje 1 max i 1 min dlatego mozna bez obaw uzyc mapy, a nie multimapy
    std::vector<std::string> rosnace;

    for (unsigned i = 0; i != 1000; ++i)
    {
        plik >> liczba;

        if (parzysta(liczba))
            parzysych++;

        mapa[sumaCyft(liczba)] = liczba;

        if (rosnacy(liczba))
            rosnace.push_back(liczba);
    }

    // ODP A
    std::cout << "a " << parzysych << '\n';
    odp << "a " << parzysych << '\n';

    // ODP B
    auto min = mapa.begin(); // dzieki auto iterator przyjmuje odpowiedni typ dla kontenera, nie tzreba pisac std::map<unsigned, std::string>::iterator
    auto max = mapa.end();
    max--; // cofamy iterator o jedno miejsce, poniewaz wskazuje na pierwsze miejsce poza zakresem mapy
    std::cout << "b\n" << "najmniejsza: " << min->second << "\nnajwieksza: " << max->second << '\n';
    odp << "b\n" << "najmniejsza: " << min->second << "\nnajwieksza: " << max->second << '\n';

    // ODP C
    std::cout << "c\n";
    odp << "c\n";
    for (const auto &el: rosnace)
    {
        std::cout << el << '\n';
        odp << el << '\n';
    }

    plik.close();
    odp.close();

    return 0;
}
