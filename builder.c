/* author: Kindane
 * gcc -v: 10.2.0
 */
#include <stdio.h>
#include <GL/glut.h>
// TODO REFACTOR ALL CODE!!

void init();

static const float size_of_square = 0.05;

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glEnable(GL_DEBUG_CALLBACK_FUNCTION);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Function Graphic Builder");
    glutDisplayFunc(init);
    glutMainLoop();
    return 0;
}

void init() {
    /* BEGIN OF THE NORMAL */
    glClear(GL_COLOR_BUFFER_BIT); /* clear color */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* bg color: can be from 0.0f to 1.0f */

    glLineWidth(1);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    /* horizontal lines */
    int counter;
    for (float i = 1; i >= -2; i -= size_of_square, counter++) {
        /* abscissa */
        if (counter == 20) {
            glEnd();
            glFlush();
            glLineWidth(5);
            glBegin(GL_LINES);
            glEnable(GL_LINE_WIDTH);
            glLineWidth(10);
            glVertex2f(-1, i);
            glVertex2f(1, i);
            glLineWidth(1);
            glEnd();
            glFlush();
            glLineWidth(1);
            glBegin(GL_LINES);
            glEnable(GL_LINE_WIDTH);
            continue;
        }
        glVertex2f(-1, i);
        glVertex2f(1, i);
    }
    counter = 0;
    /* ordinate */
    /* vertical lines */
    for (float i = 1; i >= -2; i-= size_of_square, counter++) {
        if (counter == 20) {
            glEnd();
            glFlush();
            glLineWidth(5);
            glBegin(GL_LINES);
            glEnable(GL_LINE_WIDTH);
            glLineWidth(10);
            glVertex2f(i, -1);
            glVertex2f(i, 1);
            glLineWidth(1);
            glEnd();
            glFlush();
            glLineWidth(1);
            glBegin(GL_LINES);
            glEnable(GL_LINE_WIDTH);
            continue;
        }
        glVertex2f(i, -1);
        glVertex2f(i, 1);
    }

    glEnd();
    glFlush();
    /* END OF THE NORMAL */
}
