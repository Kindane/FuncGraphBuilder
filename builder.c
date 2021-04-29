/* author: Kindane
 * gcc -v: 10.2.0
 */
#include <stdio.h>
#include <GL/glut.h>
#include "functions.h"

void init();
void drawFunction(dot2f* function, size_t dotCount);

static const float size_of_square = 0.05;
static dot2f* buffer = NULL;
static size_t sizeOfBuff = 0;

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Not enough arguments.\n");
        printf("Example: ./builder <FType: int> <param1: float> <param2: float> <param3: float>\n");
        exit(1);
    }

    int functionType;
    float param1, param2, param3;
    functionType = atoi(argv[1]);
    param1 = atof(argv[2]);
    param2 = atof(argv[3]);
    param3 = atof(argv[4]);

    switch (functionType) {
    case Linear:
        buffer = (dot2f*)malloc(sizeof(dot2f)*2);
        sizeOfBuff = 2;
        linearFunc(buffer, param1, param2);
        break;
    case Quadratic:
        buffer = (dot2f*)malloc(sizeof(dot2f)*7);
        sizeOfBuff = 7;
        quadraticFunc(buffer, param1, param2, param3);
        break;
    case FractionLinear:
        buffer = (dot2f*)malloc(sizeof(dot2f)*6);
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

void drawFunction(dot2f* function, size_t dotCount) {
    glLineWidth(3);
    glColor3f(1,0,0);
    glBegin(GL_LINES);

    for (size_t i = 0; i < dotCount; i++) {
        if (isinf(function[i].x)) {continue;}
        glVertex2f(function[i].x*size_of_square, function[i].y*size_of_square);
    }
    

    glEnd();
    glFlush();
}

void init()
{
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
    drawFunction(buffer, sizeOfBuff);
}
