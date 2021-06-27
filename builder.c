/* author: Kindane
 * gcc -v: 10.2.0
 */


#include <stdio.h>
#include <GL/glut.h>
#include "functions.h"

#define NORMALIZE_VAL(val) ((val) * (size_of_square))

void init();
void drawQuadratic(dot2f* function);
void drawLinear(dot2f* function);
void drawFractionLinear(dot2f* function);
void initDraw();

static const float size_of_square = 0.05;
static dot2f* buffer = NULL;
funcType_t functionType;

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Not enough arguments.\n");
        printf("Example: ./builder <FType: int> <param1: float> <param2: float> <param3: float>\n");
        exit(EXIT_FAILURE);
    }

    float param1, param2, param3;
    int dotsCount = 0;
    functionType = atoi(argv[1]);
    param1 = atof(argv[2]);
    param2 = atof(argv[3]);
    param3 = atof(argv[4]);

    switch (functionType) {
    case Linear:
        dotsCount = 2;
        buffer = calloc(sizeof(dot2f), dotsCount);
        linearFunc(buffer, param1, param2);
        break;
    case Quadratic:
        dotsCount = 7;
        buffer = calloc(sizeof(dot2f), dotsCount);
        quadraticFunc(buffer, param1, param2, param3);
        break;
    case FractionLinear:
        dotsCount = 6;
        buffer = calloc(sizeof(dot2f), dotsCount);
        fractionLinearFunc(buffer, param1);
        break;
    default:
        printf("Unknown type of function. Abort.\n");
        exit(1);
        break;
    }


    for (int i = 0; i < dotsCount; i++) {
        printf("%d - ", i+1);
        showDot2f(&buffer[i]);
    }


    /* init main window */
    glutInit(&argc, argv);
    glEnable(GL_DEBUG_CALLBACK_FUNCTION);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Function Graphic Builder");
    glutDisplayFunc(init);

    glutMainLoop(); 
    free(buffer);
    return 0;
}

void initDraw() {
    glLineWidth(4);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
}

void drawQuadratic(dot2f *function) {
    float x01, x02; /* first and second X0's */
    dot2f startDot, firstDot, secondDot, thirdDot, fourthDot;
    startDot = function[0];
    firstDot = function[3];
    secondDot = function[4];
    thirdDot = function[5];
    fourthDot = function[6];

    startDot.x *= size_of_square;
    startDot.y *= size_of_square;
    firstDot.x *= size_of_square;
    firstDot.y *= size_of_square;
    secondDot.x *= size_of_square;
    secondDot.y *= size_of_square;
    thirdDot.x *= size_of_square;
    thirdDot.y *= size_of_square;
    fourthDot.x *= size_of_square;
    fourthDot.y *= size_of_square;

    x01 = function[1].x;
    x02 = function[2].x;
    if (!isinf(x01))
        x01 *= size_of_square;
    if (!isinf(x02))
        x02 *= size_of_square;

    glVertex2f(firstDot.x, firstDot.y);
    if (secondDot.y < 0 && !isinf(x01)) {
        glVertex2f(secondDot.x, secondDot.y);
        glVertex2f(x01, 0); /* end of past */
        glVertex2f(x01, 0); /* start of new */
    }
    else {
        glVertex2f(secondDot.x, secondDot.y);
    }
    glVertex2f(secondDot.x, secondDot.y); /* connect last point to init dot */
    glVertex2f(startDot.x, startDot.y); /* connect last point to init dot */

    glVertex2f(startDot.x, startDot.y);
    glVertex2f(thirdDot.x, thirdDot.y);
    glVertex2f(thirdDot.x, thirdDot.y);

    if (fourthDot.y < 0 && !isinf(x02)) {
        glVertex2f(x02, 0); /* end of past */
        glVertex2f(x02, 0); /* start of new */
        glVertex2f(fourthDot.x, fourthDot.y);
    }
    else {
        glVertex2f(fourthDot.x, fourthDot.y);
    }
}

void drawLinear(dot2f *function) {
    for (size_t i = 0; i < 2; i++)
        glVertex2f(NORMALIZE_VAL(function[i].x), NORMALIZE_VAL(function[i].y));
}

void drawFractionLinear(dot2f *function) {
    glVertex2f(NORMALIZE_VAL(function[0].x), NORMALIZE_VAL(function[0].y));
    glVertex2f(NORMALIZE_VAL(function[1].x), NORMALIZE_VAL(function[1].y));
    glVertex2f(NORMALIZE_VAL(function[1].x), NORMALIZE_VAL(function[1].y));
    glVertex2f(NORMALIZE_VAL(function[2].x), NORMALIZE_VAL(function[2].y));
    glVertex2f(NORMALIZE_VAL(function[3].x), NORMALIZE_VAL(function[3].y));
    glVertex2f(NORMALIZE_VAL(function[4].x), NORMALIZE_VAL(function[4].y));
    glVertex2f(NORMALIZE_VAL(function[4].x), NORMALIZE_VAL(function[4].y));
    glVertex2f(NORMALIZE_VAL(function[5].x), NORMALIZE_VAL(function[5].y));
}

void init() {
    glClear(GL_COLOR_BUFFER_BIT);         /* clear color */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* bg color: can be from 0.0f to 1.0f */

    glLineWidth(1);           /* line width = 1 */
    glColor3f(0.0, 0.0, 0.0); /* Line color: black */
    glBegin(GL_LINES);        /* Start draw! */

    int counter = 0;
    for (float i = 1; i >= -2; i -= size_of_square, counter++) {
        if (counter == 20) { /* Draw X and Y lines */
            glEnd();
            glFlush();
            glLineWidth(5);
            glBegin(GL_LINES);

            glVertex2f(i, -1); /* X */
            glVertex2f(i, 1);  /* X */
            glVertex2f(-1, i); /* Y */
            glVertex2f(1, i);  /* Y */

            glEnd();
            glFlush();
            glLineWidth(1);
            glBegin(GL_LINES);
            continue;
        }
        glVertex2f(i, -1);
        glVertex2f(i, 1);
        glVertex2f(-1, i);
        glVertex2f(1, i);
    }

    glEnd();
    glFlush();
    initDraw();
    switch (functionType) {
    case Linear:
        drawLinear(buffer);
        break;
    case Quadratic:
        drawQuadratic(buffer);
        break;
    case FractionLinear:
        drawFractionLinear(buffer);
    }
    glEnd();
    glFlush();
}
