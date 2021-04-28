#include "functions.h"


void initDot2f(dot2f* dot, float x, float y) {
    dot->x = x;
    dot->y = y;
}

void showDot2f(dot2f* dot) {
    printf("x: %5.2f y: %5.2f\n", dot->x, dot->y);
}

/*
 * LINEAR FUNCTION:
 * f(x) = kx + b
 */
void linearFunc(dot2f* buf, float k, float b) {
    dot2f resultArr[2];
    memset(resultArr, 0, 5);

    initDot2f(&resultArr[0], 0, 0*k+b);
    initDot2f(&resultArr[1], 1, 1*k+b);

    memcpy(buf, &resultArr, sizeof(dot2f)*2);
}

/*
 * Fractional Linear Function
 * y = k/x
 */
void fractionLinearFunc(dot2f* buf, float k) {
    if (k == 0) {
        fprintf(stderr, "k cannot be zero, now BUF = 0, return.\n");
        memset(buf, 0, 1);
        return;
    }
    dot2f resultArr[6];
    memset(resultArr, 0, 5);

    for (int i = 0, value = -3; i < 6; i++, value++) {
        if (value == 0) value++;
        initDot2f(&resultArr[i], value, k/value);
    }

    memcpy(buf, &resultArr, sizeof(dot2f)*6);
}

/*
 * QUADRATIC FUNCTION:
 * f(x) = ax^2 + bx + c
 */
void quadraticFunc(dot2f* buf, float a, float b, float c) {
    if (a == 0) {
        fprintf(stderr, "Error! param `a` cannot be ZERO, now BUF = 0, return.\n");
        memset(buf, 0, 1);
        return;
    }
    dot2f resultArr[7];
    float x0, y0;
    memset(resultArr, 0, 7);
    x0 = -b / (2 * a);
    y0 = a*pow(x0, 2) + b*x0 + c; /* y0 = a*x0^2 + b*x0 + c */
    initDot2f(&resultArr[0], x0, y0);

    /* finding a discriminant. D = b^2 - 4ac
     * x1 = (-b + sqrt(D)) / 2a
     * x2 = (-b - sqrt(D)) / 2a
     */
    float D = pow(b, 2) - (4*a*c); /* discriminant */
    if (D < 0) { /* if discriminant < 0 then there is no X */
        initDot2f(&resultArr[1], INFINITY, INFINITY);
        initDot2f(&resultArr[2], INFINITY, INFINITY);
    }
    else if (D == 0) { /* if discriminant=0 then there is only one X */
        initDot2f(&resultArr[1], -b / 2*a, 0);
        initDot2f(&resultArr[2], INFINITY, 0);
    }
    else {
        initDot2f(&resultArr[1], (-b - sqrt(D)) / 2*a, 0);
        initDot2f(&resultArr[2], (-b + sqrt(D)) / 2*a, 0);
    }

    for (int i = 3, index = -2; i < 7; i++, index++) {
        float value = x0+index;
        if (value == x0) { value++; index++;}
        initDot2f(&resultArr[i], value, a*pow(value, 2) + b*value + c); 
    }

    memcpy(buf, &resultArr, sizeof(dot2f)*7);

}
