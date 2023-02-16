#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int i;
    int liczba;
    int temp;
    int cyfr6d = 0;
    int cyfr6o = 0;

    ifstream plik;
    plik.open("liczby2.txt");

    for(i=0; i<1000; i++) {
        plik >> liczba;

        temp = liczba;
        while (temp) {
            if (temp%10 == 6) {
                cyfr6d++;
            }
            temp /= 10;
        }

        temp = liczba;
        while (temp) {
            if (temp%8 == 6) {
                cyfr6o++;
            }
            temp /= 8;
        }
    }
    plik.close();

    cout << "Zadanie 4:\n";
    cout << "w podanych liczbach znalazlem " << cyfr6o << " szostek w zapisie osemkowym\n";
    cout << "w podanych liczbach znalazlem " << cyfr6d << " szostek w zapisie dziesietnym\n\n";

    return 0;
}
