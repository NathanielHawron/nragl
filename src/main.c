#include <stdio.h>
#include <emscripten/emscripten.h>

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}
void idle() {
  glutPostRedisplay();
}

int main(int argc, char ** argv) {
    printf("Hello World\n");

    glutInit(& argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("NRAGL");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
    glutMainLoop();

    return 0;
}

extern EMSCRIPTEN_KEEPALIVE void myFunction(int argc, char ** argv) {
    printf("MyFunction Called\n");
}