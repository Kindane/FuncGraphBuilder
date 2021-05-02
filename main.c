#include "functions.h"

int main() {
    int choice;
    funcType_t ftype;
    printf("      Welcome to Function Graphic Builder.      \n");
    printf("What function do you want to draw?              \n");
    printf("1. Linear function:           y = kx + b        \n");
    printf("2. Quadratic function:        y = ax^2 + bx + c \n");
    printf("3. Fraction Linear function:  y = k/x           \n");
    scanf("%d", &choice);

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
        break;
    case Quadratic:
        printf("Enter a: "); scanf("%f", &firstParam);
        printf("Enter b: "); scanf("%f", &secondParam);
        printf("Enter c: "); scanf("%f", &thirdParam);
        break;
    case FractionLinear:
        printf("Enter x: ");
        scanf("%f", &firstParam);
        secondParam = INFINITY;
        thirdParam =  INFINITY;
        break;
    }

    char* command = (char*)malloc(128*sizeof(char));
    sprintf(command,
        "gcc ../builder.c ../functions.c -o program -g -lglut -lGLU -lGL -lm; ./program %d %f %f %f;",
        ftype, firstParam, secondParam, thirdParam); /* i removed `rm program` statemant because i don't want to compile program every time */

    printf("Please, wait, this might take several seconds...\n");
    //fflush(stdout);
    system(command);

    free(command);
    return 0;
}
