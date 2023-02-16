#include <stdio.h>
#include <math.h>

void main() {
    int xa,ya,xb,yb,xc,yc;
    int i;
    double obwod;
    double najdluzszy = 0.0;
    FILE* plik = fopen("wspolrzedneTR.txt", "r");

    for (i=0; i<100; i++) {
        fscanf(plik, "%d\t%d\t%d\t%d\t%d\t%d\n", &xa, &ya, &xb, &yb, &xc, &yc);
        obwod = sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb))+sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya))+sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
        if (obwod>najdluzszy) {
            najdluzszy = obwod;
            printf("%d)\t%d\t%d\t%d\t%d\t%d\t%d\tobwod: %.2f\n", i, xa,ya, xb,yb, xc,yc, obwod);
        }
    }

    fclose(plik);
}
