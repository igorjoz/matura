#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <array>

bool jestPierwsza(unsigned num)
{
     if (num == 2)
        return true;

    if (num < 2 || (num % 2 == 0 && num != 2))
        return false;

    for (unsigned i = 3; i <= std::sqrt(num); i += 2)
        if (num % i == 0)
            return false;

    return true;
}

bool saBlizniacze(unsigned x, unsigned y)
{
    if (jestPierwsza(x) && jestPierwsza(y))
        if (x - y == 2 || y - x == 2) // trzeba sprawdzic dwa warianty, pierwsza i druga oraz drugia - pierwsza
            return true;

    return false;
}

int main()
{
    std::ifstream liczbyPlik("dane_6.txt", std::ios::in); // na stronie CKE plik nazywa sie dane4.txt!!!
    std::ofstream odp("wyniki_6.txt", std::ios::out);
    std::array<unsigned, 2000> liczby;
    std::vector<unsigned> liczbyPierwsze;
    std::vector<unsigned> blizniaki;

    for (unsigned i = 0; i != 2000; ++i)
    {
        unsigned num;
        liczbyPlik >> num;
        liczby[i] = num;

        if (jestPierwsza(num))
            liczbyPierwsze.push_back(num);
    }

    // ODP 6.1
    std::cout << "6.1 liczb pierwszych: " << liczbyPierwsze.size() << '\n';
    odp << "6.1 liczb pierwszych: " << liczbyPierwsze.size() << '\n';

    // ODP 6.2
    std::cout << "6.2\n";
    std::cout << "min: " << *std::min_element(liczbyPierwsze.begin(), liczbyPierwsze.end()) << '\n';
    std::cout << "max: " << *std::max_element(liczbyPierwsze.begin(), liczbyPierwsze.end()) << '\n';
    odp << "6.2\n";
    odp << "min: " << *std::min_element(liczbyPierwsze.begin(), liczbyPierwsze.end()) << '\n';
    odp << "max: " << *std::max_element(liczbyPierwsze.begin(), liczbyPierwsze.end()) << '\n';

    // ODP 6.3
    for (unsigned i = 0; i != liczby.size() - 1; ++i)
    {
        if (saBlizniacze(liczby[i], liczby[i + 1]))
        {
            blizniaki.push_back(liczby[i]);
            blizniaki.push_back(liczby[i + 1]);
        }
    }

    std::cout << "6.3 liczb blizniaczych: " << blizniaki.size() / 2 << '\n';
    odp << "6.3 liczb blizniaczych: " << blizniaki.size() / 2 << '\n';

    for (unsigned i = 0; i < blizniaki.size() - 1; i += 2)
    {
        std::cout << blizniaki[i] << " i " << blizniaki[i + 1] << '\n';
        odp << "6.3 liczb blizniaczych: " << blizniaki.size() / 2 << '\n';
    }

    liczbyPlik.close();
    odp.close();
    return 0;
}
