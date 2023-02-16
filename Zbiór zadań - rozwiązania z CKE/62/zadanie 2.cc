#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int i;
    int liczba;
    int poprzednia = -1;
    int pierwszy = -1;
    int dlugosc_ciagu = 0;
    int naj_dlugosc_ciagu = 0;
    int naj_pierwszy;

    ifstream plik;
    plik.open("liczby2.txt");

    for(i=0; i<1000; i++) {
        plik >> liczba;
        if (liczba >= poprzednia) {
            dlugosc_ciagu++;
        } else {
            pierwszy = liczba;
            dlugosc_ciagu = 1;
        }
        if (dlugosc_ciagu > naj_dlugosc_ciagu) {
            naj_dlugosc_ciagu = dlugosc_ciagu;
            naj_pierwszy = pierwszy;
        }

        poprzednia = liczba;
    }
    plik.close();

    cout << "Zadanie 2:\n";
    cout << "najdluzszy ciag zaczyna sie od elementu " << naj_pierwszy << " i ma " << naj_dlugosc_ciagu << " elementow\n\n";

    return 0;
}
