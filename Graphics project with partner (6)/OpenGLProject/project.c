#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <windows.h>
#include <glut.h>
#include <GLaux.h>





float a=1.0,b=0.0,c=0.0,A=0.0,q1=0.0,q=0.0,A1=0.0,A2=0.0,AA=0.0,BB=0.0,B=0.0,C=0.0,t=0.0,D=0.0,E=0.0,F=0.0,G=0.0,H=0.0,I=0.0,C1=0.0,C2=0.0,X1=0.0,X2=0.0,Y1=0.0,Y2=0.0,Z1=0.0,Z2=0.0,Z3=0.0,Z4=0.0,Z5=0.0,Z6=0.0,R1=0.0,R2=0.0,morn=0.0,day=0.0,night=0.0;
float p=-200.0,D1=-70.0,D2=-82.0,E1=-72.0,E2=-84.0,F1=-72.0,F2=-84.0,G1=-72.0,G2=-84.0,H1=-72.0,H2=-84.0,I1=-72.0,I2=-84.0;

float skyv1=.42, skyv11=.65, skyv111=.80,skyv2=.53, skyv22=.81, skyv222=.98,skyv3=.25, skyv33= .41, skyv333=.88,skyv4=1,skyv44=1,skyv444=1;
int f=0,g=0,s=0;
float PI=3.1416,end=0.0,tajdown=0.0,day1=0.0,night1=0.0;
float pink1=1,pink2=.89,pink3=0.88,deep_pink1=0.80,deep_pink2= 0.51,deep_pink3= 0.67,wh1=1,wh2=1,wh3=1,gr1=0.9,gr=0.9,gr3=0.9,gold1= 0.93,gold2=.91,gold3=0.66,dgold1=1,dgold2=.84,dgold3=0;
GLfloat	l_t=0;
float  xbottom2=0.9,ybottom2=0.9,zbottom2=0.9;
float  xbottom1=1,ybottom1=1,zbottom1=1;
float  xmiddle=1,ymiddle=1,zmiddle=1;
float   xcorner=0.9,ycorner=0.9, zcorner=0.9;
GLuint texture[50];
void LoadGLTextures()
{
    AUX_RGBImageRec* TextureImage;

    glGenTextures(20,texture);

    if (TextureImage = auxDIBImageLoad("taka.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }
    if (TextureImage = auxDIBImageLoad("shaju.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }

    if (TextureImage = auxDIBImageLoad("nurjahan.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }

    if (TextureImage = auxDIBImageLoad("taj.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }



    if (TextureImage = auxDIBImageLoad("fun.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }


    if (TextureImage = auxDIBImageLoad("ele.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }



    if (TextureImage = auxDIBImageLoad("dia.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }



    if (TextureImage = auxDIBImageLoad("river.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[10]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }

    if (TextureImage = auxDIBImageLoad("end.bmp"))
    {
        glBindTexture(GL_TEXTURE_2D, texture[11]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
    }



}

void circle(float x, float y,double R,double m,double n,double o)
{
    double t = 0.0,a = 0.002, PI_2 = 2*acos(-1);

    glColor3f(m,n,o);
    glBegin(GL_TRIANGLES);
    {
        for(t=0; t<=PI_2; t+=a)
        {
            glVertex3f(x, y, 0);
            glVertex3f(R*cos(t-a)+x, R*sin(t-a)+y, 0);
            glVertex3f(R*cos(t)+x, R*sin(t)+y, 0);
        }
    }

    glEnd();


}
void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


void drawsky()
{


    glBegin(GL_QUADS);
    {

        glPushMatrix();
        glTranslatef(0,-35,0);
        glBegin(GL_QUADS);
        glColor3f(skyv1,skyv11,skyv111);

        glVertex2d(100, 75);

        glColor3f(skyv2,skyv22,skyv222);
        glVertex2d(-100, 75);
        glColor3f(skyv3,skyv33, skyv333);

        glVertex2d(-100, -15);
        glColor3f(skyv4,skyv44,skyv444);
        glVertex2d(100, -15);
        glEnd();
        glPopMatrix();

    }
    glEnd();


}

void drawtree()
{
    circle(-28,-37,3,0.27,.55,0);
    circle(-24,-37,3,0.27,.55,0);
    circle(-26,-33,3,0.27,.55,0);

    circle(-28,-42,3,0.27,.55,0);
    circle(-24,-42,3,0.27,.55,0);
    circle(-26,-39,3,0.27,.55,0);

    circle(28,-37,3,0.27,.55,0);
    circle(24,-37,3,0.27,.55,0);
    circle(26,-33,3,0.27,.55,0);

    circle(28,-42,3,0.27,.55,0);
    circle(24,-42,3,0.27,.55,0);
    circle(26,-39,3,0.27,.55,0);



    circle(-28,-55,3,0.27,.55,0);
    circle(-24,-55,3,0.27,.55,0);
    circle(-26,-51,3,0.27,.55,0);

    circle(-28,-60,3,0.27,.55,0);
    circle(-24,-60,3,0.27,.55,0);
    circle(-26,-56,3,0.27,.55,0);

    circle(28,-55,3,0.27,.55,0);
    circle(24,-55,3,0.27,.55,0);
    circle(26,-51,3,0.27,.55,0);

    circle(28,-60,3,0.27,.55,0);
    circle(24,-60,3,0.27,.55,0);
    circle(26,-56,3,0.27,.55,0);

    glBegin(GL_QUADS);
    {
        glColor3f(.8,.58,.05);
        glVertex3f(25, -66, 0);
        glVertex3f(27, -66, 0);
        glVertex3f(27, -60, 0);
        glVertex3f(25, -60, 0);

        glVertex3f(-25, -66, 0);
        glVertex3f(-27, -66, 0);
        glVertex3f(-27, -60, 0);
        glVertex3f(-25, -60, 0);


        glVertex3f(25, -49, 0);
        glVertex3f(27, -49, 0);
        glVertex3f(27, -30, 0);
        glVertex3f(25, -30, 0);

        glVertex3f(-25, -49, 0);
        glVertex3f(-27, -49, 0);
        glVertex3f(-27, -30, 0);
        glVertex3f(-25, -30, 0);
    }
    glEnd;
}
void drawfield()
{

    glBegin(GL_QUADS);
    {


        glColor3f(0.53,.81,0.98);
        glVertex3f(-25, -100, 0);
        glVertex3f(25, -100, 0);
        glVertex3f(10, -15, 0);
        glVertex3f(-10, -15, 0);
    }
    glEnd();




    glBegin(GL_QUADS);
    {
        glColor3f(0.4,.4,0.4);
        glVertex3f(-35, -100, 0);
        glVertex3f(35, -100, 0);
        glVertex3f(10, -15, 0);
        glVertex3f(-10, -15, 0);

        glColor3f(0.67,1,0.18);
        glVertex3f(-100, -100, 0);
        glVertex3f(100, -100, 0);
        glVertex3f(100, -15, 0);
        glVertex3f(-100, -15, 0);

    }
    glEnd();


}
void drawtaj()
{

    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==0  && C != 125)
        C=C+1;
    else if(s ==1 )
        C=C+.5;
    glTranslatef(0,C,0);
    renderBitmapString(-55.0,-72.0,GLUT_BITMAP_TIMES_ROMAN_24,"Taj Mahal was built by Mughal Emperor Shah Jahan in the loving memory of the");
    renderBitmapString(-25.0,-84.0,GLUT_BITMAP_TIMES_ROMAN_24," beautiful Wife Mumtaj !!!");
    glPopMatrix();
    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==1  && D != 125)
        D=D+1;
    else if(s ==2 )
        D=D+.5;
    glTranslatef(0,D,0);
    renderBitmapString(-55.0,D1,GLUT_BITMAP_TIMES_ROMAN_24,"Construction of Taj Mahal started in year 1631.Around 20,000 people worked day ");
    renderBitmapString(-55.0,D2,GLUT_BITMAP_TIMES_ROMAN_24," and night for 22 years to build this historical monument. ");
    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==2 && E != 125)
        E=E+1;
    else if(s ==3 )
        E=E+.5;
    glTranslatef(0,E,0);
    renderBitmapString(-55.0,E1,GLUT_BITMAP_TIMES_ROMAN_24,"The construction cost of this Masterpiece Monument was around 320 million ");
    renderBitmapString(-25.0,E2,GLUT_BITMAP_TIMES_ROMAN_24," indian Rupees!!!");
    glPopMatrix();


    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==3 && F != 125)
        F=F+1;
    else if(s ==4 )
        F=F+.5;
    glTranslatef(0,F,0);
    renderBitmapString(-55.0,F1,GLUT_BITMAP_TIMES_ROMAN_24,"Around 1000 elephants were employed for the transportation of the ");
    renderBitmapString(-25.0,F2,GLUT_BITMAP_TIMES_ROMAN_24," construction material !!!");
    glPopMatrix();

    glPushMatrix();
    if(s ==4 && G != 125)
        G=G+1;
    else if(s ==5 )
        G=G+.5;
    glTranslatef(0,G,0);
    renderBitmapString(-55.0,G1,GLUT_BITMAP_TIMES_ROMAN_24,"30 different variety if semi precious and precious stone were used To make");
    renderBitmapString(-25.0,G2,GLUT_BITMAP_TIMES_ROMAN_24,"the Taj Mahal more beautiful!!!");
    glPopMatrix();

    glPushMatrix();
    if(s ==5 && H != 125)
        H=H+1;
    else if(s ==8 )
        H=H+.5;
    glTranslatef(0,H,0);
    renderBitmapString(-55.0,H1,GLUT_BITMAP_TIMES_ROMAN_24,"At the different time of the day Taj Mahal appears to be in a different colour Every time!!!");

    glPopMatrix();

    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==6 && morn !=125 )
    {
        morn+=2.5;


        xbottom2=deep_pink1,ybottom2=deep_pink2,zbottom2=deep_pink3;
        xbottom1=pink1,ybottom1=pink2,zbottom1=pink3;
        xmiddle=pink1,ymiddle=pink2,zmiddle=pink3;
        xcorner=deep_pink1,ycorner=deep_pink2, zcorner=deep_pink3;
        skyv1=0;
        skyv11=0;
        skyv111=1;
        skyv2=1;
        skyv222=0;
        skyv22=1;
        skyv3=1;
        skyv33=0;
        skyv333=0;
        skyv4=1;
        skyv44=1;
        skyv444=1;
    }
    else if(s ==7 )
        morn=morn+.5;
    glTranslatef(0,morn,0);
    renderBitmapString(25.0,-84.0,GLUT_BITMAP_TIMES_ROMAN_24,"PINK IN THE MORNING......");

    glPopMatrix();
    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==7  && day != 125)
    {
        day+=2.5;

        skyv1=.42, skyv11=.65, skyv111=.80,skyv2=.53, skyv22=.81, skyv222=.98,skyv3=.25, skyv33= .41, skyv333=.88,skyv4=1,skyv44=1,skyv444=1;
        xbottom2=0.9,ybottom2=0.9,zbottom2=0.9;
        xbottom1=1,ybottom1=1,zbottom1=1;
        xmiddle=wh1,ymiddle=wh2,zmiddle=wh3;
        xcorner=0.9,ycorner=0.9, zcorner=0.9;
    }
    else if(s ==8 )
        day1=day1-3;
    glTranslatef(0,day,0);
    glTranslatef(day1,0,0);
    renderBitmapString(25.0,-84.0,GLUT_BITMAP_TIMES_ROMAN_24,"WHITE IN THE DAY ......");

    glPopMatrix();
    glColor3f(1,1,1);
    glPushMatrix();
    if(s ==8  && night != 125)
    {
        night=night+2.5;

        xbottom2=dgold1,ybottom2=dgold2,zbottom2=dgold3;
        xbottom1=gold1,ybottom1=gold2,zbottom1=gold3;
        xmiddle=gold1,ymiddle=gold2,zmiddle=gold3;
        xcorner=dgold1,ycorner=dgold2, zcorner=dgold3;
        skyv1=0;
        skyv11=0;
        skyv111=1;
        skyv2=0;
        skyv222=0;
        skyv22=1;
        skyv3=0;
        skyv33=0;
        skyv333=1;
        skyv4=0;
        skyv44=0;
        skyv444=1;
    }
    else if(s ==9 )
        night1=night1+5;
    glTranslatef(0,night,0);
    glTranslatef(night1,0,0);
    renderBitmapString(25.0,-84.0,GLUT_BITMAP_TIMES_ROMAN_24,"GOLDEN AT THE NIGHT......");

    glPopMatrix();
    glColor3f(0,0,0);
    glPushMatrix();
    if(s ==9 && I != 125)
    {
        I=I+2.5;
        skyv1=.42, skyv11=.65, skyv111=.80,skyv2=.53, skyv22=.81, skyv222=.98,skyv3=.25, skyv33= .41, skyv333=.88,skyv4=1,skyv44=1,skyv444=1;
        xbottom2=0.9,ybottom2=0.9,zbottom2=0.9;
        xbottom1=1,ybottom1=1,zbottom1=1;
        xmiddle=wh1,ymiddle=wh2,zmiddle=wh3;
        xcorner=0.9,ycorner=0.9, zcorner=0.9;
    }

    else if(s ==11 )
        I=I+.5;
    glTranslatef(0,I,0);
    renderBitmapString(-55.0,I1,GLUT_BITMAP_TIMES_ROMAN_24,"In recent times different studies suggest that Taj Mahal is sinking in Yamuna River !!!");

    glPopMatrix();


    glPushMatrix();
    if(s ==10 )
        tajdown=tajdown-2;
    glTranslatef(0,tajdown,0);
    drawtree();
    glBegin(GL_QUADS);
    {
        glColor3f(xbottom1,ybottom1,zbottom1);
        glVertex3f(-50, -21, 0);
        glVertex3f(50, -21, 0);
        glVertex3f(50, -20, 0);
        glVertex3f(-50, -20, 0);

        glColor3f(xbottom2,ybottom2,zbottom2);
        glVertex3f(-50, -21, 0);
        glVertex3f(50, -21, 0);
        glVertex3f(50, -23, 0);
        glVertex3f(-50, -23, 0);


        glColor3f(xbottom1,ybottom1,zbottom1);
        glVertex3f(-50, -23, 0);
        glVertex3f(50, -23, 0);
        glVertex3f(50, -28, 0);
        glVertex3f(-50, -28, 0);

        glColor3f(xbottom2,ybottom2,zbottom2);
        glVertex3f(-60, -28, 0);
        glVertex3f(60, -28, 0);
        glVertex3f(60, -33, 0);
        glVertex3f(-60, -33, 0);
    }
    glEnd();




    glColor3f(xmiddle,ymiddle,zmiddle);
    glBegin(GL_TRIANGLES);
    {

        glVertex3f(-13.5, 25.5, 0);
        glVertex3f(13.5,25.5, 0);
        glVertex3f(0,39.5, 0);
    }

    glEnd();

    circle(0.0,20.0,14.5,xmiddle,ymiddle,zmiddle);


    glColor3f(xmiddle,ymiddle,zmiddle);
    glBegin(GL_TRIANGLES);
    {

        glVertex3f(-59, 10, 0);
        glVertex3f(-51,10, 0);
        glVertex3f(-55,15, 0);



    }

    glEnd();

    circle(-55.0,7.0,5.0,xmiddle,ymiddle,zmiddle);

    glColor3f(xmiddle,ymiddle,zmiddle);
    glBegin(GL_TRIANGLES);
    {

        glVertex3f(59, 10, 0);
        glVertex3f(51,10, 0);
        glVertex3f(55,15, 0);
    }

    glEnd();

    circle(55.0,7.0,5.0,xmiddle,ymiddle,zmiddle);


    circle(-37.45,1.0,2.5,xcorner,ycorner,zcorner);
    glColor3f(xcorner,ycorner,zcorner);
    glBegin(GL_TRIANGLES);
    {

        glVertex3f(-39, 3, 0);
        glVertex3f(-35.9,3, 0);
        glVertex3f(-37.4,5, 0);
    }

    glEnd();


    circle(37.45,1.0,2.5,xcorner,ycorner,zcorner);
    glColor3f(xcorner,ycorner,zcorner);
    glBegin(GL_TRIANGLES);
    {

        glVertex3f(35.9, 3, 0);
        glVertex3f(39,3, 0);
        glVertex3f(37.4,5, 0);
    }

    glEnd();



    glBegin(GL_QUADS);


    {

        glColor3f(0.56,0.27,0.07);
        glVertex3f(-24, -20, 0);
        glVertex3f(-28, -20, 0);
        glVertex3f(-28, -7.5, 0);
        glVertex3f(-24, -7.5, 0);

        glVertex3f(24, -20, 0);
        glVertex3f(28, -20, 0);
        glVertex3f(28, -7.5, 0);
        glVertex3f(24, -7.5, 0);






        glColor3f(0.56,0.27,0.07);
        glVertex3f(-14, -20, 0);
        glVertex3f(-18, -20, 0);
        glVertex3f(-18, -7.5, 0);
        glVertex3f(-14, -7.5, 0);

        glVertex3f(14, -20, 0);
        glVertex3f(18, -20, 0);
        glVertex3f(18, -7.5, 0);
        glVertex3f(14, -7.5, 0);


        glColor3f(0.56,0.27,0.07);
//middlesmalldoor
        glVertex3f(-4, -20, 0);
        glVertex3f(4, -20, 0);
        glVertex3f(4, -5, 0);
        glVertex3f(-4, -5, 0);



//middlebigdoor
        glColor3f(xcorner,ycorner,zcorner);
        glVertex3f(-8, -20, 0);
        glVertex3f(8, -20, 0);
        glVertex3f(8, 5, 0);
        glVertex3f(-8, 5, 0);


        glColor3f(xmiddle,ymiddle,zmiddle);

        glVertex3f(-12, -20, 0);
        glVertex3f(12, -20, 0);
        glVertex3f(12, 15, 0);
        glVertex3f(-12, 15, 0);



        glColor3f(xcorner,ycorner,zcorner);

        glVertex3f(10, -20, 0);
        glVertex3f(23, -20, 0);
        glVertex3f(23, 5, 0);
        glVertex3f(10, 5, 0);

        glColor3f(xcorner,ycorner,zcorner);
        glVertex3f(23,-20, 0);
        glVertex3f(30, -20, 0);
        glVertex3f(30, 4, 0);
        glVertex3f(23, 5, 0);

        glColor3f(xcorner,ycorner,zcorner);

        glVertex3f(-10, -20, 0);
        glVertex3f(-23, -20, 0);
        glVertex3f(-23, 5, 0);
        glVertex3f(-10, 5, 0);
        glColor3f(xcorner,ycorner,zcorner);
//glColor3f(0.93,.91,0.66);
        glVertex3f(-23,-20, 0);
        glVertex3f(-30, -20, 0);
        glVertex3f(-30, 4, 0);
        glVertex3f(-23, 5, 0);
//big left minar




        glColor3f(xmiddle,ymiddle,zmiddle);
        glVertex3f(-60, -28, 0);
        glVertex3f(-50, -28, 0);
        glVertex3f(-52, 10, 0);
        glVertex3f(-58, 10, 0);



        //big right minar

        glVertex3f(50, -28, 0);
        glVertex3f(60, -28, 0);
        glVertex3f(58, 10, 0);
        glVertex3f(52, 10, 0);

        //smallminar
        glColor3f(xcorner,ycorner,zcorner);
        glVertex3f(-40, -20, 0);
        glVertex3f(-35, -20, 0);
        glVertex3f(-36, 0, 0);
        glVertex3f(-39, 0, 0);


        glVertex3f(35, -20, 0);
        glVertex3f(40, -20, 0);
        glVertex3f(39, 0, 0);
        glVertex3f(36, 0, 0);
    }
    glEnd();
    glPopMatrix();
}

void image()
{
    glPushMatrix();


    if(s ==0 )
        q1=q1+1;
    glTranslatef(q1,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(-40, -30, 0);
        glTexCoord2f(1, 0);
        glVertex3f(40, -30, 0);
        glTexCoord2f(1, 1);
        glVertex3f(40, 30, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-40, 30, 0);

    }
    glEnd();

    glPopMatrix();
    glPushMatrix();

    if(s ==0 && A != 120 )
        A=A+1;
    else if(s ==1 )
        AA=AA+.9;
    glTranslatef(0,A,0);
    glTranslatef(AA,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(25, -100, 0);
        glTexCoord2f(1, 0);
        glVertex3f(55, -100, 0);
        glTexCoord2f(1, 1);
        glVertex3f(55, -70, 0);
        glTexCoord2f(0, 1);
        glVertex3f(25, -70, 0);

    }
    glEnd();


    glPopMatrix();


    glPushMatrix();
    if(s ==1 && A1 != 120 )
        A1=A1+1;
    else if(s ==2 )
        A2=A2+.9;
    glTranslatef(0,A1,0);
    // glPushMatrix();
    glTranslatef(A2,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(25, -100, 0);
        glTexCoord2f(1, 0);
        glVertex3f(57,-100, 0);
        glTexCoord2f(1, 1);
        glVertex3f(57, -70, 0);
        glTexCoord2f(0, 1);
        glVertex3f(25, -70, 0);

    }
    glEnd();
    glPopMatrix();
// glPopMatrix();

    glPushMatrix();
    if(s ==2 && C1 != 110 )
        C1=C1+1;
    else if(s ==3 )
        C2=C2+.9;
    glTranslatef(0,C1,0);
    glTranslatef(C2,0,0);

    // glColor3f(0.85,.65,0.13);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(20, -100, 0);
        glTexCoord2f(1, 0);
        glVertex3f(60,-100, 0);
        glTexCoord2f(1, 1);
        glVertex3f(60, -75, 0);
        glTexCoord2f(0, 1);
        glVertex3f(20, -75, 0);

    }
    glEnd();

    glPopMatrix();

    glPushMatrix();
    if(s ==3 && X1 != 40 )
        X1=X1+1;
    else if(s ==4 )
        X2=X2+.9;
    glTranslatef(0,X1,0);
    glTranslatef(X2,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS);

    {

        glTexCoord2f(0, 0);
        glVertex3f(-45, -100, 0);
        glTexCoord2f(1, 0);
        glVertex3f(45,-100, 0);
        glTexCoord2f(1, 1);
        glVertex3f(45, -75, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-45, -75, 0);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if(s ==4 && Y1 != 120 )
        Y1+=1;
    else if(s ==5 )
        Y2=Y2+.9;
    glTranslatef(0,Y1,0);
    glTranslatef(Y2,0,0);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(25, -110, 0);
        glTexCoord2f(1, 0);
        glVertex3f(55, -110, 0);
        glTexCoord2f(1, 1);
        glVertex3f(55, -70, 0);
        glTexCoord2f(0, 1);
        glVertex3f(25, -70, 0);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    if(s ==9 && R1 != 40 )
        R1=R1+1;
    else if(s == 11)
        R2=R2-.5;
    glTranslatef(0,R1,0);
    glTranslatef(0,R2,0);
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(-75, -110, 0);
        glTexCoord2f(1, 0);
        glVertex3f(75,-110, 0);
        glTexCoord2f(1, 1);
        glVertex3f(75, -70, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-75, -70, 0);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    if(s ==11 && end != -150 )
        end=end-2;
    glTranslatef(0,end,0);
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    glBegin(GL_QUADS);

    {


        glTexCoord2f(0, 0);
        glVertex3f(-40, 110, 0);
        glTexCoord2f(1, 0);
        glVertex3f(40, 110, 0);
        glTexCoord2f(1, 1);
        glVertex3f(40, 180, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-40, 180, 0);

    }
    glEnd();

    glPopMatrix();

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();


    gluLookAt(0,0,100,	0,0,0,	0,1,0);



    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    image();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //  drawtree();
    drawtaj();
    drawfield();
    drawsky();



//image();

    glFlush();


}

void animate()
{
    //codes for any changes in Models, Camera

    //this will call the display AGAIN





    glutPostRedisplay();
}

void specialKeyListener(int key, int x, int y)
{


}


void Keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's' :
    {
        glutIdleFunc(animate);
        s=0;


        break;
    }


    case '1' :
    {
        glutIdleFunc(animate);
        s=1;
        break;
    }
    case '2' :
    {
        glutIdleFunc(animate);
        s=2;
        break;
    }
    case '3' :
    {
        glutIdleFunc(animate);
        s=3;
        break;
    }

    case '4' :
    {
        glutIdleFunc(animate);
        s=4;
        break;
    }
    case '5' :
    {
        glutIdleFunc(animate);
        s=5;
        break;
    }

    case '6' :
    {
        glutIdleFunc(animate);
        s=6;

        break;
    }
    case '7' :
    {
        glutIdleFunc(animate);
        s=7;
        break;
    }
    case '8' :
    {
        glutIdleFunc(animate);
        s=8;
        break;
    }
    case '9' :
    {
        glutIdleFunc(animate);
        s=9;
        break;
    }
    case 't' :
    {
        glutIdleFunc(animate);
        s=10;
        break;
    }
    case 'e' :
    {
        glutIdleFunc(animate);
        s=11;
        break;
    }



    default:
        ;
    }

    glutPostRedisplay();
}
void init()
{
    LoadGLTextures();
    glClearColor (0.0, 0.0, 0.0,0.0) ;
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    /*
    gluPerspective() — set up a perspective projection matrix

    fovy -         Specifies the field of view angle, in degrees, in the y direction.
    aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
    zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
    zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
    */

    gluPerspective(70, 1, 0.1, 10000.0);

}

int main(int argc, char **argv)
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (120, 0);
    glutCreateWindow ("Story of tajmahal!");
    init();

    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(1,image,0);
    glutMainLoop();

    return 0;
}

