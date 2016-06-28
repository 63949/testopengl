#include <GL/glut.h>
#include <math.h>
const int n=3;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;

void init();
void display();
int main(int argc, char* argv[])
{
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
      glutInitWindowPosition(0, 0);
      glutInitWindowSize(300, 300);
      glutCreateWindow("OpenGL 3D View");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
void init()
{
      glClearColor(0.0, 0.0, 0.0, 0.0);
      glMatrixMode(GL_PROJECTION);
      glOrtho(-5, 5, -5, 5, 5, 15);
      glMatrixMode(GL_MODELVIEW);
      gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}
void display()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POINTS);
 //   glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(i=0;i<n;i++)
    {
        glVertex2f(R*cos(2*Pi/n*i),R*sin(2*Pi/n*i));

    }
    glEnd();
    glFlush();

}
