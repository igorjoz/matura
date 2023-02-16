#include <stdio.h>

void main() {
    int xa,ya,xb,yb,xc,yc;
    int i, liczba=0;
    FILE* plik = fopen("wspolrzedne.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);
        if ((yb-ya)*(xc-xb) == (yc-yb)*(xb-xa)) {
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc);
            liczba++;
        }
    }

    fclose(plik);
    printf("Liczba linii z 3 punktami z jednej prostej: %d\n", liczba);
}
