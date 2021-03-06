#include <iostream>
#include <fstream>
#include <utility>

bool rosnace(int a, int b, int c);
int NWD(int a, int b);
int sumaCyfr(int n);

struct SumaCyfrWWierszach{
    int suma;
    int iloscWierszy;
};

int main()
{
    std::ifstream dane {"liczby.txt"};
    std::ofstream wyniki {"wyniki6.txt"};
    int pierwsza;
    int druga;
    int trzecia;
    int rosnacych {0};
    int sumaNWD {0};
    int sumaCyfrWWierszu;
    int sumaRowna35 {0};
    SumaCyfrWWierszach X {0, 0};


    while (dane >> pierwsza >> druga >> trzecia) {

        if (rosnace(pierwsza, druga, trzecia))
            rosnacych++;

        sumaNWD += NWD(NWD(pierwsza, druga), trzecia);

        sumaCyfrWWierszu = sumaCyfr(pierwsza) + sumaCyfr(druga) + sumaCyfr(trzecia);

        if (sumaCyfrWWierszu == 35)
            sumaRowna35++;

        if (sumaCyfrWWierszu > X.suma) {
            X.suma = sumaCyfrWWierszu;
            X.iloscWierszy = 0;
        }

        if (sumaCyfrWWierszu == X.suma)
            X.iloscWierszy++;

    }

    wyniki << rosnacych << '\n';
    wyniki << sumaNWD << '\n';
    wyniki << sumaRowna35 << '\n';
    wyniki << X.suma << '\n';
    wyniki << X.iloscWierszy << '\n';

    return 0;
}

bool rosnace(int a, int b, int c)
{
    return b > a && c > b;
}

int NWD(int a, int b)
{
    while (b != 0)
        std::swap(a %= b, b);

    return a;
}

int sumaCyfr(int n)
{
    int suma {0};

    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }

    return suma;
}
