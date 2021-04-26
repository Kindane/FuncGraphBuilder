#ifndef _DOT_H_
#define _DOT_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct {
    float x, y;
} dot2f;

void initDot2f(dot2f* dot, float x, float y);

void showDot2f(dot2f* dot);

#endif //_DOT_H_ 1
