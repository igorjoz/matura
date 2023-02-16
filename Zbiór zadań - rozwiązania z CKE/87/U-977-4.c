#include <stdio.h>

void main() {
    int i;
    int ta=20;
    int ts=4;
    float va=4.0;
    float vs=10.0;
    float sa;
    float ss;
    float s;
    float scalk = 0.0;

    for (i=1; i<=107; i++) {
        // czasy plyniecia
        if (i<73){
            ta = 20;
            ts = 4;
        } else if (i==73) {
            ta = 0;
            ts = 0;
        } else if (i<107) {
            ta = 20;
            ts = 4;
        } else {
            ta = 0;
            ts = 9;
        }

        // droga przeplynieta
        sa = va*ta;
        ss = vs*ts;
        s = sa+ss;
        scalk += s;

        // to co mamy
        printf("%d\tt= %d %d\tv= %.2f %.2f\ts= %.2f %.2f\ts= %.2f\tscalk = %.1f\n", i, ta, ts, va, vs, sa, ss, s, scalk);

        // srednie na jutro
        va *= 0.99;
        vs *= 0.99;
    }

}
