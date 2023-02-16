#include <stdio.h>

void main() {
    int xa,ya,xb,yb,xc,yc,xd,yd;
    int i, liczba=0;
    FILE* plik = fopen("wspolrzedneTR.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);

        xd = xa+xc-xb;
        yd = ya+yc-yb;
        if (xd == yd) {
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i, xa,ya, xb,yb, xc,yc, xd,yd);
            liczba++;
        }
    }

    fclose(plik);
    printf("Liczba punktow D na prostej y=x: %d\n", liczba);
}
