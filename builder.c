/* author: Kindane
 * gcc -v: 10.2.0
 */

/*
* TODO: REFACTOR THIS F*CKING SHIT! OH MY EYES THIS HORRIBLE!! 
*/

#include <stdio.h>
#include <GL/glut.h>
#include "functions.h"

void init();
void drawQuadratic(dot2f *function);
void drawLinear(dot2f *function);
void drawFractionLinear(dot2f *function);
void initDraw();

static const float size_of_square = 0.05;
static dot2f *buffer = NULL;
static size_t sizeOfBuff = 0;
funcType_t functionType;

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Not enough arguments.\n");
        printf("Example: ./builder <FType: int> <param1: float> <param2: float> <param3: float>\n");
        exit(1);
    }

    float param1, param2, param3;
    functionType = atoi(argv[1]);
    param1 = atof(argv[2]);
    param2 = atof(argv[3]);
    param3 = atof(argv[4]);

    switch (functionType) {
    case Linear:
        buffer = (dot2f *)malloc(sizeof(dot2f) * 2);
        sizeOfBuff = 2;
        linearFunc(buffer, param1, param2);
        break;
    case Quadratic:
        buffer = (dot2f *)malloc(sizeof(dot2f) * 7);
        sizeOfBuff = 7;
        quadraticFunc(buffer, param1, param2, param3);
        break;
    case FractionLinear:
        buffer = (dot2f *)malloc(sizeof(dot2f) * 6);
        sizeOfBuff = 6;
        fractionLinearFunc(buffer, param1);
        break;
    default:
        printf("Unknown type of function. Abort.\n");
        exit(1);
        break;
    }

    /* init main window */
    glutInit(&argc, argv);
    glEnable(GL_DEBUG_CALLBACK_FUNCTION);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Function Graphic Builder");
    glutDisplayFunc(init);

    glutMainLoop(); /* this is like a `return`, after this line code does now work */
    free(buffer);
    return 0;
}

void initDraw() {
    glLineWidth(4);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
}

void drawQuadratic(dot2f *function) {
    float x01, x02;
    /* OH MY GOD.. */
    x01 = function[1].x;
    x02 = function[2].x;
    if (!isinf(x01)) { x01 *= size_of_square; }
    if (!isinf(x02)) { x02 *= size_of_square; }

    glVertex2f(function[3].x * size_of_square, function[3].y * size_of_square);
    if (function[4].y * size_of_square > 0 && !isinf(x01)) {
        glVertex2f(function[4].x * size_of_square, function[4].y * size_of_square);
        glVertex2f(x01, 0); /* end of past */
        glVertex2f(x01, 0); /* start of new */
    }
    else {
        glVertex2f(function[4].x * size_of_square, function[4].y * size_of_square);
    }
    glVertex2f(function[4].x * size_of_square, function[4].y * size_of_square); /* connect last point to init dot */
    glVertex2f(function[0].x * size_of_square, function[0].y * size_of_square); /* connect last point to init dot */

    glVertex2f(function[0].x * size_of_square, function[0].y * size_of_square);
    glVertex2f(function[5].x * size_of_square, function[5].y * size_of_square);
    glVertex2f(function[5].x * size_of_square, function[5].y * size_of_square);

    if (function[6].y * size_of_square > 0 && !isinf(x02)) {
        glVertex2f(x02, 0); /* end of past */
        glVertex2f(x02, 0); /* start of new */
        glVertex2f(function[6].x * size_of_square, function[6].y * size_of_square);
    }
    else {
        glVertex2f(function[6].x * size_of_square, function[6].y * size_of_square);
    }
}
void drawLinear(dot2f *function) {
    for (size_t i = 0; i < 2; i++)
        glVertex2f(function[i].x * size_of_square, function[i].y * size_of_square);
}
void drawFractionLinear(dot2f *function) {
    /* Pizdec nahoi blyat.. */
    glVertex2f(function[0].x * size_of_square, function[0].y * size_of_square);
    glVertex2f(function[1].x * size_of_square, function[1].y * size_of_square);
    glVertex2f(function[1].x * size_of_square, function[1].y * size_of_square);
    glVertex2f(function[2].x * size_of_square, function[2].y * size_of_square);
    glVertex2f(function[3].x * size_of_square, function[3].y * size_of_square);
    glVertex2f(function[4].x * size_of_square, function[4].y * size_of_square);
    glVertex2f(function[4].x * size_of_square, function[4].y * size_of_square);
    glVertex2f(function[5].x * size_of_square, function[5].y * size_of_square);
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
