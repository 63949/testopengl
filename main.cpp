#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
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
      static GLubyte Mask[128];
      FILE *fp;
      fp = fopen("/home/lpz/testopengl/test.bmp","rb");
      if(!fp)
      {
          printf("file not exit.\n");
          exit(0);
      }
      if(fseek(fp,-(int)sizeof(Mask),SEEK_END))
          exit(0);
      if(!fread(Mask,sizeof(Mask),1,fp))
          exit(0);
      fclose(fp);

      glClear(GL_COLOR_BUFFER_BIT);
      glEnable(GL_POLYGON_STIPPLE);
      glPolygonStipple(Mask);
      glRectf(-0.5f,-1.5f,0.0f,0.0f);
      glDisable(GL_POLYGON_STIPPLE);
      glRectf(0.0f,0.0f,0.5f,0.5f);
      glFlush();
      //glColor3f(1.0, 0, 0);
     /* glPolygonMode(GL_FRONT,GL_FILL);
      glPolygonMode(GL_BACK,GL_LINE);
      glFrontFace(GL_CCW);
*/
      //glBegin(GL_LINES);
/*      glBegin(GL_POLYGON);
      glVertex2f(-0.5f,-0.5f);
      glVertex2f(0.0f,-0.5f);
      glVertex2f(0.0f,0.0f);
      glVertex2f(-0.5f,0.0f);
 */     /*glVertex2f(0.0f,0.0f);
      glVertex2f(10.5f,0.5f);
*/
  //    glEnd();
//      glutWireTeapot(3);
   /*   glBegin(GL_POLYGON);
      glVertex2f(0.0f,0.0f);
      glVertex2f(0.0f,0.5f);
      glVertex2f(0.5f,0.5f);
      glVertex2f(0.5f,0.0f);
      glEnd();
      glFlush();*/
}
