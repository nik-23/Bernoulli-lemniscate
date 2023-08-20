/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

//

#ifdef _APPLE_
#include <GL/glut.h>
#else


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#endif
#include <stdlib.h>
#include <math.h>
#define pi 3.141592
#define n 5000


double X[n], Y[n];
float xymin = -6.5,xymax = 6.5;

void fill_dots_coords()
{
    float a = 1.0;
    float b = 1.0;
    float t, dt = 0.02;
    int i;

    for (i = 0, t = -pi; i < n; i++, t += dt) {
        X[i] = 2*a * sqrt(2.0) * cos(t) / (pow(sin(t), 2) +1);
        Y[i] = 2*b * sqrt(2.0) * cos(t) * sin(t) / (pow(sin(t), 2) +1);

    }
}

void words(char* str, int x, int y,float pos, GLfloat red, GLfloat green, GLfloat blue)
{
    glColor3f(red, green, blue);
    glRasterPos2f(x, y);
    int i = 0;
    while (str[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
        i++;
        glRasterPos2f(x + i*pos, y);

    }
}

void cordx_scaleout(char* str, float x, float y, float pos, GLfloat red, GLfloat green, GLfloat blue)
{
    glColor3f(red, green, blue);
    glRasterPos2f(x, y);
    int i = 0;
    while (str[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
        i++;
        glRasterPos2f(x + i * pos, y);

    }
}

void cordy_scaleout(char* str, float x, float y, float pos, GLfloat red, GLfloat green, GLfloat blue)
{
    glColor3f(red, green, blue);
    glRasterPos2f(x, y);
    int i = 0;
    while (str[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
        i++;
        glRasterPos2f(x, y + i * pos);

    }
}
void render(int key, int x, int y)
{

    if (key == GLUT_KEY_UP)
    {
        glScalef(1.05, 1.05, 0);
    }

    else if (key == GLUT_KEY_DOWN)
    {
        glScalef(0.95, 0.95, 0);
    }

    glutPostRedisplay();

}

void out_axes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    glColor3f(2.0, 2.0, 2.0);

    glVertex3f(0, xymax, 0);
    glVertex3f(0, xymin, 0);

    glVertex3f(0, xymax, 0);
    glVertex3f(0.25, xymax - 0.25, 0);
    glVertex3f(0, xymax, 0);
    glVertex3f(-0.25, xymax - 0.25, 0);

    glVertex3f(xymin, 0, 0);
    glVertex3f(xymax, 0, 0);

    glVertex3f(xymax, 0, 0);
    glVertex3f(xymax - 0.25, 0.25, 0);
    glVertex3f(xymax, 0, 0);
    glVertex3f(xymax - 0.25, -0.25, 0);

    for (float i = xymin; i < xymax; i += 0.5)
    {
        glVertex3f(i, -0.15, 0);
        glVertex3f(i, 0.15, 0);
    }

    for (float i = xymin; i < xymax; i += 0.5)
    {
        glVertex3f(-0.15, i, 0);
        glVertex3f(0.15, i, 0);
    }

    glEnd();
}
void out_graphic()
{
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < n - 1; i++)
        {
        if (X[i] < xymin || X[i] > xymax)
        {
            glEnd();
            glBegin(GL_LINE_STRIP);
        }
        glVertex3f(X[i], Y[i], 0);
    }
    glEnd();
}

void display()
{
    out_axes();
    out_graphic();

    char last_name[] = { "VAVRENIYK MYKYTA" };
    char formula[] = { "2*a*sqrt(2.0)*cos(t)/(pow(sin(t),2)+1)" };
    char x[] = { "x" }, y[] = { "y" };
    char cord1[] = { "1 2 3 4 5 6" };
    char cord2[] = { "6 5 4 3 2 1" };
    char cord[] = { "- - - - - -" };
    words(x, xymax, -1.5, 1, 1.0, 7.0, 3.0);
    words(y, 1.5, xymax, 1, 1.0, 7.0, 3.0);
    words(last_name, 2.5, -9, 0.5, 0, 7.0, 0);
    words(formula, 2.5, -10, 0.3, 2.0, 2.0, 2.0);
    cordx_scaleout(cord1, 0.8, 1, 0.5, 1.0, 1.0, 1.0);
    cordx_scaleout(cord2, -6.0, -1.5, 0.5, 1.0, 1.0, 1.0);
    cordx_scaleout(cord, -6.3, -1.5, 0.5, 1.0, 1.0, 1.0);
    cordy_scaleout(cord1, 1, -1.2, -0.5, 1.0, 1.0, 1.0);
    cordy_scaleout(cord2,  -1, 5.8, -0.5, 1.0, 1.0, 1.0);
    cordy_scaleout(cord, 0.70, -1.2, -0.5, 1.0, 1.0, 1.0);
    glutSwapBuffers();
}
int main(int argc, char* argv[])
{
 int l = 0.15;
    fill_dots_coords();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("KV-23 VAVRENIYK");
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15, 15, -15, 15, -100, 100);
    glutDisplayFunc(display);
    glutSpecialFunc(render);
    glutMainLoop();
    return 0;
}
