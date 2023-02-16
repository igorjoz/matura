#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int i;
    int liczbar = 0;
    int liczbaw = 0;
    int licz1;
    int licz2;

    ifstream plik1;
    plik1.open("liczby1.txt");

    ifstream plik2;
    plik2.open("liczby2.txt");

    for(i=0; i<1000; i++) {
        plik1 >> oct >> licz1;
        plik2 >> dec >> licz2;

        if (licz1 == licz2) {
            liczbar++;
        } else if (licz1 > licz2) {
            liczbaw++;
        }
    }
    plik1.close();
    plik2.close();

    cout << "Zadanie 3:\n";
    cout << liczbar << " par liczb ma te sama wartosc\n";
    cout << liczbaw << " liczb z pierwszego pliku jest wiekszych od odpowiadajacych im liczb z drugiego pliku\n\n";

    return 0;
}

