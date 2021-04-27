#include "dot.h"


void initDot2f(dot2f* dot, float x, float y) {
    dot->x = x;
    dot->y = y;
}

void showDot2f(dot2f* dot) {
    printf("x: %5.2f y: %5.2f\n", dot->x, dot->y);
}
