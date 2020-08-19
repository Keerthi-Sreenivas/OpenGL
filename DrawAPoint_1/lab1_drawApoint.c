#include <GL/gl.h>//open  gl API header file
#include <GL/glu.h> //already included in the glut library ,utility library
#include <GL/glut.h> //utility toolkit provides functions to interact with the code in api

void init();
void display();
void reShape(int w,int h);



void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //default frame buffer is passed as an argument
    glLoadIdentity(); //resets co-ordinate system

    glPointSize(10.0); //size of the points is set to 10 pixels

    //drawing here
    glBegin(GL_POINTS); //to draw points we pass argument GL_POINTS

    glVertex2f(5,5); //first point

    glVertex2f(-2,3); //second point

    glVertex2f(-6.3,7.2); //third point

    glVertex2f(3,-4.2); //fourth point

    glEnd();

    glFlush();
}

void reShape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);//setting view port
    glMatrixMode(GL_PROJECTION);// setting projection
    glLoadIdentity();//resets projection matrix
    gluOrtho2D(-10,10,-10,10);//initiating a 2D projection
    glMatrixMode(GL_MODELVIEW);
}




int main(int argc, char**argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB);

   glutInitWindowPosition(200,100);
   glutInitWindowSize(500,500);

   glutCreateWindow("Window 1");

   glutDisplayFunc(display);
   glutReshapeFunc(reShape);
   init();

   glutMainLoop();
}




