/* author: Kindane
 * gcc -v: 10.2.0
 */
#include <stdio.h>
#include <GL/glut.h>
// ~~TODO REFACTOR ALL CODE!!~~ DONE

void init();

static const float size_of_square = 0.05;

int main(int argc, char* argv[]) {
    /* init main window */
    glutInit(&argc, argv);
    glEnable(GL_DEBUG_CALLBACK_FUNCTION);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Function Graphic Builder");
    glutDisplayFunc(init);

    glutMainLoop(); /* this is like a `return`, after this line code does now work */
    return 0;
}



void init() {
    glClear(GL_COLOR_BUFFER_BIT); /* clear color */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); /* bg color: can be from 0.0f to 1.0f */

    glLineWidth(1); /* line with = 1 */
    glColor3f(0.0, 0.0, 0.0); /* Line color: black */
    glBegin(GL_LINES); /* Start draw! */

    int counter = 0;
    for (float i = 1; i >= -2; i-= size_of_square, counter++) {
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
}
