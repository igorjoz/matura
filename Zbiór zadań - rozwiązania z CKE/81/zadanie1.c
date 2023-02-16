#include <stdio.h>

void main() {
    int xa,ya,xb,yb,xc,yc;
    int i, liczba=0;
    FILE* plik = fopen("wspolrzedne.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);
        if ((xa>0) && (ya>0) && (xb>0) && (yb>0) && (xc>0) && (yc>0)) {
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc);
            liczba++;
        }
    }

    fclose(plik);
    printf("Liczba trojkatow w I cwiartce: %d\n", liczba);
}
