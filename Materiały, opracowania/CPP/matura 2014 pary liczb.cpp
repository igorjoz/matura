#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

bool jestCalkowita(float num)
{
    return std::floor(num) == num;
}

int nwd(int a, int b)
{
    int c;

    while (b != 0)
    {
        c =  a % b;
        a = b;
        b = c;
    }
    return a;
}

int sumaCyfr(std::string str)
{
    int suma = 0;
    for (unsigned i = 0; i != str.size(); ++i)
        suma += str[i] - '0';

    return suma;
}

void ppa()
{
    std::ifstream file("PARY_LICZ.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);

    unsigned wierszy = 0;
    float num1;
    float num2;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> num1 >> num2;

        if (jestCalkowita(num1 / num2))
            wierszy++;

        if (jestCalkowita(num2 / num1))
            wierszy++;
    }

    file2 << "a " << wierszy << '\n';
    std::cout << "a " << wierszy << " wierszy\n";

    file.close();
}

void ppb()
{
    std::ifstream file("PARY_LICZ.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);

    unsigned wierszy = 0;
    int num1;
    int num2;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> num1 >> num2;

        if (nwd(num1, num2) == 1)
            wierszy++;
    }
    file2 << "b " << wierszy << '\n';
    std::cout << "b " << wierszy << " wierszy\n";

    file.close();
}

void ppc()
{
    std::ifstream file("PARY_LICZ.TXT", std::ios::in);
    std::ofstream file2("ZADANIE5.TXT", std::ios::out | std::ios::app);

    unsigned wierszy = 0;
    std::string str1;
    std::string str2;

    for (unsigned i = 0; i != 1000; ++i)
    {
        file >> str1 >> str2;
        if(sumaCyfr(str1) == sumaCyfr(str2))
            wierszy++;
    }

    file2 << "c " << wierszy << '\n';
    std::cout << "c " << wierszy << " wierszy\n";

    file.close();
}

int main()
{
    ppa();
    ppb();
    ppc();

    return 0;
}
