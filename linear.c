#include "dot.h"
/*
 * LINEAR FUNCTION:
 * f(x) = kx + b
 */

int main() {
    float k, b;
    dot2f first;
    dot2f second;

    printf("Linear function kx+b\n");
    printf("enter K: ");
    scanf("%f", &k);
    printf("enter B: ");
    scanf("%f", &b);

    initDot2f(&first, 0, 0*k+b);
    initDot2f(&second, 1, 1*k+b);

    printf("First dot is:\n");
    showDot2f(&first);
    printf("Second dot is:\n");
    showDot2f(&second);
    return 0;
}

