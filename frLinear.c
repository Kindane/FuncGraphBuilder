#include "dot.h"

/*
 * Fractional Linear Function
 * y = (ax+b)/(cx+d)
 * https://encyclopedia2.thefreedictionary.com/Linear+Fractional+Function
 */

int main() {
    float k;
    dot2f* helpDotsArr = (dot2f*)malloc(sizeof(dot2f)*6);
    printf("Fractional Linear Function:\n");
    printf("    k \n");
    printf("y = - \n");
    printf("    x \n");

    printf("enter k: "); scanf("%f", &k);
    if (k == 0) {
        printf("k cannot be zero, abort.\n");
        exit(1);
    }

    for (int i = 0, value = -3; i < 6; i++, value++) {
        if (value == 0) value++;
        initDot2f(&helpDotsArr[i], value, k/value);
        showDot2f(&helpDotsArr[i]);
    }

    return 0;
}
