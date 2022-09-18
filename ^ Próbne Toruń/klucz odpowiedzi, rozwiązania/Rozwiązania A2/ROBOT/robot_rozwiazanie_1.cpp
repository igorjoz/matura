#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int plansza[22][22];
string gracze[1000];
int punkty[1000];
int ruchyWWierszu[1000];

int policzPunkty(int nrGracza) {
    string instr = gracze[nrGracza];
    int pkt = plansza[1][1];
    int x = 1, y = 1;
    for(int i = 0; i < instr.length(); i++) {
        switch(instr[i]) {
        case 'S':
            y++;
            break;
        case 'N':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        }

        if(plansza[y][x] == -1) {
            pkt = -1;
            break;
        }

        pkt += plansza[y][x];
    }

    return pkt;
}

int iluZdysk() {
    int wynik = 0;
    for(int i = 0; i < 1000; i++) {
        if(punkty[i] == -1) {
            wynik++;
        }
    }

    return wynik;
}

int maksPkt() {
    int maks = punkty[0], id = 0;
    for(int i = 1; i < 1000; i++) {
        if(maks < punkty[i]) {
            maks = punkty[i];
            id = i;
        }
    }

    return id;
}

int maksRuchowWWierszuDlaGracza(int nrGracza) {
    string instr = gracze[nrGracza];
    int maks = 0, zlicz=0;
    for(int i = 0; i < instr.length(); i++) {
        if(instr[i] == 'W' || instr[i] == 'E') {
            zlicz++;
        } else {
            if(zlicz > maks) {
                maks = zlicz;
            }

            zlicz = 0;
        }
    }

    if(zlicz > maks) {
        maks = zlicz;
    }

    zlicz = 0;
    return maks;
}

int maksRuchowWWierszyDlaWszystkich() {
    int maks = ruchyWWierszu[0];
    for(int i = 1; i < 1000; i++) {
        if(ruchyWWierszu[i] > maks) {
            maks = ruchyWWierszu[i];
        }
    }

    return maks;
}

int main() {
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++) {
            plansza[i][j] = -1;
        }
    }

    ifstream daneP("plansza.txt"), daneR("robot.txt");
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= 20; j++) {
            daneP >> plansza[i][j];
        }
    }

    for(int i = 0; i < 1000; i++) {
        daneR >> gracze[i];
        punkty[i] = policzPunkty(i);
        ruchyWWierszu[i] = maksRuchowWWierszuDlaGracza(i);
    }

    daneP.close();
    daneR.close();

    ofstream wyniki("zadanie4.txt");
    wyniki << "4.1" << endl << iluZdysk() << endl << endl;
    int id = maksPkt();
    wyniki << "4.2" << endl << "Numer gracza: " << id+1 << endl << "Wynik: " << punkty[id] << endl << endl;
    int maks = maksRuchowWWierszyDlaWszystkich();
    wyniki << "4.3" << endl << "Maksimum: " << maks << endl;
    wyniki << "Numery graczy:" << endl;
    for(int i = 0; i < 1000; i++) {
        if(ruchyWWierszu[i] == maks) {
            wyniki << i+1 << endl;
        }
    }

    wyniki.close();


    return 0;
}
