#include<GL/glut.h>
#include<math.h>

 GLfloat x1, x2, thisprogisboring, y2, x3, y3;
 GLfloat x_Src, y_Src, x_Dest, y_Dest;

//used to change colour (To be implemented)
static int colour;

void MainMenu(int);

void display(void)
{
glClearColor(0.0, 2.0, 1.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);

glPointSize(3.0);
glColor3f(1.0, 0.0, 0.0);

//Rectangle vertices
glBegin(GL_POLYGON);
glVertex2f(x1, thisprogisboring);
glVertex2f(x1, y2);
glVertex2f(x2, y2);
glVertex2f(x2, thisprogisboring);
glEnd();

//Line vertices
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINES);
glVertex2f(x_Src, y_Src);
glVertex2f(x_Dest, y_Dest);
glEnd();

//Triangle Vertices
glBegin(GL_TRIANGLES);

glVertex2f(x1, thisprogisboring);
glVertex2f(x1, y2);
glVertex2f(x2, y2);
glEnd();

glFlush();
return;
}

void MyRect(GLint button, GLint state, GLint x, GLint y)
{
static int first = 1;

if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{
if (first)
{
//first point in terms of window size
x1 = (x - 250.0) / 250.0;
thisprogisboring = -(y - 250) / 250.0;;
}
else
{
//second point in terms of window size
x2 = (x - 250.0) / 250.0;
y2 = -(y - 250) / 250.0;
glutPostRedisplay();
}
first = !first;
}

return; // tvkk524@gmail.com
}

void MyCircle(GLint button, GLint state, GLint x, GLint y)
{
static int first = 1;

if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{

glClear(GL_COLOR_BUFFER_BIT);
//glColor3f(1.0, 1.0, 1.0);

glBegin(GL_QUADS);
//glColor3f(0.0, 0.0, 0.0);

glVertex3f(0.1, 0.1, 0.0);
glVertex3f(0.9, 0.1, 0.0);
glVertex3f(0.9, 0.9, 0.0);
glVertex3f(0.1, 0.9, 0.0);

glEnd();
float a1, b1, a2, b2;
float angle;
double radius = 0.6;

a1 = 0, b1 = -0.1;
//glColor3f(1.0, 1.0, 0.6);

glBegin(GL_TRIANGLE_FAN);
glVertex2f(a1, b1);

for (angle = 1.0f; angle < 360.0f; angle += 0.1)
{
a2 = a1 + sin(angle)*radius;
b2 = b1 + cos(angle)*radius;
glVertex2f(a2, b2);
}

glEnd();

glFlush();

}

}


void MyLine(GLint button, GLint state, GLint x, GLint y)
{
static int first = 1;

if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{
if (first)
{
x_Src = (x - 250.0) / 250.0;
y_Src = -(y - 250) / 250.0;

}
else
{
x_Dest = (x - 250.0) / 250.0;
y_Dest = -(y - 250) / 250.0;
glutPostRedisplay();
}
first = !first;
}
return;
}
void MyTraingle(GLint button, GLint state, GLint x, GLint y)
{
static int first = 1;

if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
{
if (first)
{
//first point in terms of window size
x1 = (x - 100.0) / 100.0;
thisprogisboring = -(y - 100.0) / 100.0;;

}
else
{
//second point in terms of window size
x2 = (x - 100.0) / 100.0;
y2 = -(y - 100.0) / 100.0;
glutPostRedisplay();
}
first = !first;
}

return;
}




void MainMenu(int item)
{
//Remove motion function if exists and go to rectangle function
//prevents two functions running at once
if (item == 1)
{
glutMotionFunc(NULL);
glutMouseFunc(MyRect);
}
else if (item == 2)
{
glutMotionFunc(NULL);
glutMouseFunc(MyLine);
}
else if (item == 3)
{
glutMotionFunc(NULL);
glutMouseFunc(MyCircle);
}


/*
else if (item == 4)
{
glutMotionFunc(NULL);
glutMouseFunc(MyPolygon);
}*/
glutPostRedisplay();
return;
}


int main(int argc, char **argv)
{

glutInit(&argc, argv);
glutInitWindowSize(500, 500);
glutInitWindowPosition(500, 200);
glutCreateWindow("Draw Shapes");
glutDisplayFunc(display);

glutCreateMenu(MainMenu);
glutAddMenuEntry("Rectangle", 1);
glutAddMenuEntry("Line", 2);
glutAddMenuEntry("Circe", 3);
//glutAddMenuEntry("Polygon", 4);

glutAttachMenu(GLUT_RIGHT_BUTTON);

glutMainLoop();
}