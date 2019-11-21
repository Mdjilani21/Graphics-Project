// 3D Solar System

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <glut.h>
#include <time.h>
#include <GL/glu.h>


int i;
float j;
double R_, Rspeed, vAngle, hAngle, angleSpeed;

// Camera Position Variable
double L[3] = {0,1,0};
double R[3] = {1,0,0};
double U[3] = {0,0,1};
double C[3] = {0,0,0};

// Variables

//Rotation Speed    1072440 km = 1 unit
double speed_mercury            = 0.1608*2;
double speed_venus              = 0.1176*2;

double speed_earth              = 0.1000*2;
double speed_earth_moon         = 1.0000*2;

double speed_mars               = 0.0810*2;
double speed_mars_deimos        = 0.8000*2;
double speed_mars_phobos        = 0.5000*2;

double speed_jupitar            = 0.0438*2;
double speed_jupitar_europa     = 0.6000*2;
double speed_jupitar_io         = 0.7000*2;
double speed_jupitar_callisto   = 0.5000*2;
double speed_jupitar_ganymede   = 0.4000*2;

double speed_saturn             = 0.0323*2;
double speed_saturn_titan       = 0.3000*2;
double speed_saturn_lapetus     = 0.4000*2;
double speed_saturn_tethys      = 0.5000*2;
double speed_saturn_dione       = 0.2000*2;
double speed_saturn_rhea        = 0.1500*2;

double speed_uranus             = 0.0228*2;
double speed_uranus_umbriel     = 0.5000*2;
double speed_uranus_titania     = 0.3000*2;
double speed_uranus_oberon      = 0.2000*2;

double speed_neptune            = 0.0182*2;
double speed_neptune_triton     = 0.2500*2;


// Rotation Angle Of Planets

double angle_mercury            = 0.0;
double angle_venus              = 0.0;

double angle_earth              = 0.0;
double angle_earth_moon         = 0.0;

double angle_mars               = 0.0;
double angle_mars_deimos        = 0.0;
double angle_mars_phobos        = 0.0;

double angle_jupitar            = 0.0;
double angle_jupitar_europa     = 0.0;
double angle_jupitar_io         = 0.0;
double angle_jupitar_callisto   = 0.0;
double angle_jupitar_ganymede   = 0.0;

double angle_saturn             = 0.0;
double angle_saturn_titan       = 0.0;
double angle_saturn_lapetus     = 0.0;
double angle_saturn_tethys      = 0.0;
double angle_saturn_dione       = 0.0;
double angle_saturn_rhea        = 0.0;

double angle_uranus             = 0.0;
double angle_uranus_umbriel     = 0.0;
double angle_uranus_titania     = 0.0;
double angle_uranus_oberon      = 0.0;

double angle_neptune            = 0.0;
double angle_neptune_triton     = 0.0;



// Distance : 5991000 km    = 1 unit

double mercury_distance            = 10 * 5;
double venus_distance              = 14.2171 * 5;

double earth_distance              = 17.6524 * 5;
double earth_moon_distance         = 1.8000;

double mars_distance               = 20.2721 * 5;
double mars_deimos_distance        = 1.0000;
double mars_phobos_distance        = 1.5000;

double jupitar_distance            = 35.0834 * 5;
double jupitar_europa_distance     = 1.0000 * 8;
double jupitar_io_distance         = 1.5000 * 7;
double jupitar_callisto_distance   = 2.0000 * 6;
double jupitar_ganymede_distance   = 2.0000 * 8;

double saturn_distance             = 49.2198 * 5;
double saturn_titan_distance       = 4.0000 * 4;
double saturn_lapetus_distance     = 3.5000 * 6;
double saturn_tethys_distance      = 3.9000 * 5;
double saturn_dione_distance       = 4.0000 * 4;
double saturn_rhea_distance        = 4.2000 * 4;

double uranus_distance             = 62.6638 * 5;
double uranus_umbriel_distance     = 2.5000 * 5;
double uranus_titania_distance     = 3.5000 * 5;
double uranus_oberon_distance      = 3.8000 * 4;

double neptune_distance            = 74.1627 * 5;
double neptune_triton_distance     = 2.5000 * 4;

// Radius : 12742 km = 1 unit

double sun_radius           = 25;
double mercury_radius       = 0.3829;
double venus_radius         = 0.9499;

double earth_radius         = 1.0000;
double earth_moon_radius    = 0.2726;

double mars_radius          = 0.5320;
double mars_deimos_radius   = 0.0300;
double mars_phobos_radius   = 0.0600;

double jupitar_radius            = 5.4866;
double jupitar_europa_radius     = 0.3122;
double jupitar_io_radius         = 0.3643;
double jupitar_callisto_radius   = 0.3821;
double jupitar_ganymede_radius   = 0.4349;

double saturn_radius             = 4.5701;
double saturn_titan_radius       = 0.5123;
double saturn_lapetus_radius     = 0.2560;
double saturn_tethys_radius      = 0.1810;
double saturn_dione_radius       = 0.2010;
double saturn_rhea_radius        = 0.2790;

double uranus_radius             = 3.9808;
double uranus_umbriel_radius     = 0.1415;
double uranus_titania_radius     = 0.1930;
double uranus_oberon_radius      = 0.1750;

double neptune_radius            = 3.8646;
double neptune_triton_radius     = 0.1569;

double halleys_commet_size       = 1;
double halleys_commet_distance   = 230;
double halleys_commet_speed      = 0.5;
double halleys_commet_angle      = 0.0;


void drawAxis(){
    glBegin(GL_LINES);

	//+X axis
	glColor3f(1, 0, 0);//red
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);

	//-X axis
	glColor3f(1, 1, 1);//purple
	glVertex3f(0, 0, 0);
	glVertex3f(-1000, 0, 0);

    //+Y axis
	glColor3f(0, 1, 0);//green
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);

	//-Y axis
	glColor3f(0, 1, 0);//yellow
	glVertex3f(0, 0, 0);
	glVertex3f(0, -1000, 0);

	//+Z axis
	glColor3f(0, 0, 1);//blue
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);

	//-Z axis
	glColor3f(0, 0, 1);//cyan
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -1000);
	glEnd();
}

void drawGrid(){
    int i;

	glColor3f(0.1, 0.1, 0.1);//gray

	glBegin(GL_LINES);
	for (i = -100; i <= 100; i++)
	{
		if (i == 0)
		{
			continue;//SKIP the MAIN axes
		}

		//lines parallel to Y-axis
		glVertex3f(i * 20, -1000, 0);
		glVertex3f(i * 20, 1000, 0);

		//lines parallel to X-axis
		glVertex3f(-1000,i * 20, 0);
		glVertex3f(1000, i * 20, 0);
	}
	glEnd();
}




void display()
{
	glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    double x = sqrt(R_*R_+1);
    double y = atan(1.0/R_);
    double a = x*cos(vAngle+y)*cos(hAngle)-R_*cos(vAngle)*cos(hAngle);
    double b = x*cos(vAngle+y)*sin(hAngle)-R_*cos(vAngle)*sin(hAngle);
    double c = x*sin(vAngle+y)-R_*sin(vAngle);

	gluLookAt(C[0]+R_*cos(vAngle)*cos(hAngle),C[1]+R_*cos(vAngle)*sin(hAngle),C[2]+100+R_*sin(vAngle),  C[0]+L[0],C[1]+L[1],C[2]+L[2],  a+U[0],b+U[1],c+U[2]);

	// Start Code


	// Star Background
	for(i = 1;i<= 25; i++)
    {

        glPushMatrix();
        glRotatef(angle_mars,0,0,1);
        glTranslatef(-1000 + ((float)rand())/((float)(RAND_MAX)/2000),-1000 + ((float)rand())/((float)(RAND_MAX)/2000),-1000 + ((float)rand())/((float)(RAND_MAX)/2000));
        glColor3f(1, 1, 1);
        glutSolidTorus(0.5 + ((float)rand())/((float)(RAND_MAX)/1.5),0,50,50);
        glPopMatrix();
    }

    // Sun
    glColor3f(1,1,0);
    glutSolidSphere(sun_radius,100,100);

    // Orbital Path Of Each Planet
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glutWireTorus(mercury_distance,0,1,100);
    glutWireTorus(venus_distance,0,1,100);
    glutWireTorus(earth_distance,0,1,100);
    glutWireTorus(mars_distance,0,1,100);
    glutWireTorus(jupitar_distance,0,1,100);
    glutWireTorus(saturn_distance,0,1,100);
    glutWireTorus(uranus_distance,0,1,100);
    glutWireTorus(neptune_distance,0,1,100);
    glPopMatrix();

    // Mercury
    glPushMatrix();
    glRotatef(angle_mercury,0,0,1);
    glTranslatef(mercury_distance,0,0);
    glColor3f(0.5,0.5,0.5);
    glutSolidSphere(mercury_radius,100,100);
    glPopMatrix();

    // Venus
    glPushMatrix();
    glRotatef(angle_venus,0,0,1);
    glTranslatef(venus_distance,0,0);
    glColor3f(0.647059, 0.164706, 0.164706);
    glutSolidSphere(venus_radius,100,100);
    glPopMatrix();

    // Earth
    glPushMatrix();
    glRotatef(angle_earth,0,0,1);
    glTranslatef(earth_distance,0,0);
    glColor3f(0,0,1);
    glutSolidSphere(earth_radius,100,100);
    glColor3f(1,1,1);
    //glutWireTorus(earth_moon_distance,0,1,100);

    glRotatef(angle_earth_moon,0,-0.15,1);
    glTranslatef(earth_moon_distance,0,0);
    glColor3f(1,1,1);
    glutSolidSphere(earth_moon_radius,100,100);
    glPopMatrix();


    // Mars
    glPushMatrix();
    glRotatef(angle_mars,0,0,1);
    glTranslatef(mars_distance,0,0);
    glColor3f(1, 0.5, 0);
    glutSolidSphere(mars_radius,100,100);

    glPushMatrix();
    glRotatef(angle_mars_deimos,0,-0.6,1);
    glTranslatef(mars_deimos_distance,0,0);
    glColor3f(0.8,0.8,0.8);
    glutSolidSphere(mars_deimos_radius,5,10);
    glPopMatrix();

    glRotatef(angle_mars_phobos,0,-0.9,1);
    glTranslatef(mars_phobos_distance,0,0);
    glColor3f(0.6,0.6,0.6);
    glutSolidSphere(mars_phobos_radius,5,10);
    glPopMatrix();

    // Jupitar
    glPushMatrix();
    glRotatef(angle_jupitar,0,0,1);
    glTranslatef(jupitar_distance,0,0);
    glColor3f(0.65, 0.45, 0.20);
    glutSolidSphere(jupitar_radius,100,100);

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glRotatef(-13,1,0,0);
    glutWireTorus(8,0,1,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_jupitar_europa,0,0,1);
    glTranslatef(jupitar_europa_distance,0,0);
    glColor3f(0.123,0.345,0.327);
    glutSolidSphere(jupitar_europa_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_jupitar_io,0,0.8,1);
    glTranslatef(jupitar_io_distance,0,0);
    glColor3f(0.98,0.65,0.654);
    glutSolidSphere(jupitar_io_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_jupitar_callisto,0,-0.6,1);
    glTranslatef(jupitar_callisto_distance,0,0);
    glColor3f(0.266,0.21661,0.668);
    glutSolidSphere(jupitar_callisto_radius,100,100);
    glPopMatrix();

    glRotatef(angle_jupitar_ganymede,0,1,1);
    glTranslatef(jupitar_ganymede_distance,0,0);
    glColor3f(0.366,0.454,0.453);
    glutSolidSphere(jupitar_ganymede_radius,100,100);
    glPopMatrix();

    // Saturn
    glPushMatrix();
    glRotatef(angle_saturn,0,0,1);
    glTranslatef(saturn_distance,0,0);
    glColor3f(0.81, 0.71, 0.23);
    glutSolidSphere(saturn_radius,100,100);

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glRotatef(27,1,0,0);
    for(j = 7; j <= 9; j = j + 0.25)
    {
        glutWireTorus(j,0,1,100);
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_saturn_tethys,0,0.9,1);
    glTranslatef(saturn_tethys_distance,0,0);
    glColor3f(0.1657,0.123,0.345);
    glutSolidSphere(saturn_tethys_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_saturn_dione,0,-0.8,1);
    glTranslatef(saturn_dione_distance,0,0);
    glColor3f(1,0.8,0.312);
    glutSolidSphere(saturn_dione_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_saturn_lapetus,0,0.5,1);
    glTranslatef(saturn_lapetus_distance,0,0);
    glColor3f(0.678,0.2343,0.456);
    glutSolidSphere(saturn_lapetus_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_saturn_rhea,0,-0.5,1);
    glTranslatef(saturn_rhea_distance,0,0);
    glColor3f(1,0.6565,0.123);
    glutSolidSphere(saturn_rhea_radius,100,100);
    glPopMatrix();

    glRotatef(angle_saturn_titan,0,0,1);
    glTranslatef(saturn_titan_distance,0,0);
    glColor3f(0.0,0.5,0.6);
    glutSolidSphere(saturn_titan_radius,100,100);
    glPopMatrix();

    // Uranus
    glPushMatrix();
    glRotatef(angle_uranus,0,0,1);
    glTranslatef(uranus_distance,0,0);
    glColor3f(0, 0.498039, 1.0);
    glutSolidSphere(uranus_radius,100,100);

    glPushMatrix();
    glRotatef(angle_uranus_oberon,0,0.36,1);
    glTranslatef(uranus_oberon_distance,0,0);
    glColor3f(0.6923,0.1065,0.544);
    glutSolidSphere(uranus_oberon_radius,100,100);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle_uranus_titania,0,-0.13,1);
    glTranslatef(uranus_titania_distance,0,0);
    glColor3f(0.2,0.815,0.663);
    glutSolidSphere(uranus_titania_radius,100,100);
    glPopMatrix();

    glRotatef(angle_uranus_umbriel,0,0.98,1);
    glTranslatef(uranus_umbriel_distance,0,0);
    glColor3f(0.78,0.78,0.80);
    glutSolidSphere(uranus_umbriel_radius,100,100);
    glPopMatrix();

    // Neptune
    glPushMatrix();
    glRotatef(angle_neptune,0,0,1);
    glTranslatef(neptune_distance,0,0);
    glColor3f(0.35, 0.35, 0.67);
    glutSolidSphere(neptune_radius,100,100);

    glRotatef(angle_neptune_triton,0,-0.10,1);
    glTranslatef(neptune_triton_distance,0,0);
    glColor3f(0.856,0.33,0.66);
    glutSolidSphere(neptune_triton_radius,100,100);
    glPopMatrix();

    // Halley's Comet
    glPushMatrix();
    glTranslatef(halleys_commet_distance-40,0,0);
    glRotatef(halleys_commet_angle,0,1,0);
    glTranslatef(halleys_commet_distance,0,0);
    glRotatef(0,1,0,0);
    glColor3f(0.22,0.89,0.87);
    glutSolidSphere(halleys_commet_size,100,100);
    glColor3f(0.22,0.69,0.87);
    glutSolidCone(halleys_commet_size,halleys_commet_size*10,100,100);

    // Comets Debris
    glRotatef(halleys_commet_angle,0,0,1);
    glPushMatrix();
    glTranslatef(1,0,7+((float)rand())/((float)(RAND_MAX)/25));
    glColor3f(0, 0.6, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,7+((float)rand())/((float)(RAND_MAX)/25));
    glColor3f(0, 0.6, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,7+((float)rand())/((float)(RAND_MAX)/20));
    glColor3f(0, 0.8, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,7+((float)rand())/((float)(RAND_MAX)/20));
    glColor3f(0, 0.8, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1,7+((float)rand())/((float)(RAND_MAX)/25));
    glColor3f(0, 0.6, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-1,7+((float)rand())/((float)(RAND_MAX)/25));
    glColor3f(0, 0.6, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,2,7+((float)rand())/((float)(RAND_MAX)/20));
    glColor3f(0, 0.8, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-2,7+((float)rand())/((float)(RAND_MAX)/20));
    glColor3f(0, 0.8, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.3),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0.5,7+((float)rand())/((float)(RAND_MAX)/28));
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.4),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.5,7+((float)rand())/((float)(RAND_MAX)/28));
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.4),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5,0,7+((float)rand())/((float)(RAND_MAX)/28));
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.4),5,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5,0,7+((float)rand())/((float)(RAND_MAX)/28));
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.4),5,5);
    glPopMatrix();
    glTranslatef(0.5,0,7+((float)rand())/((float)(RAND_MAX)/30));
    glColor3f(1, 1, 1);
    glutSolidSphere(0.1 + ((float)rand())/((float)(RAND_MAX)/0.4),5,5);

    glPopMatrix();


    // -------------- Functions -------------- //


    // X, Y, Z Axis
    //drawAxis();

	// Grid Lines
	//drawGrid();

	// End Code

	glutSwapBuffers();
}

void keyboard_function(unsigned char key,int x, int y)
{

    // Zoom In
    if(key == 'z')
    {
        C[0] = C[0]-U[0];
        C[1] = C[1]-U[1];
        C[2] = C[2]-U[2];
    }
    // Zoom Out
    else if(key == 'x')
    {
        C[0] = C[0]+U[0];
        C[1] = C[1]+U[1];
        C[2] = C[2]+U[2];
    }
    // Camera Moving Up
    else if(key == 'w')
    {
        C[0] = C[0]-R[0];
        C[1] = C[1]-R[1];
        C[2] = C[2]-R[2];
    }
    // Camera Moving Down
    else if(key == 's')
    {
        C[0] = C[0]+R[0];
        C[1] = C[1]+R[1];
        C[2] = C[2]+R[2];
    }
    // Camera Moving Left
    else if(key == 'a')
    {
        C[0] = C[0]-L[0];
        C[1] = C[1]-L[1];
        C[2] = C[2]-L[2];
    }
    // Camera Moving Right
    else if(key == 'd')
    {
        C[0] = C[0]+L[0];
        C[1] = C[1]+L[1];
        C[2] = C[2]+L[2];
    }


}


void specialKeyListener(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		vAngle+=angleSpeed;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		vAngle-=angleSpeed;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		hAngle-=angleSpeed;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		hAngle+=angleSpeed;
	}
	else if (key == GLUT_KEY_PAGE_UP)
	{
	    if(R_>=Rspeed){
            R_-=Rspeed;
	    }
	}
	else if (key == GLUT_KEY_PAGE_DOWN)
    {
        R_+=Rspeed;
    }
}

void animate()
{
    angle_mercury           = angle_mercury + speed_mercury;
    angle_venus             = angle_venus + speed_venus;

    angle_earth             = angle_earth + speed_earth;
    angle_earth_moon        = angle_earth_moon - speed_earth_moon;

    angle_mars              = angle_mars + speed_mars;
    angle_mars_phobos       = angle_mars_phobos + speed_mars_phobos;
    angle_mars_deimos       = angle_mars_deimos + speed_mars_deimos;

    angle_jupitar           = angle_jupitar + speed_jupitar;
    angle_jupitar_europa    = angle_jupitar_europa + speed_jupitar_europa;
    angle_jupitar_io        = angle_jupitar_io + speed_jupitar_io;
    angle_jupitar_callisto  = angle_jupitar_callisto + speed_jupitar_callisto;
    angle_jupitar_ganymede  = angle_jupitar_ganymede + speed_jupitar_ganymede;

    angle_saturn            = angle_saturn + speed_saturn;
    angle_saturn_titan      = angle_saturn_titan - speed_saturn_titan;
    angle_saturn_rhea       = angle_saturn_rhea - speed_saturn_rhea;
    angle_saturn_lapetus    = angle_saturn_lapetus - speed_saturn_lapetus;
    angle_saturn_dione      = angle_saturn_dione - speed_saturn_dione;
    angle_saturn_tethys     = angle_saturn_tethys - speed_saturn_tethys;


    angle_uranus            = angle_uranus + speed_uranus;
    angle_uranus_oberon     = angle_uranus_oberon + speed_uranus_oberon;
    angle_uranus_umbriel    = angle_uranus_umbriel - speed_uranus_umbriel;
    angle_uranus_titania    = angle_uranus_titania + speed_uranus_titania;

    angle_neptune           = angle_neptune + speed_neptune;
    angle_neptune_triton    = angle_neptune_triton - speed_neptune_triton;


    halleys_commet_angle    = halleys_commet_angle + halleys_commet_speed;

	glutPostRedisplay();

}

void init()
{
    R_ = 100.0;
	Rspeed = 3.0;
	vAngle = 0.0;
    hAngle = 0.0;
    angleSpeed = 0.05;

    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, 1, 0.1, 10000.0);


}

int main(int argc, char **argv)
{
    srand(time(0));
	glutInit(&argc, argv);
    glutInitWindowSize(1200, 750);
	glutInitWindowPosition(150, 50);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("3D Solar System");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);

	glutSpecialFunc(specialKeyListener);
	glutKeyboardFunc(keyboard_function);

    glutIdleFunc(animate);
	glutMainLoop();

	return 0;
}
