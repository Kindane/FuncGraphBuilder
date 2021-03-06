#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    float x, y;
} dot2f;

typedef enum funcType {
    Linear = 1,
    Quadratic = 2,
    FractionLinear = 3
} funcType_t;

void initDot2f(dot2f* dot, float x, float y);

void showDot2f(dot2f* dot);

/*
 * f(x) = kx + b
 * returns array with array[0] as first point
 * and array[1] as second point
 */
void linearFunc(dot2f* buf, float k, float b);

/*
 * QUADRATIC FUNCTION:
 * f(x) = ax^2 + bx + c
 * https://math-prosto.ru/?page=pages/quadratic_function/quadratic_function_how_to_draw_parabola.php
 * if (a == 0) sets BUF to NULL and return;
 * returns array with array[0] as init dot,
 * array[1] and array[2] is a NULL-dots (x=0;y=something),
 * if func has only 1 NULL-dot or do not have NULL-dots
 * array[1].x = INFINITY and array[2].x = INFINITY (Y too)
 * array[3]...array[7] is a function dots, a-ka (x=-1;y=4)
 */
void quadraticFunc(dot2f* buf, float a, float b, float c);

/*
 * Fractional Linear Function
 * f(x) = k/x
 * https://encyclopedia2.thefreedictionary.com/Linear+Fractional+Function
 * if (k == 0) sets BUF to NULL and return;
 * returns array with array[0]...array[2] is a first arc
 * and array[3]...array[5] is a second arc
 */
void fractionLinearFunc(dot2f* buf, float k);


#endif // _FUNCTIONS_H
