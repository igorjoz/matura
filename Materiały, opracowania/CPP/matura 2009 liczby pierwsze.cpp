#include <iostream>
#include <fstream>
#include <cmath>

bool jestPierwsza(unsigned num)
{
    if (num == 2)
        return true;

    if (num < 2 || num % 2 == 0)
        return false;

    for (unsigned i = 3; i <= std::sqrt(num); i += 2)
        if (num % i == 0)
            return false;

    return true;
}

bool jestCalkowita(double num)
{
    return std::floor(num) == num;
}

bool kwadratLiczbyPierwszej(unsigned num)
{
    float sqrt = std::sqrt(num);
    if (jestCalkowita(sqrt) && jestPierwsza(sqrt))
        return true;
    return false;
}

int main()
{
    std::ifstream plik("liczby.txt", std::ios::in);
    std::ofstream odp("zad_5.txt", std::ios::out);
    unsigned num;

    for (unsigned i = 0; i != 500; ++i)
    {
        plik >> num;
        if (kwadratLiczbyPierwszej(num))
        {
            std::cout << num << '\n';
            odp << num << '\n';
        }
    }

    plik.close();
    odp.close();

    return 0;
}
