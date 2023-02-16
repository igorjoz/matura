#include <stdio.h>

//
// rozwiazanie bledne - problem zaokraglen liczb rzeczywistych w komputerze
// rozwiazanie podane dla porownania wynikow z poprawnym
//

void main() {
    int xa,ya,xb,yb,xc,yc;
    int kw1, kw2, kw3;
    double dl1, dl2, dl3;
    double k1, k2, k3;
    int i, liczba=0;
    FILE* plik = fopen("wspolrzedneTR.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);

        dl1 = sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
        dl2 = sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
        dl3 = sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
        k1 = dl1*dl1;
        k2 = dl2*dl2;
        k3 = dl3*dl3;

        if ((k1==k2+k3) || (k2==k1+k3) || (k3==k1+k2)) {
            liczba++;
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc);
        }
    }

    fclose(plik);
    printf("Liczba trojkatow prostokatnych: %d\n", liczba);
}
