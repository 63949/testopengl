#include <GL/glut.h>
#include <math.h>
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
    //glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f,0.0f);
    for(i=0;i<8;++i)
    {
        glColor3f(i&0x04,i&0x02,i&0x01);
        glVertex2f(cos(i*Pi/4),sin(i*Pi/4));
    }
    glEnd();
    glFlush();

}
