#include <stdio.h>

//
// rozwiazanie bledne - problem zaokraglen liczb rzeczywistych w komputerze
// rozwiazanie podane dla porownania wynikow z poprawnym
//

void main() {
    int xa,ya,xb,yb,xc,yc;
    int i, liczba=0;
    double dl1, dl2, dl3, maks;
    FILE* plik = fopen("wspolrzedne.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);
        dl1 = sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
        dl2 = sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
        dl3 = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
        if (dl1>dl2) {
            maks = dl1;
        } else {
            maks = dl2;
        }
        if (dl3>maks) {
            maks = dl3;
        }
        if (2*maks == dl1+dl2+dl3) {
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc);
            liczba++;
        }
    }

    fclose(plik);
    printf("Liczba linii z 3 punktami z jednej prostej: %d\n", liczba);
}
