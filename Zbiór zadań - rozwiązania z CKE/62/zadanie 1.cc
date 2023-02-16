#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int i;
    int liczba;
    int minimum = 999999;
    int maximum = 0;

    ifstream plik;
    plik.open("liczby1.txt");

    for(i=0; i<1000; i++) {
        plik >> oct >> liczba;
        if (minimum > liczba) {
            minimum = liczba;
        }
        if (maximum < liczba) {
            maximum = liczba;
        }
    }
    plik.close();

    cout << "Zadanie 1:\n";
    cout << "najmniejsza z liczb to " << dec << minimum << " dziesietnie czyli " << oct << minimum << " osemkowo\n";
    cout << "najwieksza z liczb to " << dec << maximum << " dziesietnie czyli " << oct << maximum << " osemkowo\n\n";

    return 0;
}
