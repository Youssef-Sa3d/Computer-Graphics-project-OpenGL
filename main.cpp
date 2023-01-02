#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;


void init(){
    glClearColor(0.0 , 0.0 , 0.0 , 1.0);
    glEnable(GL_DEPTH_TEST);

}
//------------------------------  reshapeFunc  ---------------------------------
//commit 7
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//------------------------------  display   -------------------------------
float angle = 0.0;
float step=0; // change x
float step2=0; // change y
float step3 = 0; // change z
float step4 = 0 ;
float x=0 , y=0 ;
float r = 0 , g = 1 , b = 0 ;//color of ashara()


//upper body
void Abo_Treeka(){
    glBegin (GL_QUADS) ;
    //FRONT
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);

    //BACK
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,-1.0+step3);
    //RIGHT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,1.0+step3);
    glVertex3f(1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);
    //LEFT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,-1.0+step3);
    glVertex3f(-1.5+step,1.0+step2,1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    //TOP
    glColor3f(0.0,1.0,1.0);
    glVertex3f (-1.0+step,2.0+step2,-1.0+step3);
    glVertex3f(-1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,1.0+step3);
    glVertex3f(1.0+step,2.0+step2,-1.0+step3);

    glEnd();





}
// suii = lower body
void suii(){
    glBegin (GL_QUADS) ;
    //FRONT
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-3.0+step,1.0+step2,1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    //BACK
    glColor3f(0.0,1.0,0.0);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);
    glVertex3f (-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,1.0+step2,-1.0+step3);
    //RIGHT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    //LEFT
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-3.0+step,1.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(-3.0+step,1.0+step2,1.0+step3);
    //TOP
    glColor3f(0.0,1.0,1.0);
    glVertex3f (-3.0+step,1.0+step2,-1.0+step3);
    glVertex3f (-3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,1.0+step3);
    glVertex3f(3.0+step,1.0+step2,-1.0+step3);
    //BOTTOM
    glColor3f(1.0,0.0,1.0);
    glVertex3f (-3.0+step,0.0+step2,-1.0+step3);
    glVertex3f(-3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,1.0+step3);
    glVertex3f(3.0+step,0.0+step2,-1.0+step3);

    glEnd();

}
void car()
{
    glTranslatef    (-1.8 +x, -6.5 +y, 15+step4);
    glRotatef(65 , 0.0  , 1.0  , 0.0 );
    glRotatef(10 , 0.0 , 0.0, 1.0 );
    //front
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(0  , 1.9 , 1.0 );
    glVertex3f(0 , 1.0 , 1.0 );
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.9,1.9,1.0);
    glVertex3f(-1.4,1.0,1.0);
    glVertex3f(1.4,1.0,1.0);
    glVertex3f(0.9,1.9,1.0);
    glEnd();

    //back
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(0  , 1.9 , -1.0 );
    glVertex3f(0 , 1.0 , -1.0 );
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.9,1.9,-1.0);
    glVertex3f(-1.4,1.0,-1.0);
    glVertex3f(1.4,1.0,-1.0);
    glVertex3f(0.9,1.9,-1.0);
    glEnd();



    suii();
    Abo_Treeka();



}
void road(){
    glTranslatef(0,0,-8);
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(-5  , -2 , 1.0 );
    glVertex3f(5 , 2.5 , 1.0 );
    glEnd();
    glColor3f(1, 1.0, 1.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex3f(-5  , -6.5 , 1.0 );
    glVertex3f(5 , 1.5 , 1.0 );
    glEnd();


}

void moon() {

    glTranslatef(-7 ,6 ,-12);

    glColor3f(1, 1.0, 1);



    glScalef(1.0,1.0,1.0);
    glutSolidSphere(1,20,5);

}


void ashara(){
    glColor3f(1, 1.0, 1);

    glLineWidth(10.0);
    // el 3amood
    glBegin(GL_LINES);
    glVertex3f(1  , -8 , 1.0 );
    glVertex3f(1.2 , -4 , 1.0 );
    glEnd();
    //el eshara
    glColor3f(r, g, b);
    glTranslatef(1.8 ,-4.5 ,0);
    glutSolidCube(1.5);

}

void display (void)
{

    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    road();
    moon();
    ashara();
    car();
    glutSwapBuffers();
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}


//----------------------------------  Time  ------------------------------------


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/20,timer,0);

	if ((r == 0 && g == 1 && b == 0) || (r == 1 && g == 1 && b == 0) ){

        x += 0.13;
        y += 0.05;
        step4 -= 0.15;

	}
	else if (r == 1 && g == 0 && b == 0 ){

        x += 0;
        y += 0;
        step4 -= 0;

	}


}

//---------------------------------- Keyboard input ----------------------------
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}
void processSpecialKeys(int key, int x, int y) {

	switch(key) {

		case GLUT_KEY_RIGHT : //right button pressed
                b = 0;
                r = 1;
                g = 0;
				break;
        case GLUT_KEY_LEFT : //left button pressed
                b = 0;
                r = 1;
				g = 0;
				break;
        case GLUT_KEY_UP : //left button pressed
                b = 0;
                r = 0;
				g = 1;
				break;
	}
}




//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // buffer mode
    glutInitWindowSize     (800, 700);
    glutInitWindowPosition (700, 200);
    glutCreateWindow       ("20101839");
    init();
    sndPlaySoundA("D:\#Matrial\Computer Graphics\The End\GODFATHER THEME.mp3",SND_ASYNC); //sound function
    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutTimerFunc(1000, timer, 0);
    //keyboard input functions
    glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

    glutIdleFunc    (idleFunc);

    glClearColor(0,0,0,1);
    texture(); // Lighting and textures


    glutMainLoop();
}
