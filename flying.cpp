
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <glut.h>
static double x=0.0;
static double inc=0.0;
void
stroke_output(GLfloat x, GLfloat y, char *format,...)
{
va_list args;
char buffer[200], *p;
va_start(args, format);
vsprintf(buffer, format, args);
va_end(args);
Flying Ball
10 Dept. of Computer Science & Engineering.
glPushMatrix();
glTranslatef(-2.5, y, 0);
glScaled(0.003, 0.005, 0.005);
for (p = buffer; *p; p++)
 glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
glPopMatrix();
}
//changing backgroun color
 // Table Fan
void fan(double ang)
 { glClearColor(0.8,0.8,0.8,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
 glTranslatef(0.0f,0.0f,-13.0f);
 glRotatef(180,0.0f,1.0f,0.0f);
//fan Blades
glPushMatrix();
glRotatef(ang,0.0f,0.0f,1.0f);
glScaled(0.9,0.2,0.1);
Flying Ball
11 Dept. of Computer Science & Engineering.
glTranslatef(0.0,0.0,0.0);
glRotatef(ang,0.0f,0.0f,1.0f);
glutSolidSphere(0.7,20,60);
glPopMatrix();
glScaled(0.8,0.04,0.8);
glTranslatef(0.0,-40.2,0.0);
glutSolidCube(6.0);
glPopMatrix();
// leg 1
glPushMatrix();
glScaled(0.04,0.4,0.04);
glTranslatef(0.0,-40.2,0.0);
glutSolidCube(6.0);
glPopMatrix();
//fan cover
glPushMatrix();
glScaled(0.8,1.0,0.2);
glTranslatef(0.0,0.0,0.0);
glutWireSphere(0.9,20,60);
Flying Ball
12 Dept. of Computer Science & Engineering.
glPopMatrix();
glPushMatrix();
glScaled(0.8,0.18,0.8);
glTranslatef(0.0,-7.2,0.0);
glutSolidCube(0.7);
glPopMatrix();
//Fan motor
glPushMatrix();
glScaled(0.35,0.4,0.5);
glTranslatef(0.0,0.0,0.5);
glutSolidSphere(0.5,20,60);
glPopMatrix();
//
glFlush();
glutSwapBuffers();
}
Flying Ball
13 Dept. of Computer Science & Engineering.
// Ceiling Fan
void cfan(double rang)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glClearColor(0.5,0.5,0.5,0.0);
glLoadIdentity();
 glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
glTranslatef(-2.0f,0.0f,0.0f);
 glRotatef(rang,0.0f,1.0f,0.0f);
glScaled(0.7,0.7,0.7);
glPushMatrix();
glTranslated(0.0,1.5,0.0);
glScaled(0.1,0.8,0.1);
glutSolidSphere(1.0,20,60);
glPopMatrix();
glPushMatrix();
glTranslated(0.0,0.9,0.0);
glScaled(0.6,0.3,0.6);
glutSolidSphere(1.0,20,60);
Flying Ball
14 Dept. of Computer Science & Engineering.
glPopMatrix();
//2nd blade
glPushMatrix();
glRotatef(ang,0.0f,0.0f,1.0f);
glScaled(0.2,2.9,0.1);
glTranslatef(0.0,0.0,16.0);
glRotatef(ang,0.0f,0.0f,1.0f);
glutSolidSphere(0.7,20,60);
glPopMatrix();
glPushMatrix();
glutWireCone(4,3,80,120);
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,inc,0.0);
glPushMatrix();
glRotated(ang,0.0,1.0,0.0);
glTranslatef(0.05,2.0,0.0);
glutSolidSphere(0.3,20,60);
glPopMatrix();
glPopMatrix();
glFlush();
glutSwapBuffers();
Flying Ball
15 Dept. of Computer Science & Engineering.
}
void f()
{
x += 9.0;
fan(x);
}
//stop the fan
void F()
{
x = 0.0;
fan(x);
}
void c()
{
x += 10.9;
cfan(x);
}
void C()
{
x+=0.0;
Flying Ball
16 Dept. of Computer Science & Engineering.
cfan(x);
}
void fly1()
{
if (inc<=-4){
x+=5.30;
cfan(x);
}
else
{
inc-=0.01;
x += 5.30;
cfan(x);
}
}
void StopFly1()
{
if(inc>=0){
cfan(0);
}
Flying Ball
17 Dept. of Computer Science & Engineering.
else if(x>=0)
{x+=0.3;
inc+=.01;
cfan(x);
}else{
cfan(0);
}
}
void fly()
{
if (inc<=-4){
x+=5.30;
flying(x,inc);
}
else
{
inc-=0.01;
x += 5.30;
flying(x,inc);
}
}
Flying Ball
18 Dept. of Computer Science & Engineering.
void StopFly()
{
if(inc>=0){
flying(0,0); }
else if(x>=0)
{x+=0.3;
inc+=.01;
flying(x,inc);
}else{
flying(0,0);
}
}
void doInit()
{
 /* Background and foreground color */
 glClearColor(0.8,0.0,0.8,0.0);

Flying Ball
19 Dept. of Computer Science & Engineering.
 glViewport(0,0,640,480);
/* Select the projection matrix and reset it then
 setup our view perspective */
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
 /* Select the modelview matrix, which we alter with rotatef() */
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glClearDepth(2.0f);
 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LEQUAL);
}
void doDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
stroke_output(-2.0, 1.7, "Demonstration of Static Pressure ");
Flying Ball
20 Dept. of Computer Science & Engineering.
glPushMatrix();
glScaled(0.7,0.7,0.7);
stroke_output(-2.0, 0.9, "b --> Apply Pressure");
stroke_output(-2.0, 0.0, "B --> Stop ");
stroke_output(-2.0, -0.9, "f | F --> Start/Stop Table Fan");
stroke_output(-2.0, -1.8, "c | C --> Start/Stop Ceiling Fan");
glPopMatrix();
GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
/*light source properties*/
GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
GLfloat light_position[]={2.0f,0.0f,0.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
Flying Ball
21 Dept. of Computer Science & Engineering.
GLfloat light_position2[]={0.0f,0.0f,8.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position2);
GLfloat light_position3[]={0.0f,5.0f,2.0f,0.5f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glFlush();
glutSwapBuffers();
 }
void menu(int id)
{
switch(id)
{
case 1:glutIdleFunc(f);
break;
case 2:glutIdleFunc(F);
break;
case 3:glutIdleFunc(c);
break;
case 4:glutIdleFunc(C);
break;
Flying Ball
22 Dept. of Computer Science & Engineering.
case 5:glutIdleFunc(fly);
break;
case 6:exit(0);
break;
}
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}
void mykey(unsigned char key,int x,int y)
{
if(key=='f')
{
glutIdleFunc(f);
}
if(key=='F')
{
glutIdleFunc(F);
}
if(key=='q'||key=='Q')
Flying Ball
23 Dept. of Computer Science & Engineering.
{
exit(0);
}
if(key=='C')
{
glutIdleFunc(StopFly1);
}
if(key=='c')
{
glutIdleFunc(fly1);
}
if(key=='b')
{
glutIdleFunc(fly);
}
if(key=='B')
{
glutIdleFunc(StopFly);
}
}
int main(int argc, char *argv[])
Flying Ball
24 Dept. of Computer Science & Engineering.
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
 glutInitWindowSize(640,480);
 glutInitWindowPosition(0,0);
 glutCreateWindow("Basic Structures Orientation");
 glutDisplayFunc(doDisplay);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glutKeyboardFunc(mykey);
glutCreateMenu(menu);
 glutAddMenuEntry("Start Fan 'f'",1);
glutAddMenuEntry("Stop Fan 'F'",2);
glutAddMenuEntry("Start Ceiling Fan 'c'",3);
glutAddMenuEntry("Stop Ceiling Fan 'C'",4);
glutAddMenuEntry("Flying Ball 'b'",5);
 glutAddMenuEntry("Exit 'q'",6);
Flying Ball
25 Dept. of Computer Science & Engineering.
glutAttachMenu(GLUT_LEFT_BUTTON);
doInit();
 glutMainLoop();
return 0; 