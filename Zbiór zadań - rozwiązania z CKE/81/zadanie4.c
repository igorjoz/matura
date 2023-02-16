#include <stdio.h>

void main() {
    int xa,ya,xb,yb,xc,yc;
    int kw1, kw2, kw3;
    int i, liczba=0;
    FILE* plik = fopen("wspolrzedneTR.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);
        kw1 = (xc-xb)*(xc-xb)+(yc-yb)*(yc-yb);
        kw2 = (xc-xa)*(xc-xa)+(yc-ya)*(yc-ya);
        kw3 = (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);

        if ((kw1==kw2+kw3) || (kw2==kw1+kw3) || (kw3==kw1+kw2)) {
            liczba++;
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc);
        }
    }

    fclose(plik);
    printf("Liczba trojkatow prostokatnych: %d\n", liczba);
}
