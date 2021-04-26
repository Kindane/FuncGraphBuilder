#include "dot.h"

/*
 * QUADRATIC FUNCTION:
 * f(x) = ax^2 + bx + c
 * https://math-prosto.ru/?page=pages/quadratic_function/quadratic_function_how_to_draw_parabola.php
 */

int main() {
    float a, b, c, x0, y0;
    dot2f fstart;
    dot2f* helpDotsArr = (dot2f*)malloc(4*sizeof(dot2f*));
    printf("Quadratic function: ax^2 + bx + c.\n");
    printf("Enter a: "); scanf("%f", &a);
    if (a == 0) {
        fprintf(stderr, "Error! param `a` cannot be ZERO.\n");
        exit(1);
    }
    printf("Enter b: "); scanf("%f", &b);
    printf("Enter c: "); scanf("%f", &c);
    x0 = -b / (2 * a);
    y0 = a*pow(x0, 2) + b*x0 + c; /* y0 = a*x0^2 + b*x0 + c */
    initDot2f(&fstart, x0, y0);
    printf("BEGIN OF THE FUNCTION: "); showDot2f(&fstart);

    /* finding a discriminant. D = b^2 - 4ac
     * x1 = (-b + sqrt(D)) / 2a
     * x2 = (-b - sqrt(D)) / 2a
     */
    float D = pow(b, 2) - (4*a*c); /* discriminant */
    dot2f nullDot1, nullDot2;
    if (D < 0) { /* if discriminant < 0 then there is no X */
        printf("i cannot find a nulls of function\n");
        initDot2f(&nullDot1, INFINITY, 0);
        initDot2f(&nullDot2, INFINITY, 0);
    }
    else if (D == 0) { /* if discriminant=0 then there is only one X */
        initDot2f(&nullDot1, -b / 2*a, 0);
        initDot2f(&nullDot2, INFINITY, 0);
    }
    else {
        initDot2f(&nullDot1, (-b - sqrt(D)) / 2*a, 0);
        initDot2f(&nullDot2, (-b + sqrt(D)) / 2*a, 0);
    }
    printf("null dot1: "); showDot2f(&nullDot1);
    printf("null dot2: "); showDot2f(&nullDot2);
    for (int i = 0, index = -2; i < 4; i++, index++) {
        float val = x0+index;
        if (val == x0) { val++; index++;}
        initDot2f(&helpDotsArr[i], val, a*pow(val, 2) + b*val + c); /* X: x0-2, Y: ? */
    }


    for (int i = 0; i < 4; i++) {
        showDot2f(&helpDotsArr[i]);
    }

    free(helpDotsArr);
    return 0;
}

