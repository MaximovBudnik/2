#include <stdlib.h>
#include <GL/glut.h>

void resize(int w, int h)
{
        glViewport(0, 0, w, h);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void show(int argc, char * argv[])
{
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(0, 1000);
        glVertex2i(0, 0);
        glVertex2i(1000, 0);
        glVertex2i(1920, 1080);
        glEnd();

        for (int i=0;i<10;i++)
        {
            glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2i(150, 450-(25*i));
		glVertex2i(750, 450-(25*i));
		glEnd();
        }


        glutSwapBuffers();
}

int main (int argc, char * argv[])
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

        glutInitWindowSize((atoi(argv[1])), atoi(argv[2]));
        glutCreateWindow("OpenGL lines");

        glutReshapeFunc(resize);
        glutDisplayFunc(show);

        glutMainLoop();

        return 0;
}
