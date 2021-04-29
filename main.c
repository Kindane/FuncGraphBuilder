#include "functions.h"

int main()
{
    int choice;
    printf("Welcome to Function Graphic Builder.     \n");
    printf("What function do you want to draw?       \n");
    printf("1. Linear function: y = kx+b             \n");
    printf("2. Quadratic function: y = ax^2 + bx + c \n");
    printf("3. Fraction Linear function: y = k/x     \n");
    scanf("%d", &choice);
    enum funcType ftype;

    while (1) {
        switch (choice) {
        case Linear:
            ftype = Linear;
            break;
        case Quadratic:
            ftype = Quadratic;
            break;
        case FractionLinear:
            ftype = FractionLinear;
            break;
        default:
            printf("Please, enter a number from 1 to 3.\n");
            scanf("%d", &choice);
            continue;
        }
        break;
    }

    float firstParam, secondParam, thirdParam;

    switch (ftype) {
    case Linear:
        printf("Enter k: "); scanf("%f", &firstParam);
        printf("Enter b: "); scanf("%f", &secondParam);
        thirdParam = INFINITY;
        /* TODO ...*/
        break;
    case Quadratic:
        printf("Enter a: "); scanf("%f", &firstParam);
        printf("Enter b: "); scanf("%f", &secondParam);
        printf("Enter c: "); scanf("%f", &thirdParam);
        /* TODO ...*/

        break;
    case FractionLinear:
        printf("Enter x: ");
        scanf("%f", &firstParam);
        secondParam = INFINITY;
        thirdParam =  INFINITY;
        /* TODO ...*/
        break;
    }

    printf("[DEBUG]   params = %.2f %.2f %.2f", firstParam, secondParam, thirdParam);

    /* Call build.c with params. */

    return 0;
}
