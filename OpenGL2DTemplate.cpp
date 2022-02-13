//  Includes
#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <windows.h>
//-----------------
double xMovement = 0;
int nextSet = 0;
double birdMovementY = 0;
//double accelerationY = 0;
int currentScore = 0;
double powerR = 0;
int lives = 3;
double angle = 0;
double angle2 = 0;
double angle3 = 0;
bool gameOver = false;
bool powerUpActivated = false;
bool playOnce = true;

void miniTriangle(double x_start, double x_end, double y_start) {
    glColor3d(0, 0, 0);
    int length = (int)(x_end - x_start)/15;
    x_end = x_start + 15;
    for (int i = 0; i < length; i++) {
        glBegin(GL_TRIANGLES);
        glVertex2d(x_start + xMovement, y_start);
        glVertex2d(x_end + xMovement, y_start);
        glVertex2d((x_start + x_end) / 2 + xMovement, y_start + 10);
        glEnd();

        x_start = x_end;
        x_end = x_start + 15;
    }

}
void miniTriangleDown(double x_start, double x_end, double y_start) {
    glColor3d(0, 0, 0);
    int length = (int)(x_end - x_start) / 15;
    x_end = x_start + 15;
    for (int i = 0; i < length; i++) {
        glBegin(GL_TRIANGLES);
        glVertex2d(x_start + xMovement, y_start);
        glVertex2d(x_end + xMovement, y_start);
        glVertex2d((x_start + x_end) / 2 + xMovement, y_start - 10);
        glEnd();

        x_start = x_end;
        x_end = x_start + 15;
    }

}
void set1() {
    glBegin(GL_QUADS);

    //background
    glColor3f(0.8, 0.2,1);
    glVertex2f(0, 0);
    glVertex2f(0, 800);
    glVertex2f(800, 800);
    glVertex2f(800, 0);
    glColor3f(0, 0.4, 0.5);

    //first
    glVertex2d(100 + xMovement + 700, 0);
    glVertex2d(200 + xMovement + 700, 0);
    glVertex2d(200 + xMovement + 700, 150);
    glVertex2d(100 + xMovement + 700, 150);

    glVertex2d(100 + xMovement + 700, 400);
    glVertex2d(200 + xMovement + 700, 400);
    glVertex2d(200 + xMovement + 700, 800);
    glVertex2d(100 + xMovement + 700, 800);
    //second
    glVertex2d(350 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 300);
    glVertex2d(350 + xMovement + 800, 300);

    glVertex2d(350 + xMovement + 800, 550);
    glVertex2d(500 + xMovement + 800, 550);
    glVertex2d(500 + xMovement + 800, 800);
    glVertex2d(350 + xMovement + 800, 800);

    //third
    glVertex2d(600 + xMovement + 800, 0);
    glVertex2d(750 + xMovement + 800, 0);
    glVertex2d(750 + xMovement + 800, 350);
    glVertex2d(600 + xMovement + 800, 350);

    glVertex2d(600 + xMovement + 800, 600);
    glVertex2d(750 + xMovement + 800, 600);
    glVertex2d(750 + xMovement + 800, 800);
    glVertex2d(600 + xMovement + 800, 800);

    glEnd();
    miniTriangle(800, 900, 150);
    miniTriangle(1150, 1300, 300);
    miniTriangle(1400, 1550, 350);

    miniTriangleDown(800, 900, 400);
    miniTriangleDown(1150, 1300, 550);
    miniTriangleDown(1400, 1550, 600);


}

void set2() {
    glBegin(GL_QUADS);
    //background
    glColor3f(0.8, 0.6, 0.4);
    glVertex2f(0, 0);
    glVertex2f(0, 800);
    glVertex2f(800, 800);
    glVertex2f(800, 0);


    glColor3f(0.9, 0, 0);
    //first
    glVertex2d(100 + xMovement +700, 0);
    glVertex2d(250 + xMovement + 700, 0);
    glVertex2d(250 + xMovement + 700, 100);
    glVertex2d(100 + xMovement + 700, 100);

    glVertex2d(100 + xMovement + 700, 400);
    glVertex2d(250 + xMovement + 700, 400);
    glVertex2d(250 + xMovement + 700, 800);
    glVertex2d(100 + xMovement + 700, 800);
    //second
    glVertex2d(425 + xMovement + 800, 0);
    glVertex2d(475 + xMovement + 800, 0);
    glVertex2d(475 + xMovement + 800, 400);
    glVertex2d(425 + xMovement + 800, 400);

    glVertex2d(425 + xMovement + 800, 760);
    glVertex2d(475 + xMovement + 800, 760);
    glVertex2d(475 + xMovement + 800, 800);
    glVertex2d(425 + xMovement + 800, 800);

    //third
    glVertex2d(670 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 150);
    glVertex2d(670 + xMovement + 800, 150);

    glVertex2d(670 + xMovement + 800, 455);
    glVertex2d(800 + xMovement + 800, 455);
    glVertex2d(800 + xMovement + 800, 800);
    glVertex2d(670 + xMovement + 800, 800);

    glEnd();
    miniTriangle(800, 950, 100);
    miniTriangle(1225, 1275, 400);
    miniTriangle(1470, 1600, 150);

    miniTriangleDown(800, 950, 400);
    miniTriangleDown(1225, 1275, 760);
    miniTriangleDown(1470, 1600, 455);
}

void set3() {
    glBegin(GL_QUADS);

    //background
    glColor3f(0.7, 1, 0.1);
    glVertex2f(0, 0);
    glVertex2f(0, 800);
    glVertex2f(800, 800);
    glVertex2f(800, 0);


    glColor3f(0.7, 0.3, 0.5);
    //first
    glVertex2d(100 + xMovement + 700, 0);
    glVertex2d(250 + xMovement + 700, 0);
    glVertex2d(250 + xMovement + 700, 200);
    glVertex2d(100 + xMovement + 700, 200);

    glVertex2d(100 + xMovement + 700, 550);
    glVertex2d(250 + xMovement + 700, 550);
    glVertex2d(250 + xMovement + 700, 800);
    glVertex2d(100 + xMovement + 700, 800);
    //second
    glVertex2d(400 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 500);
    glVertex2d(400 + xMovement + 800, 500);

    glVertex2d(400 + xMovement + 800, 760);
    glVertex2d(500 + xMovement + 800, 760);
    glVertex2d(500 + xMovement + 800, 800);
    glVertex2d(400 + xMovement + 800, 800);

    //third
    glVertex2d(600 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 340);
    glVertex2d(600 + xMovement + 800, 340);

    glVertex2d(600 + xMovement + 800, 680);
    glVertex2d(800 + xMovement + 800, 680);
    glVertex2d(800 + xMovement + 800, 800);
    glVertex2d(600 + xMovement + 800, 800);

    glEnd();

    miniTriangle(800, 950, 200);
    miniTriangle(1200, 1300, 500);
    miniTriangle(1400, 1600, 340);

    miniTriangleDown(800, 950, 550);
    miniTriangleDown(1200, 1300, 760);
    miniTriangleDown(1400, 1600, 680);
}

void setPower() {
    glBegin(GL_QUADS);

    //background
    if(powerUpActivated)
        glColor3f(1, 0.9, 0.6);
    else
        glColor3f(0.6, 0.9, 0.8);
    glVertex2f(0, 0);
    glVertex2f(0, 800);
    glVertex2f(800, 800);
    glVertex2f(800, 0);

    if (powerUpActivated)
        glColor3f(0.6, 0.9, 1);
    else
       glColor3f(0.8, 0.6, 0.9);
    //first
    glVertex2d(100 + xMovement + 800, 0);
    glVertex2d(200 + xMovement + 800, 0);
    glVertex2d(200 + xMovement + 800, 100);
    glVertex2d(100 + xMovement + 800, 100);

    glVertex2d(100 + xMovement + 800, 700);
    glVertex2d(200 + xMovement + 800, 700);
    glVertex2d(200 + xMovement + 800, 800);
    glVertex2d(100 + xMovement + 800, 800);

    //second
    glVertex2d(400 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 0);
    glVertex2d(500 + xMovement + 800, 400);
    glVertex2d(400 + xMovement + 800, 400);

    glVertex2d(400 + xMovement + 800, 610);
    glVertex2d(500 + xMovement + 800, 610);
    glVertex2d(500 + xMovement + 800, 800);
    glVertex2d(400 + xMovement + 800, 800);

    //third
    glVertex2d(650 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 0);
    glVertex2d(800 + xMovement + 800, 500);
    glVertex2d(650 + xMovement + 800, 500);

    glVertex2d(650 + xMovement + 800, 700);
    glVertex2d(800 + xMovement + 800, 700);
    glVertex2d(800 + xMovement + 800, 800);
    glVertex2d(650 + xMovement + 800, 800);

    glEnd();
    miniTriangle(900, 1000, 100);
    miniTriangle(1200, 1300, 400);
    miniTriangle(1450, 1600, 500);

    miniTriangleDown(900, 1000, 700);
    miniTriangleDown(1200, 1300, 610);
    miniTriangleDown(1450, 1600, 700);
}
void bird() {
    if (gameOver) {
        glColor3d(0, 0, 0);
        //body
        glBegin(GL_QUADS);
        glVertex2d(100, 350 );
        glVertex2d(150, 350 );
        glVertex2d(150, 400);
        glVertex2d(100, 400 );
        glEnd();

        //Mouth

        glBegin(GL_POLYGON);
        glColor3d(0.9, 0.5, 0.5);

        glVertex2d(115, 355 );
        glVertex2d(135, 355 );
        glVertex2d(130, 365);
        glVertex2d(120, 365);


        glEnd();

        //whiskers

        glBegin(GL_LINES);
        glColor3d(1, 1, 1);
        glVertex2d(125, 364 );
        glVertex2d(95, 355 );

        glVertex2d(125, 364 );
        glVertex2d(95, 370 );

        glVertex2d(125, 364);
        glVertex2d(155, 370);

        glVertex2d(125, 364 );
        glVertex2d(155, 355);
        glEnd();
        //ears
        glColor3d(0, 0, 0);

        glBegin(GL_TRIANGLES);
        glVertex2d(100, 400 );
        glVertex2d(120, 400 );
        glVertex2d(110, 425 );

        glVertex2d(130, 400 );
        glVertex2d(150, 400);
        glVertex2d(140, 425 );

        glColor3d(0.9, 0.5, 0.5);
        glVertex2d(104, 400 );
        glVertex2d(116, 400);
        glVertex2d(110, 420 );

        glVertex2d(134, 400 );
        glVertex2d(146, 400 );
        glVertex2d(140, 420 );
        glEnd();



        //eyes

        glPushMatrix();
        glColor3f(1, 1, 1);

        glTranslatef(110, 380 , 0);
        GLUquadric* quadObj = gluNewQuadric();
        gluDisk(quadObj, 0, 10, 50, 50);
        glPopMatrix();


        glPushMatrix();
        glColor3f(1, 1, 1);

        glTranslatef(140, 380 , 0);
        quadObj = gluNewQuadric();
        gluDisk(quadObj, 0, 10, 50, 50);
        glPopMatrix();

        glBegin(GL_LINES);
        glColor3f(1, 0, 0);

        glVertex2d(120, 388);
        glVertex2d(100, 372);
        glVertex2d(120, 372);
        glVertex2d(100, 388);

        glVertex2d(150, 388);
        glVertex2d(130, 372);
        glVertex2d(150, 372);
        glVertex2d(130, 388);

        glEnd();


    }
    else {
        if (powerUpActivated)
            glColor3f(1, 0, 0.1);
        else
            glColor3d(0, 0, 0);
        //body
        glBegin(GL_QUADS);
        glVertex2d(100, 350 + birdMovementY);
        glVertex2d(150, 350 + birdMovementY);
        glVertex2d(150, 400 + birdMovementY);
        glVertex2d(100, 400 + birdMovementY);
        glEnd();

        //Mouth

        glBegin(GL_POLYGON);
        glColor3d(0.9, 0.5, 0.5);

        glVertex2d(115, 365 + birdMovementY);
        glVertex2d(135, 365 + birdMovementY);
        glVertex2d(130, 355 + birdMovementY);
        glVertex2d(120, 355 + birdMovementY);


        glEnd();

        //whiskers

        glBegin(GL_LINES);
        glColor3d(1, 1, 1);
        glVertex2d(125, 364 + birdMovementY);
        glVertex2d(95, 355 + birdMovementY);

        glVertex2d(125, 364 + birdMovementY);
        glVertex2d(95, 370 + birdMovementY);

        glVertex2d(125, 364 + birdMovementY);
        glVertex2d(155, 370 + birdMovementY);

        glVertex2d(125, 364 + birdMovementY);
        glVertex2d(155, 355 + birdMovementY);
        glEnd();
        //ears
        glColor3d(0, 0, 0);

        glBegin(GL_TRIANGLES);
        glVertex2d(100, 400 + birdMovementY);
        glVertex2d(120, 400 + birdMovementY);
        glVertex2d(110, 425 + birdMovementY);

        glVertex2d(130, 400 + birdMovementY);
        glVertex2d(150, 400 + birdMovementY);
        glVertex2d(140, 425 + birdMovementY);

        glColor3d(0.9, 0.5, 0.5);
        glVertex2d(104, 400 + birdMovementY);
        glVertex2d(116, 400 + birdMovementY);
        glVertex2d(110, 420 + birdMovementY);

        glVertex2d(134, 400 + birdMovementY);
        glVertex2d(146, 400 + birdMovementY);
        glVertex2d(140, 420 + birdMovementY);
        glEnd();



        //eyes

        glPushMatrix();
        glColor3f(1, 1, 1);

        glTranslatef(110, 380 + birdMovementY, 0);
        GLUquadric* quadObj = gluNewQuadric();
        gluDisk(quadObj, 5, 10, 50, 50);
        glPopMatrix();


        glPushMatrix();
        glColor3f(1, 1, 1);

        glTranslatef(140, 380 + birdMovementY, 0);
        quadObj = gluNewQuadric();
        gluDisk(quadObj, 5, 10, 50, 50);
        glPopMatrix();


    }
     glutPostRedisplay();

     
    
}



//this is the method used to print text in OpenGL
//there are three parameters,
//the first two are the coordinates where the text is display,
//the third coordinate is the string containing the text to display
void print(int x, int y, char* string)
{
    int len, i;

    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x, y);

    //get the length of the string to display
    len = (int)strlen(string);

    //loop to display character by character
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}



void Timer(int value) {
    if (!gameOver) {
        if (powerUpActivated)
            powerUpActivated = false;
        nextSet = rand() % 4 + 1;
        xMovement = 0;
        if (nextSet == 4)
            powerR = rand() % 495 + 105.0;
    }
    glutTimerFunc(15 * 1000, Timer, 0);
}

void actM(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        birdMovementY += 100;
        //accelerationY = 0;
        PlaySound(TEXT("catJump.wav"), NULL, SND_ASYNC);
    }
    glutPostRedisplay();
}

void jump(unsigned char key,  int x, int y) {
    if (key == ' ') {
        birdMovementY += 100;
        PlaySound(TEXT("catJump.wav"), NULL, SND_ASYNC);

       // accelerationY = 0;
    }
    glutPostRedisplay();

}

void powerup() {

    if (!powerUpActivated) {
        glColor3d(1, 0.8, 0);

        glBegin(GL_TRIANGLES);
        glVertex2d(105 + xMovement + 800, powerR + 10);
        glVertex2d(195 + xMovement + 800, powerR + 10);
        glVertex2d(150 + xMovement + 800, powerR + 60);

        glVertex2d(150 + xMovement + 800, powerR);
        glVertex2d(195 + xMovement + 800, powerR + 50);
        glVertex2d(105 + xMovement + 800, powerR + 50);
        glEnd();


        glPushMatrix();
        glTranslated(150 + xMovement + 800, 30 + powerR, 0);
        glRotated(angle, 0, 0, 1);
        glTranslated(-950 - xMovement, -30 - powerR, 0);

        glBegin(GL_LINES);
        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(190 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, 70 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(110 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, powerR - 10);



        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslated(150 + xMovement + 800, 30 + powerR, 0);
        glRotated(angle2, 0, 0, 1);
        glTranslated(-950 - xMovement, -30 - powerR, 0);

        glBegin(GL_LINES);
        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(190 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, 70 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(110 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, powerR - 10);



        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPushMatrix();
        glTranslated(150 + xMovement + 800, 30 + powerR, 0);
        glRotated(angle3, 0, 0, 1);
        glTranslated(-950 - xMovement, -30 - powerR, 0);

        glBegin(GL_LINES);
        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(190 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, 70 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(110 + xMovement + 800, 30 + powerR);

        glVertex2d(150 + xMovement + 800, 30 + powerR);
        glVertex2d(150 + xMovement + 800, powerR - 10);



        glEnd();
        glPopMatrix();
    }
    glutPostRedisplay();



}

void GameOver() 
{
    gameOver = true;
    birdMovementY = -900;
    glColor3f(1, 0, 0);
    char* p0s[20];
    sprintf((char*)p0s, "GAME OVER");
    print(300, 350, (char*)p0s);
    
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
   
    


    if (nextSet == 1)
        set1();
    else if (nextSet == 2)
        set2();
    else if (nextSet == 3)
        set3();
    else {
        setPower();
        powerup();
      }
    bird();
   

    glColor3f(0, 0, 0);
    char* p0s[20];
    sprintf((char*)p0s, "%d", currentScore);
    print(370, 750, (char*)p0s);


    //glColor3f(0.9, 0.8, 0);
     p0s[25]; 
    sprintf((char*)p0s, "lives: %d", lives);
    print(620, 700, (char*)p0s);

    //Game over
    if (birdMovementY < -350 || birdMovementY > 375) {
        GameOver();
    }

    if (gameOver && playOnce) {
        PlaySound(NULL, NULL, SND_SYNC);
        PlaySound(TEXT("gameOver.wav"), NULL, SND_ASYNC);
        playOnce = false;
   }
    
    //collision

    if (nextSet == 1) {
        //block1
        if ((birdMovementY <= -200 || birdMovementY >= -25) && birdMovementY > -900) {
            if (xMovement <= -650 && xMovement >= -800) {
                //hit
                lives -= 1;

                if (lives < 1) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = -100;
                }
            }

        }

        //block2
        if ((birdMovementY <= -50 || birdMovementY >= 125 ) && birdMovementY > -900) {
            if (xMovement <= -1000 && xMovement >= -1200) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = 25;
                }
            }

        }

        //block3
        if ((birdMovementY <= 0 || birdMovementY >= 175) && birdMovementY > -900) {
            if (xMovement <= -1250 && xMovement >= -1450) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = 75;
                }
            }

        }
    }

    if (nextSet == 2) {
        //block1
        if ((birdMovementY <= -250 || birdMovementY >= -25) && birdMovementY > -900) {
            if (xMovement <= -650 && xMovement >= -850) {
                //hit
                lives -= 1;
                if (lives < 1) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = -200;
                }
            }

        }

        //block2
        if ((birdMovementY <= 50 || birdMovementY >= 335) && birdMovementY > -900) {
            if (xMovement <= -1075 && xMovement >= -1175) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = 150;
                }
            }

        }

        //block3
        if ((birdMovementY <= -200 || birdMovementY >= 30) && birdMovementY > -900) {
            if (xMovement <= -1320 && xMovement >= -1500) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = -150;
                }
            }

        }
    }

    if (nextSet == 3) {
        //block1
        if ((birdMovementY <= -150 || birdMovementY >= 125) && birdMovementY > -900) {
            if (xMovement <= -650 && xMovement >= -850) {
                //hit
                lives -= 1;
                if (lives <1) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = -50;
                }
            }

        }

        //block2
        if ((birdMovementY <= 150 || birdMovementY >= 335 ) && birdMovementY > -900) {
            if (xMovement <= -1050 && xMovement >= -1200) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = 250;
                }
            }

        }

        //block3
        if ((birdMovementY <= -10 || birdMovementY >= 255) && birdMovementY > -900) {
            if (xMovement <= -1250 && xMovement >= -1500) {
                //hit
                lives -= 1;
                if (lives == 0) { //game over
                    GameOver();
                }
                else {
                    birdMovementY = 50;
                }
            }

        }
    }

    if (nextSet == 4) {
        //block1
        if ((xMovement <= -750 && xMovement >= -900) && ((birdMovementY + 350 >= powerR && birdMovementY + 290 <= powerR) || (birdMovementY + 425 >= powerR && birdMovementY + 365 <= powerR))) {
            powerUpActivated = true;
            glColor3f(1, 0, 0);
            char* p0s[20];
            sprintf((char*)p0s, "POWER UP!");
            print(300, 350, (char*)p0s);

        }
        else {
            if ((birdMovementY <= -250 || birdMovementY >= 275) && birdMovementY > -900 ) {
                if (xMovement <= -750 && xMovement >= -900 ) {
                    if (powerUpActivated)
                        birdMovementY = 60;
                    else {
                        //hit
                        lives -= 1;
                        if (lives < 1) { //game over
                            GameOver();
                        }
                        else {
                            birdMovementY = 60;
                        }
                    }
                }

            }

            //block2
            if ((birdMovementY <= 50 || birdMovementY >= 185) && birdMovementY > -900 ) {
                if (xMovement <= -1050 && xMovement >= -1200) {
                    if (powerUpActivated)
                        birdMovementY = 150;
                    else {
                        //hit
                        lives -= 1;
                        if (lives == 0) { //game over
                            GameOver();
                        }
                        else {
                            birdMovementY = 150;
                        }
                    }
                }


            }

            //block3
            if ((birdMovementY <= 150 || birdMovementY >= 275) && birdMovementY > -900 ) {
                if (xMovement <= -1300 && xMovement >= -1500 ) {
                    if (powerUpActivated)
                        birdMovementY = 200;
                    else {
                        //hit
                        lives -= 1;
                        if (lives == 0) { //game over
                            GameOver();
                        }
                        else {
                            birdMovementY = 200;
                        }
                    }
                }
            }
        }
    }




    glutPostRedisplay();
    glFlush();
}

void Anim() {
   // accelerationY += 0.0002;
    birdMovementY -= 0.2 ;
    if(!gameOver)
       xMovement -= 0.15;
    angle += 2;
    angle2 += 3;
    angle3 += 4;

   

    glutPostRedisplay();
}

void Timer2(int value) {
    if(!gameOver)
       currentScore += 1;
    glutTimerFunc(2 * 1000, Timer2, 0);

}

void main(int argc, char** argr) {
    glutInit(&argc, argr);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);



    glutCreateWindow("Flappy Bird");
     glutDisplayFunc(Display);
     glutIdleFunc(Anim);
     srand(time(0));

     glutTimerFunc(0, Timer, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)
     glutTimerFunc(7000, Timer2, 0); // sets the Timer handler function; which runs every `Threshold` milliseconds (1st argument)

     glutMouseFunc(actM);
     glutKeyboardFunc(jump);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(0, 800, 0, 800);

    glutMainLoop();
}