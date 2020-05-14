#include "declaration.h"
#include "header.h"



void myinit(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
}


void mydisplay()
{
	if(windowFlag){
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(125.0,470.0);
		for(i=0;i<strlen(str1);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
		glutPostRedisplay();

		glColor3f(0.0,0.0,1.0);
		glRasterPos2f(165.0,445.0);
		for(i=0;i<strlen(str2);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
		glutPostRedisplay();


		glColor3f(1.0,0.0,1.0);
		glRasterPos2f(110.0,410.0);
		for(i=0;i<strlen(str3);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[i]);
		glutPostRedisplay();

		glColor3f(1.0,0.0,1.0);
		glRasterPos2f(140.0,385.0);
		for(i=0;i<strlen(str5);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i]);
		glutPostRedisplay();

		glColor3f(1.0,0.2,0.1);
		glRasterPos2f(190.0,340.0);
		for(i=0;i<strlen(str4);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[i]);
		glutPostRedisplay();

		glColor3f(0.2,0.8,0.4);
		glRasterPos2f(170.0,300.0);
		for(i=0;i<strlen(str6);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str6[i]);
		glutPostRedisplay();

		glColor3f(0.2,0.0,0.9);
		glRasterPos2f(20.0,150.0);
		for(i=0;i<strlen(str8);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str8[i]);
		glutPostRedisplay();

		glColor3f(0.4,0.0,0.3);
		glRasterPos2f(20.0,130.0);
		for(i=0;i<strlen(str9);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str9[i]);
		glutPostRedisplay();

		glColor3f(0.4,0.0,0.3);
		glRasterPos2f(20.0,110.0);
		for(i=0;i<strlen(str10);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str10[i]);
		glutPostRedisplay();

		glColor3f(0.8,0.0,0.001);
		glRasterPos2f(20.0,90.0);
		for(i=0;i<strlen(str11);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str11[i]);
		glutPostRedisplay();



		glColor3f(0.2,0.0,0.9);
		glRasterPos2f(350.0,150.0);
		for(i=0;i<strlen(str12);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str12[i]);
		glutPostRedisplay();

		glColor3f(0.4,0.0,0.3);
		glRasterPos2f(350.0,130.0);
		for(i=0;i<strlen(str13);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str13[i]);
		glutPostRedisplay();

		glColor3f(0.4,0.0,0.3);
		glRasterPos2f(350.0,110.0);
		for(i=0;i<strlen(str14);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str14[i]);
		glutPostRedisplay();

		glColor3f(0.8,0.0,0.001);
		glRasterPos2f(350.0,90.0);
		for(i=0;i<strlen(str15);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str15[i]);
		glutPostRedisplay();

		if(j<5)
		{

		glColor3f(0.2,0.8,0.4);
		glRasterPos2f(200.0,20.0+j);
		for(i=0;i<strlen(str7);i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str7[i]);
		glutPostRedisplay();
		j=j+0.01;
		}
		else
			j=0.0;

	}
	glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	firstWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(mydisplay);
	glutMouseFunc(click);
	myinit();
	createHelpWindow();
	PlaySound(TEXT("sing.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	glutMainLoop();
}




void click(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && windowFlag)
	{
		windowFlag=0;
		createNewWindow();
	}
	glutPostRedisplay();
}


void keySecond(unsigned char key,int x,int y)
{
	if(key=='x'||key=='X')
		exit(0);
	if(key=='d'||key=='D')
		flag5=1;
	if(key=='a'||key=='A')
		flag5=0;
	if(key=='w' && yMove<50)
		yMove+=0.1;
	if(key=='s' && yMove>0)
		yMove-=0.1;
	if(key=='f' || key =='F')
	{
		flagThirdScene=1;
		PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC| SND_LOOP);
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
}


void createNewWindow()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(firstWindow);
	secondWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(mydisplaySecondWindow);
	glutKeyboardFunc(keySecond);
	initSecondWindow();
}


void mydisplaySecondWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();

	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	//Motion to woodcutter that is 'd' or else 'a' stop
	//flag5 is set on 'd' and unset on 'a'
	if( j<250 && flag5==1)
	{
		cutter(100+j,200+yMove);
		if(alpha>=0.0 && alpha<50.0){
            rightleg(100+j,200+yMove);
            leftleg(100+j,200+yMove);
            alpha+=1.0;
		}
		else if(alpha>=25.0){
            moverightlegs(100+j,200+yMove);
            moveleftlegs(100+j,200+yMove);
            alpha+=1.0;
		}
		if(alpha>60){
            alpha=0.0;
		}
		j+=0.5;
		displayHelp("A to Stop",1000,100);
		displayHelp("W to up",1000,70);
		displayHelp("S to down",1000,40);
	}
	else if( j<250)
	{
		cutter(100+j,200+yMove);
		displayHelp("D to Move",1000,100);
		displayHelp("W to up",1000,70);
		displayHelp("S to down",1000,40);
	}
	else
	{
		cutter(350,200+yMove);
		displayHelp("Press F",1000,100);
	}
		glutPostRedisplay();


	if(j>250.0 && flagThirdScene)
	{
		createThirdWindow();
	}
	glFlush();

}

void key(unsigned char key,int x,int y)
{
	if(key=='x'||key=='X')
		exit(0);


}

void initSecondWindow(void)
{

	glClearColor(0.7,0.8,0.98,0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawTree(void)
{
	//Draws the base of the tree
	glBegin(GL_POLYGON);
		glColor3f(0.5450,0.2705,0.0745);
		glVertex2f(300,200);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(600,200);
		glColor3f(0.5450,0.2705,0.0745);
		glVertex2f(550,250);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(350,250);
	glEnd();

	//Draws the stem of the tree
	glColor3f(0.406374,0.203187,0);
	glBegin(GL_POLYGON);
		glVertex2f(350,250);
		glVertex2f(350,400);
		glVertex2f(550,400);
		glVertex2f(550,250);
	glEnd();

	//Draws the upwards branch of the tree
	glBegin(GL_POLYGON);
		glVertex2f(350,400);
		glVertex2f(350,550);
		glVertex2f(500,550);
		glVertex2f(500,400);
	glEnd();

	//Draws the left branch of the tree
	glBegin(GL_POLYGON);
		glVertex2f(350,400);
		glVertex2f(225,450);
		glVertex2f(225,500);
		glVertex2f(350,450);
	glEnd();


	//Draws the Right side branch of the tree
	glBegin(GL_POLYGON);
		glVertex2f(500,375);
		glVertex2f(500,450);
		glVertex2f(725,525);
		glVertex2f(725,450);
	glEnd();


	//Draws the small upwards branch of the tree
	glBegin(GL_POLYGON);
		glVertex2f(725,525);
		glVertex2f(700,500);
		glVertex2f(700,575);
		glVertex2f(725,575);
	glEnd();


	//Draws the junction of the small branches
	glBegin(GL_POLYGON);
		glVertex2f(725,475);
		glVertex2f(725,525);
		glVertex2f(750,525);
		glVertex2f(775,500);
		glVertex2f(750,480);
		glVertex2f(725,475);
	glEnd();

	//Draws the Right side upwards small branch
	glColor3f(0.406374,0.203187,0);
	glBegin(GL_POLYGON);
		glVertex2f(775,500);
		glVertex2f(750,525);
		glVertex2f(800,545);
		glVertex2f(800,525);
	glEnd();


	//Draws the bigger leaf
	//glColor3f(0.1,0.6324,0.1);
	//glColor3f0.231075,0.372549,0.043137);
	glColor3f(0.01854,1.0,0.185465);
	glBegin(GL_POLYGON);
		glVertex2f(350,525);
		glVertex2f(300,525);
		glVertex2f(250,475);
		glVertex2f(200,425);
		glVertex2f(150,425);
		glVertex2f(125,475);
		glVertex2f(125,600);
		glVertex2f(200,650);
		glVertex2f(500,700);
		//glColor3f(0.2,0.9,0.3);
		glVertex2f(550,675);
		glVertex2f(650,650);
		glVertex2f(700,600);
		glVertex2f(700,575);
		glVertex2f(650,550);
		glVertex2f(550,550);
		glVertex2f(500,525);
		glVertex2f(350,525);
	glEnd();

	//Draws the smaller leaf
	//glColor3f(0.231075,0.672548,0.043137);
	glBegin(GL_POLYGON);
		glVertex2f(700,600);
		glVertex2f(700,575);
		glVertex2f(750,550);
		glVertex2f(825,500);
		glVertex2f(850,475);
		glVertex2f(875,475);
		glVertex2f(875,525);
		//glColor3f(0.2,0.9,0.3);
		glVertex2f(800,600);
		glVertex2f(750,625);
		glVertex2f(700,600);
	glEnd();

	//drawLeafTriangles();
	//drawTreeEdges();
}


void drawWater(void)
{

	glColor3f(0.0,0.4,1.0);

	//Draws the lower half of the water
	glBegin(GL_POLYGON);
		glVertex2f(1300,175);
		glVertex2f(1300,0);
		glVertex2f(0,0);
		glVertex2f(0,50);
		glVertex2f(50,50);
		glVertex2f(150,75);
		glVertex2f(250,100);
		glVertex2f(500,100);
		glVertex2f(600,90);
		glVertex2f(700,125);
		glVertex2f(825,175);
		glVertex2f(1300,175);
	glEnd();

	//Draws the upper half of the water
	glBegin(GL_POLYGON);
		glVertex2f(1300,175);
		glVertex2f(825,175);
		glVertex2f(600,250);
		glVertex2f(600,300);
		glVertex2f(800,450);
		glVertex2f(1300,450);
	glEnd();
}

void drawLand(void)
{
	glColor3f(0.231075,0.372549,0.043137);

	//Draws the landscape
	glBegin(GL_POLYGON);
		glVertex2f(0,50);
		glVertex2f(1300,50);
		glVertex2f(1300,550);
		glVertex2f(0,550);
	glEnd();
}


void drawGrasses(void)
{
	drawGrass(50,-10);
	drawGrass(200,210);
	drawGrass(50,500);
	drawGrass(600,135);
	drawGrass(700,155);
	drawGrass(1000,500);
	drawGrass(1200,460);
}


void drawGrass(int x,int y)
{
	glColor3f(0.1,0.6324,0.1);
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y);
	glVertex2f(x+25,y);
	glVertex2f(x-25,y+100);
	glVertex2f(x+25,y);
	glVertex2f(x+50,y);
	glVertex2f(x+25,y+100);
	glEnd();
}

void drawTreeEdges(void)
{

	float r=50.0;
	float i;
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((300+r*cos(i)),(525+r*sin(i)));
	glEnd();


	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((275+r*cos(i)),(450+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((250+r*cos(i)),(425+r*sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((225+r*cos(i)),(435+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((150+r*cos(i)),(450+r*sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((150+r*cos(i)),(500+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((150+r*cos(i)),(525+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((200+r*cos(i)),(600+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((150+r*cos(i)),(550+r*sin(i)));
	glEnd();
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((250+r*cos(i)),(600+r*sin(i)));
	glEnd();

	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((250+r*cos(i)),(625+r*sin(i)));
	glEnd();
}



void cutter(float x,float y)
{




	//Draws the face
	float radius = 35.0;
	glColor3f(1.0,0.90,0.85);

	glBegin(GL_POLYGON);
		for(float i=0;i<360;i+=0.1)
			glVertex2f(cos(i)*radius+x,sin(i)*radius+y+150);
	glEnd();

	radius=6.0;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();

	radius=3.0;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();


	//Hair of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-35,y+150);
		glVertex2f(x-35,y+170);
		glVertex2f(x-25,y+195);
		glVertex2f(x+40,y+195);
		glVertex2f(x+35,y+175);
		glVertex2f(x+20,y+170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-10.0,y+100.0);
		glVertex2f(x-10.0,y+120.0);
		glVertex2f(x+10.0,y+120.0);
		glVertex2f(x+10.0,y+100.0);
	glEnd();


	//Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y+90);
		glVertex2f(x+10,y+100);
		glVertex2f(x+50,y+85);
		glVertex2f(x+50,y+75);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+75);
		glVertex2f(x+50,y+85);
		glVertex2f(x+75,y+105);
		glVertex2f(x+75,y+95);
	glEnd();



	//Draws the red shirt of woodcutter
	glColor3f(0.8,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+75);
		glVertex2f(x-10,y+100);
		glVertex2f(x+10,y+100);
		glVertex2f(x+25,y+75);
		glVertex2f(x+25,y);
	glEnd();



//Draws the left leg of the wood cutter
/*	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-15,y-75);
		glVertex2f(x-15,y);
		glVertex2f(x-5,y);
		glVertex2f(x-5,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-15,y-75);
		glVertex2f(x-5,y-65);
		glVertex2f(x+15,y-70);
		glVertex2f(x+15,y-75);
	glEnd();

	//Draws the right leg of the woodcutter

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y-75);
		glVertex2f(x+10,y);
		glVertex2f(x+20,y);
		glVertex2f(x+20,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y-75);
		glVertex2f(x+20,y-65);
		glVertex2f(x+40,y-70);
		glVertex2f(x+40,y-75);
	glEnd();
*/
	//Draws the shoes of woodcutter



	//Draws the trousers of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+25);
		glVertex2f(x+25,y+25);
		glVertex2f(x+25,y);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x-25,y-30);
		glVertex2f(x-25,y);
		glVertex2f(x-2,y);
		glVertex2f(x-2,y-30);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+4,y-30);
		glVertex2f(x+4,y);
		glVertex2f(x+25,y);
		glVertex2f(x+25,y-30);
	glEnd();



	//Draws the right hand of the woodcutter
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x,y+70);
		glVertex2f(x,y+80);
		glVertex2f(x+55,y+65);
		glVertex2f(x+55,y+55);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+55,y+55);
		glVertex2f(x+55,y+65);
		glVertex2f(x+80,y+95);
		glVertex2f(x+80,y+85);
	glEnd();


	//Draws the mouth of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+25,y+125);
		glVertex2f(x+10,y+125);
		glVertex2f(x+10,y+127);
	glEnd();

	//Draws the Nose of the woodcutter

	glBegin(GL_LINE_STRIP);
		glVertex2f(x+32,y+140);
		glVertex2f(x+32,y+150);
		glVertex2f(x+34,y+155);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2f(x-10,y+160);
		glVertex2f(x-20,y+160);
		glVertex2f(x-20,y+140);
		glVertex2f(x-10,y+140);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(x-20,y+150);
		glVertex2f(x-10,y+150);
	glEnd();


	//Draws the axe
	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x-95,y+95);
		glVertex2f(x-95,y+105);
		glVertex2f(x+95,y+105);
		glVertex2f(x+95,y+95);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-90,y+65);
		glVertex2f(x-90,y+115);
		glVertex2f(x-60,y+115);
		glVertex2f(x-60,y+65);
	glEnd();

	//Draws the Right palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+80,y+85);
		glVertex2f(x+80,y+105);
		glVertex2f(x+90,y+105);
		glVertex2f(x+90,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+80,y+105);
		glVertex2f(x+80,y+100);
		glVertex2f(x+82.5,y+105);
		glVertex2f(x+82.5,y+100);
		glVertex2f(x+85,y+105);
		glVertex2f(x+85,y+100);
		glVertex2f(x+87,y+105);
		glVertex2f(x+87,y+100);
		glVertex2f(x+89.5,y+105);
		glVertex2f(x+89.5,y+100);
	glEnd();

	//Draws the left palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+65,y+95);
		glVertex2f(x+65,y+105);
		glVertex2f(x+75,y+105);
		glVertex2f(x+75,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+65,y+105);
		glVertex2f(x+65,y+100);
		glVertex2f(x+67.5,y+105);
		glVertex2f(x+67.5,y+100);
		glVertex2f(x+70,y+105);
		glVertex2f(x+70,y+100);
		glVertex2f(x+72.5,y+105);
		glVertex2f(x+72.5,y+100);
		glVertex2f(x+74.5,y+105);
		glVertex2f(x+74.5,y+100);
	glEnd();

}




void createHelpWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,700);
	glutInitWindowPosition(1000,0);
	secondWindow=glutCreateWindow("Help");
	glutDisplayFunc(displayHelpWindow);
	myinit();
	//glutKeyboardFunc(key);
}

void displayHelpWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	displayHelp(strD,50.0,475.0);
	displayHelp(strA,50.0,450.0);
	displayHelp(strS,50.0,425.0);
	displayHelp(strF,50.0,400.0);
	displayHelp(strT,50.0,375.0);
	displayHelp(strY,50.0,350.0);
	displayHelp(strB,50.0,325.0);
	displayHelp(strN,50.0,300.0);
	displayHelp(strJ,50.0,275.0);
	displayHelp(strK,50.0,250.0);
	glFlush();
}

void createThirdWindow()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(secondWindow);
	thirdWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(mydisplayThirdWindow);
	//while(flagPlayAxe)
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	initSecondWindow();
	glutKeyboardFunc(keyThird);
	glutMainLoop();
}

void keyThird(unsigned char key,int x,int y)
{
	if(key=='x'||key=='X')
		exit(0);
	if(key=='t' || key == 'T' && flagFourthScene)
	{
		flagFourthScene=0;
		createFourthWindow();
		flagPlayAxe=false;
		PlaySound(TEXT("sound.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	//if(key=='r')
		//PlaySound(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
}




void mydisplayThirdWindow()
{
	int count=0;
	int flag=0;
	////(TEXT("cow.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	////(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();


	drawWoodcutterOnTree(550.0,450.0);

	glPushMatrix();
	//drawAxeDown(550,450);
	if(theta>=0.0 && theta<50.0)
	{
		drawAxeUp(550,450);
		theta+=1.0;
	}
	else if(theta>=50.0)
	{
		glPushMatrix();
		glTranslatef(0.0,-10.0,0.0);
		drawAxeDown(550,450);
		glPopMatrix();
		theta+=1.0;
		//(TEXT("Axe.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	}
	if(theta>100.0)
	{
		theta=0.0;
	}
	displayHelp("Press T",1000,100);
	glutPostRedisplay();
}

void drawWoodcutterOnTree(float x, float y)
{
	//Draws the face
	float radius = 35.0;
	glColor3f(1.0,0.90,0.85);

	glBegin(GL_POLYGON);
		for(float i=0;i<360;i+=0.1)
			glVertex2f(cos(i)*radius+x,sin(i)*radius+y+150);
	glEnd();

	radius=6.0;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();

	radius=3.0;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();


	//Hair of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-35,y+150);
		glVertex2f(x-35,y+170);
		glVertex2f(x-25,y+195);
		glVertex2f(x+40,y+195);
		glVertex2f(x+35,y+175);
		glVertex2f(x+20,y+170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-10.0,y+100.0);
		glVertex2f(x-10.0,y+120.0);
		glVertex2f(x+10.0,y+120.0);
		glVertex2f(x+10.0,y+100.0);
	glEnd();


	//Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y+90);
		glVertex2f(x+10,y+100);
		glVertex2f(x+50,y+85);
		glVertex2f(x+50,y+75);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+75);
		glVertex2f(x+50,y+85);
		glVertex2f(x+75,y+115);
		glVertex2f(x+75,y+105);
	glEnd();



	//Draws the red shirt of woodcutter
	glColor3f(0.8,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+75);
		glVertex2f(x-10,y+100);
		glVertex2f(x+10,y+100);
		glVertex2f(x+25,y+75);
		glVertex2f(x+25,y);
	glEnd();

		//Draws the mouth of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+25,y+125);
		glVertex2f(x+10,y+125);
		glVertex2f(x+10,y+127);
	glEnd();

	//Draws the Nose of the woodcutter

	glBegin(GL_LINE_STRIP);
		glVertex2f(x+32,y+140);
		glVertex2f(x+32,y+150);
		glVertex2f(x+34,y+155);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2f(x-10,y+160);
		glVertex2f(x-20,y+160);
		glVertex2f(x-20,y+140);
		glVertex2f(x-10,y+140);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(x-20,y+150);
		glVertex2f(x-10,y+150);
	glEnd();

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x,y+70);
		glVertex2f(x,y+80);
		glVertex2f(x+55,y+65);
		glVertex2f(x+55,y+55);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+55,y+55);
		glVertex2f(x+55,y+65);
		glVertex2f(x+80,y+95);
		glVertex2f(x+80,y+85);
	glEnd();

	//Drwas the trousers of woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+30);
		glVertex2f(x+25,y+30);
		glVertex2f(x+25,y);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+25,y);
		glVertex2f(x+25,y+26);
		glVertex2f(x+50,y+26);
		glVertex2f(x+50,y);
	glEnd();

	//Draws the leg

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+8);
		glVertex2f(x+50,y+18);
		glVertex2f(x+75,y+18);
		glVertex2f(x+75,y+8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+75,y-42);
		glVertex2f(x+75,y+18);
		glVertex2f(x+85,y+18);
		glVertex2f(x+85,y-42);
	glEnd();

	//glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+85,y-42);
		glVertex2f(x+85,y-32);
		glVertex2f(x+95,y-37);
		glVertex2f(x+95,y-42);
	glEnd();

	//Draws the left leg

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y-50);
		glVertex2f(x+50,y-40);
		glVertex2f(x+60,y-35);
		glVertex2f(x+60,y-50);
	glEnd();

	//glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+60,y-50);
		glVertex2f(x+60,y-40);
		glVertex2f(x+70,y-45);
		glVertex2f(x+70,y-50);
	glEnd();
	glColor3f(1.0,0.90,0.85);
	//Draws the axe
/*	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+100);
		glVertex2f(x+50,y+110);
		glVertex2f(x+150,y+110+yAxe);
		glVertex2f(x+150,y+100+yAxe);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+115,y+70+yAxe);
		glVertex2f(x+115,y+120+yAxe);
		glVertex2f(x+140,y+120+yAxe);
		glVertex2f(x+140,y+70+yAxe);
	glEnd();
	*/

	//Draws the Right palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+80,y+85);
		glVertex2f(x+80,y+105);
		glVertex2f(x+90,y+105);
		glVertex2f(x+90,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+80,y+105);
		glVertex2f(x+80,y+100);
		glVertex2f(x+82.5,y+105);
		glVertex2f(x+82.5,y+100);
		glVertex2f(x+85,y+105);
		glVertex2f(x+85,y+100);
		glVertex2f(x+87,y+105);
		glVertex2f(x+87,y+100);
		glVertex2f(x+89.5,y+105);
		glVertex2f(x+89.5,y+100);
	glEnd();

	//Draws the left palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+65,y+95);
		glVertex2f(x+65,y+105);
		glVertex2f(x+75,y+105);
		glVertex2f(x+75,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+65,y+105);
		glVertex2f(x+65,y+100);
		glVertex2f(x+67.5,y+105);
		glVertex2f(x+67.5,y+100);
		glVertex2f(x+70,y+105);
		glVertex2f(x+70,y+100);
		glVertex2f(x+72.5,y+105);
		glVertex2f(x+72.5,y+100);
		glVertex2f(x+74.5,y+105);
		glVertex2f(x+74.5,y+100);
	glEnd();
}

void drawAxeUp(float x,float y)
{
	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+100);
		glVertex2f(x+50,y+110);
		glVertex2f(x+150,y+160);
		glVertex2f(x+150,y+150);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+115,y+145);
		glVertex2f(x+150,y+160);
		glVertex2f(x+175,y+120);
		glVertex2f(x+155,y+100);
	glEnd();
}

void drawAxeDown(float x,float y)
{
	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+100);
		glVertex2f(x+50,y+110);
		glVertex2f(x+150,y+110);
		glVertex2f(x+150,y+100);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+115,y+70);
		glVertex2f(x+115,y+120);
		glVertex2f(x+140,y+120);
		glVertex2f(x+140,y+70);
	glEnd();
}

void createFourthWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	fourthWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDestroyWindow(thirdWindow);
	glutDisplayFunc(mydisplayFourthWindow);
	PlaySound(TEXT("sound.wav"),  NULL, SND_FILENAME | SND_ASYNC);
	glutKeyboardFunc(keyFourth);
	initSecondWindow();

}

void keyFourth(unsigned char key,int x,int y)
{
	if(key=='t' || key == 'T' && flagFourthScene)
	{
		flagFourthScene=0;
		createFourthWindow();
	}
	if(key=='x'||key=='X')
		exit(0);

	if(key=='g' || key== 'G')
		flagMoveDownAxe=1;

	if(key=='y' || key== 'Y')
		flagFifthScene=1;
}

void mydisplayFourthWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	drawWoodcutterOnTree(550.0,450.0);

	if(moveAxeY<200 && flagMoveDownAxe)
	{
		moveDownAxe(650.0,450.0-moveAxeY);
		displayText();
		moveAxeY+=1.0;
	}
	else if(moveAxeY<200)
	{
		moveDownAxe(650.0,450.0);
		displayHelp("Press G",1000,100);
	}
	else if(moveAxeY>=200 && flagFifthScene)
	{
		createFifthWindow();
		flagFifthScene=0;
	}
	else if(moveAxeY>=200 && !flagFifthScene)
	{
		displayTextGod();
		displayHelp("Press Y",1000.0,100.0);
	}

	glutPostRedisplay();
	glFlush();
}

void displayText()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(700,600);
		glVertex2f(750,650);
		glVertex2f(850,650);
		glVertex2f(850,550);
		glVertex2f(750,550);
	glEnd();

	displayHelp("What have I",720,600);
	displayHelp("done...???",750,575);
}

void displayTextGod()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(700,600);
		glVertex2f(750,650);
		glVertex2f(850,650);
		glVertex2f(850,550);
		glVertex2f(750,550);
	glEnd();

	displayHelp("Oho God....",720,600);

}

void moveDownAxe(float x,float y)
{
	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x-10,y);
		glVertex2f(x-10,y+100);
		glVertex2f(x,y+100);
		glVertex2f(x,y);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-20,y+10);
		glVertex2f(x-20,y+35);
		glVertex2f(x+25,y+35);
		glVertex2f(x+25,y+10);
	glEnd();
}

void keySixth(unsigned char key,int x,int y)
{
	if(key=='b'||key=='B')
	{
		createSeventhWindow();
	}
	if(key=='x'||key=='X')
		exit(0);
}

void createFifthWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	//glutInitWindowSize(1900,1200);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(fourthWindow);
	fifthWindow=glutCreateWindow("Miracle:Honest Woodcutter");


	glutDisplayFunc(mydisplayFifthWindow);
	initSecondWindow();
	glutKeyboardFunc(key);
}

void mydisplayFifthWindow(void)
{

	moveAxeInWater+=1.0;
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
	drawUnderWater();

    plant();
    eli();
    glPopMatrix();

	if(moveAxeInWater<500)
	{
		moveDownAxe(600,750-moveAxeInWater);
		moveAxeInWater+=1.0;
	}
	else if(moveAxeInWater>500)
	{
		drawAxeInWater(600.0,250.0);
	}
    draw_bubble(bmove);
	drawFishes(moveFishes);
    bmove+=1.0;
	moveFishes+=1.0;
	glutPostRedisplay();
	glFlush();

	if(moveFishes==800.0)
		createSixthWindow();
}

void drawUnderWater(void)
{
	glClearColor(0.0,0.4,0.8,1.0);
	drawStone();
}

void drawStone(void)
{
	glColor3f(0.862745,0.862745,0.862745);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,300);
		glVertex2f(300,200);
		glVertex2f(500,250);
		glVertex2f(600,250);
		glVertex2f(1000,350);
		glVertex2f(1300,350);
		glVertex2f(1300,0);
		glVertex2f(0,0);
	glEnd();
}

void drawAxeInWater(float x,float y)
{
	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x-150,y);
		glVertex2f(x-150,y+10);
		glVertex2f(x,y+10);
		glVertex2f(x,y);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-35,y-10);
		glVertex2f(x-35,y+35);
		glVertex2f(x-10,y+35);
		glVertex2f(x-10,y-10);
	glEnd();
}

void drawFishes(float xMove)
{
	glColor3f(1.0,0.6,0.0);
	drawFish(500.0-xMove,500.0);

	glColor3f(1.0,0.85,0.0);
	drawFish(700.0-xMove,600.0);

	glColor3f(0.8,0.4,0.0);
	drawFish(1200.0-xMove,650.0);

	glColor3f(0.0,0.2,0.98);
	drawFish(300.0-xMove,700.0);
}

void drawFish(float x,float y)
{

    float i=0.0;
	float r=5.0;
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y);
		glVertex2f(x+15,y+10);
		glVertex2f(x+20,y+14);//
		glVertex2f(x+30,y+18);
		glVertex2f(x+40,y+22);
		glVertex2f(x+50,y+25);
		glVertex2f(x+60,y+26);
		glVertex2f(x+70,y+25);
		glVertex2f(x+80,y+25);
		glVertex2f(x+90,y+25);
		glVertex2f(x+100,y+25);//

		glVertex2f(x+150,y);
		glVertex2f(x+100,y-25);
		glVertex2f(x+60,y-26);
		glVertex2f(x+70,y-25);
		glVertex2f(x+80,y-25);
		glVertex2f(x+90,y-25);
		glVertex2f(x+50,y-25);
		glVertex2f(x+20,y-14);//
		glVertex2f(x+30,y-18);
		glVertex2f(x+40,y-22);
		glVertex2f(x+15,y-10);
		glVertex2f(x+10,y);
	glEnd();
    //fish top fins
    glColor3f(1.0,0.6,0.0);
	glBegin(GL_POLYGON);
        glVertex2f(x+50,y+25);
        glVertex2f(x+70,y+29);
        glVertex2f(x+95,y+33);
        glVertex2f(x+105,y+36);
        glVertex2f(x+115,y+38);
        glVertex2f(x+120,y+40);
        glVertex2f(x+110,y+30);
        glVertex2f(x+100,y+25);
	glEnd();
    //fish bottom fins
    glColor3f(1.0,0.6,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x+20,y-8);
        glVertex2f(x+30,y-10);
        glVertex2f(x+40,y-15);
        glVertex2f(x+50,y-20);
        glVertex2f(x+90,y-20);
        glVertex2f(x+80,y-8);
    glEnd();
 /*   if(beta==0.0 && beta<=50.0){

        glColor3f(1.0,0.6,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+110,y-10);
		glVertex2f(x+110,y+10);
		glVertex2f(x+155,y+30);
		glVertex2f(x+155,y-30);
	glEnd();
	beta+=1.0;
    }
    else if(beta>25.0){*/
	glColor3f(1.0,0.6,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+110,y-10);
		glVertex2f(x+110,y+10);
		glVertex2f(x+155,y+40);
		glVertex2f(x+155,y-40);
	glEnd();
/*	beta+=1.0;

    }
    if(beta>60.0){
        beta=0.0;
    }*/


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((x+25+r*cos(i)),(y+5+r*sin(i)));
	glEnd();
}
void eli()
{
	glColor3f(0.4,0.8,.80);
//	glBegin(GL_POLYGON);
	//
	glBegin(GL_POLYGON);
	for(float i=0;i<180;i++)
	glVertex2f(320+12*cos(i),200+5+6*sin(i));
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(float j=0;j<180;j++)
	glVertex2f(300+12*cos(j),200+5+6*sin(j));
	glEnd();
glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float l=0;l<180;l++)
	glVertex2f(280+12*cos(l),200+5+6*sin(l));
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(260+12*cos(p),200+5+6*sin(p));
	glEnd();

	glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float r=0;r<180;r++)
	glVertex2f(385+12*cos(r),200+5+6*sin(r));
	glEnd();


    glColor3f(0.4,0.8,.80);
//	glBegin(GL_POLYGON);
	//
	glBegin(GL_POLYGON);
	for(float i=0;i<180;i++)
	glVertex2f(620+12*cos(i),200+5+6*sin(i));
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(float j=0;j<180;j++)
	glVertex2f(600+12*cos(j),200+5+6*sin(j));
	glEnd();
glColor3f(0.4,0.8,.80);
	glBegin(GL_POLYGON);
	for(float l=0;l<180;l++)
	glVertex2f(780+12*cos(l),200+5+6*sin(l));
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(float p=0;p<180;p++)
	glVertex2f(760+12*cos(p),200+5+6*sin(p));
	glEnd();
}

void draw_bubble(float bmove)
{

    bubble(300,100+bmove);
    bubble(400,100+bmove);

}
void bubble(float x, float y)
{
    float i=0.0;
	float r=15.0;
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((x+25+r*cos(i)),(y+5+r*sin(i)));
	glEnd();

}
void plant()
{

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+10,200);
	glVertex2f(330+10,220);
	glVertex2f(350+10,210);
	glVertex2f(350+10,250);
	glVertex2f(360+10,210);
	glVertex2f(370+10,220);
	glVertex2f(380,240);
	glVertex2f(380,200);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340-130,200);
	glVertex2f(330-130,220);
	glVertex2f(350-130,210);
	glVertex2f(350-130,250);
	glVertex2f(360-130,210);
	glVertex2f(370-130,220);
	glVertex2f(380-130,240);
	glVertex2f(380-130,200);
	//glVertex2f(340,200);
	glEnd();

    glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340-230,200);
	glVertex2f(330-230,220);
	glVertex2f(350-230,210);
	glVertex2f(350-230,250);
	glVertex2f(360-230,210);
	glVertex2f(370-230,220);
	glVertex2f(380-230,240);
	glVertex2f(380-230,200);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+100,100);
	glVertex2f(330+100,120);
	glVertex2f(350+100,110);
	glVertex2f(350+100,150);
	glVertex2f(360+100,110);
	glVertex2f(370+100,120);
	glVertex2f(380+100,140);
	glVertex2f(380+100,100);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+200,100);
	glVertex2f(330+200,120);
	glVertex2f(350+200,110);
	glVertex2f(350+200,150);
	glVertex2f(360+200,110);
	glVertex2f(370+200,120);
	glVertex2f(580,140);
	glVertex2f(580,100);
	//glVertex2f(340,200);
	glEnd();



	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+300,200);
	glVertex2f(330+300,220);
	glVertex2f(350+300,210);
	glVertex2f(350+300,250);
	glVertex2f(360+300,210);
	glVertex2f(370+300,220);
	glVertex2f(680,240);
	glVertex2f(680,200);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+400,100);
	glVertex2f(330+400,120);
	glVertex2f(350+400,110);
	glVertex2f(350+400,150);
	glVertex2f(360+400,110);
	glVertex2f(370+400,120);
	glVertex2f(780,140);
	glVertex2f(780,100);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+500,200);
	glVertex2f(330+500,220);
	glVertex2f(350+500,210);
	glVertex2f(350+500,250);
	glVertex2f(360+500,210);
	glVertex2f(370+500,220);
	glVertex2f(880,240);
	glVertex2f(880,200);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+600,300);
	glVertex2f(330+600,320);
	glVertex2f(350+600,310);
	glVertex2f(350+600,350);
	glVertex2f(360+600,310);
	glVertex2f(370+600,320);
	glVertex2f(380+600,340);
	glVertex2f(380+600,300);
	//glVertex2f(340,200);
	glEnd();

	glColor3f(0,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(340+700,200);
	glVertex2f(330+700,220);
	glVertex2f(350+700,210);
	glVertex2f(350+700,250);
	glVertex2f(360+700,210);
	glVertex2f(370+700,220);
	glVertex2f(380+700,240);
	glVertex2f(380+700,200);
	//glVertex2f(340,200);
	glEnd();


}

void createSixthWindow(void)
{

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(fifthWindow);
	sixthWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(mydisplaySixthWindow);
	glutKeyboardFunc(keySixth);
	initSecondWindow();

}

void mydisplaySixthWindow(void)
{
	moveFishAxe+=0.5;
	//cout<<"moveFishAxe:"<<moveFishAxe<<"\n";
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0,-220.0,0.0);
	drawWoodcutterOnRiverSide(550.0,450.0);
	glPopMatrix();

	if(moveFishAxe<250.0)
	{
		drawCutterInFish(850.0,0.0+moveFishAxe,2);
		displayTextGold(moveFishAxe+20.0);
	}
	else if(moveFishAxe>=250.0)
	{
		drawCutterInFish(850.0,250.0,2);
		displayTextCutterOne();
		displayHelp("Press B",1000.0,100.0);
	}
	glFlush();
}

void displayTextGold(float y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(900.0,y);
		glVertex2f(950.0,50.0+y);
		glVertex2f(1100.0,50.0+y);
		glVertex2f(1100.0,y-50.0);
		glVertex2f(950.0,y-50.0);
	glEnd();

	displayHelp("Is this",950.0,y+20.0);
	displayHelp("yours...???",950.0,y-10.0);
}

void displayTextCutterOne()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(700,450);
		glVertex2f(750,500);
		glVertex2f(950,500);
		glVertex2f(950,400);
		glVertex2f(750,400);
	glEnd();

	displayHelp("No!!!",780,460);
	displayHelp("My one is not gold.",720,430);
}

void drawWoodcutterOnRiverSide(float x,float y)
{

	float radius = 35.0;
	glColor3f(1.0,0.90,0.85);

	glBegin(GL_POLYGON);
		for(float i=0;i<360;i+=0.1)
			glVertex2f(cos(i)*radius+x,sin(i)*radius+y+150);
	glEnd();

	radius=6.0;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();

	radius=3.0;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
	glEnd();


	//Hair of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-35,y+150);
		glVertex2f(x-35,y+170);
		glVertex2f(x-25,y+195);
		glVertex2f(x+40,y+195);
		glVertex2f(x+35,y+175);
		glVertex2f(x+20,y+170);
	glEnd();


	//Draws the neck of the woodcutter
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-10.0,y+100.0);
		glVertex2f(x-10.0,y+120.0);
		glVertex2f(x+10.0,y+120.0);
		glVertex2f(x+10.0,y+100.0);
	glEnd();


	//Draws the left hand of woodcutter
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y+90);
		glVertex2f(x+10,y+100);
		glVertex2f(x+50,y+85);
		glVertex2f(x+50,y+75);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+75);
		glVertex2f(x+50,y+85);
		glVertex2f(x+75,y+115);
		glVertex2f(x+75,y+105);
	glEnd();



	//Draws the red shirt of woodcutter
	glColor3f(0.8,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+75);
		glVertex2f(x-10,y+100);
		glVertex2f(x+10,y+100);
		glVertex2f(x+25,y+75);
		glVertex2f(x+25,y);
	glEnd();

		//Draws the mouth of the woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+25,y+125);
		glVertex2f(x+10,y+125);
		glVertex2f(x+10,y+127);
	glEnd();

	//Draws the Nose of the woodcutter

	glBegin(GL_LINE_STRIP);
		glVertex2f(x+32,y+140);
		glVertex2f(x+32,y+150);
		glVertex2f(x+34,y+155);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2f(x-10,y+160);
		glVertex2f(x-20,y+160);
		glVertex2f(x-20,y+140);
		glVertex2f(x-10,y+140);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(x-20,y+150);
		glVertex2f(x-10,y+150);
	glEnd();

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x,y+70);
		glVertex2f(x,y+80);
		glVertex2f(x+55,y+65);
		glVertex2f(x+55,y+55);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+55,y+55);
		glVertex2f(x+55,y+65);
		glVertex2f(x+80,y+95);
		glVertex2f(x+80,y+85);
	glEnd();

	//Drwas the trousers of woodcutter
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-25,y);
		glVertex2f(x-25,y+30);
		glVertex2f(x+25,y+30);
		glVertex2f(x+25,y);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x+25,y);
		glVertex2f(x+25,y+26);
		glVertex2f(x+50,y+26);
		glVertex2f(x+50,y);
	glEnd();


	//Draws the Right palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+80,y+85);
		glVertex2f(x+80,y+105);
		glVertex2f(x+90,y+105);
		glVertex2f(x+90,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+80,y+105);
		glVertex2f(x+80,y+100);
		glVertex2f(x+82.5,y+105);
		glVertex2f(x+82.5,y+100);
		glVertex2f(x+85,y+105);
		glVertex2f(x+85,y+100);
		glVertex2f(x+87,y+105);
		glVertex2f(x+87,y+100);
		glVertex2f(x+89.5,y+105);
		glVertex2f(x+89.5,y+100);
	glEnd();

	//Draws the left palm
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+65,y+95);
		glVertex2f(x+65,y+105);
		glVertex2f(x+75,y+105);
		glVertex2f(x+75,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(x+65,y+105);
		glVertex2f(x+65,y+100);
		glVertex2f(x+67.5,y+105);
		glVertex2f(x+67.5,y+100);
		glVertex2f(x+70,y+105);
		glVertex2f(x+70,y+100);
		glVertex2f(x+72.5,y+105);
		glVertex2f(x+72.5,y+100);
		glVertex2f(x+74.5,y+105);
		glVertex2f(x+74.5,y+100);
	glEnd();

	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+50,y+8);
		glVertex2f(x+50,y+18);
		glVertex2f(x+75,y+18);
		glVertex2f(x+75,y+8);
	glEnd();
}

void drawCutterInFish(float x,float y,int color)
{
	float r=5.0;
	float i=0.0;

	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x-25,y);
	glColor3f(1.0,0.8,0.1);
	glVertex2f(x-25,y+25);
	glColor3f(1.0,0.843137,0.0);
	glVertex2f(x-15,y+65);
	glColor3f(0.752941,0.752941,0.752941);
	glVertex2f(x,y+75);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+15,y+65);
	glColor3f(1.0,0.843137,0.0);
	glVertex2f(x+25,y+25);
	glColor3f(0.752941,0.752941,0.752941);
	glVertex2f(x+25,y);
	glEnd();



	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((x+7+r*cos(i)),(y+55+r*sin(i)));
	glEnd();

	if(color==1)
		glColor3f(0.8456,0.684,0.4424);
	else if(color==2)
		glColor3f(1.0,0.843137,0.0);
	else if(color==3)
		glColor3f(0.752941,0.752941,0.752941);

	glBegin(GL_POLYGON);
		glVertex2f(x-75,y+75);
		glVertex2f(x-75,y+85);
		glVertex2f(x+75,y+85);
		glVertex2f(x+75,y+75);
	glEnd();

	if(color==1)
		glColor3f(0.0,0.0,0.0);
	else if(color==2)
		glColor3f(1.0,0.843137,0.0);
	else if(color==3)
		glColor3f(0.752941,0.752941,0.752941);
	glBegin(GL_POLYGON);
		glVertex2f(x-70,y+40);
		glVertex2f(x-70,y+95);
		glVertex2f(x-45,y+95);
		glVertex2f(x-45,y+40);
	glEnd();

}

void createSeventhWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(sixthWindow);
	seventhWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(mydisplaySeventhWindow);
	glutKeyboardFunc(keySeventh);
	initSecondWindow();
}

void mydisplaySeventhWindow()
{
	moveFishAxe2+=0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0,-220.0,0.0);
	drawWoodcutterOnRiverSide(550.0,450.0);
	glPopMatrix();


	if(moveFishAxe2<250.0)
	{
		drawCutterInFish(850.0,0.0+moveFishAxe2,3);
		displayTextGold(moveFishAxe2+20.0);
	}
	else if(moveFishAxe2>=250.0)
	{
		drawCutterInFish(850.0,250.0,3);
		displayTextCutterTwo();
		displayHelp("Press N",1000.0,100.0);
	}

	glFlush();
}

void displayTextCutterTwo()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(700,450);
		glVertex2f(750,500);
		glVertex2f(950,500);
		glVertex2f(950,400);
		glVertex2f(750,400);
	glEnd();

	displayHelp("No!!!",780,460);
	displayHelp("My one is not silver.",720,430);
}

void keySeventh(unsigned char key,int x,int y)
{
	if(key=='x' || key == 'X')
		exit(0);
	if(key=='N' || key == 'n');
		createEigthWindow();
}

void createEigthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(seventhWindow);
	eighthWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(displayEigthWindow);
	glutKeyboardFunc(keyEigth);
	initSecondWindow();

}

void keyEigth(unsigned char key,int x,int y)
{
	if(key=='x'||key=='X')
		exit(0);
	if(key=='J'||key=='j')
		createTenthWindow();
}

void displayEigthWindow()
{
	moveFishAxe3+=0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0,-220.0,0.0);
	drawWoodcutterOnRiverSide(550.0,450.0);
	glPopMatrix();


	if(moveFishAxe3<250.0)
	{
		drawCutterInFish(850.0,0.0+moveFishAxe3,1);
		displayTextGold(moveFishAxe3);
	}
	else if(moveFishAxe3>=250.0)
	{

		drawCutterInFish(850.0,250,1);
		displayTextThree();
		displayHelp("Press J",1000.0,100.0);
	}
	else if(moveFishAxe3>=300.0)
	{
		cout<<"Hello\n";
		drawCutterInFish(850.0,250,1);
		displayTextGold(350.0);

	}
	glutPostRedisplay();

	glFlush();
}

void displayTextThree()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(700,450);
		glVertex2f(750,500);
		glVertex2f(950,500);
		glVertex2f(950,400);
		glVertex2f(750,400);
	glEnd();

	displayHelp("Yes!!!",780,460);
	displayHelp("Yoo...This is",780,430);
	displayHelp("mine!!!!",780,410);

}


void displayHelp(char str[],float x,float y)
{
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(x,y);
		for(i=0;i<strlen(str);i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
		glutPostRedisplay();
}

void createNinthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(10,10);
	ninthWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(displayNinthWindow);
	glutDestroyWindow(tenthWindow);
	initSecondWindow();
}

void displayNinthWindow()
{
	tCount+=0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	if(tCount<=100)
		displayHelp("Thank you...!",200,500);
	if(tCount>100 && tCount<=200)
		displayHelp("Special Thanks to Mr.Sudharshan K",200,500);

	else if(tCount>200&&tCount<=500)
	{
		displayHelp("Story:Sudharshan.A",200,550);
		displayHelp("Design:Sudharshan.A",200,500);
		displayHelp("Programming:Shreesha.M",200,450);
		displayHelp("Guided by:Mr.Sudarshan K",200,600);
	}
	else if(tCount>500)
	{
		displayHelp("HONESTY IS THE BEST POLICY",300,350);
	}

	else if(tCount==750.0)
	{
		exit(0);
	}
	glFlush();
}

void createTenthWindow()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutDestroyWindow(eighthWindow);
	tenthWindow=glutCreateWindow("Miracle:Honest Woodcutter");
	glutDisplayFunc(displayTenthWindow);
	glutKeyboardFunc(keyTenth);
	initSecondWindow();
	glutMainLoop();
}

void displayTenthWindow(void)
{
	moveFishAxe4+=0.5;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLand();
	drawWater();

	glPushMatrix();
	glTranslatef(-100.0,200.0,0.0);
	drawTree();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(600.0,300.0,0.0);
	drawTree();
	glPopMatrix();

	drawTree();
	drawGrasses();

	glPushMatrix();
	glTranslatef(50.0,-220.0,0.0);
	drawWoodcutterOnRiverSide(550.0,450.0);
	glPopMatrix();


	if(moveFishAxe4<250.0)
	{
		drawCutterInFishThree(850.0,0.0+moveFishAxe4);
		displayTextAll(moveFishAxe4);
	}
	else if(moveFishAxe4>=250.0)
	{

		drawCutterInFishThree(850.0,250);
		displayHelp("Press K ",1000.0,100.0);
	}
	glutPostRedisplay();

	glFlush();
}

void drawCutterInFishThree(float x,float y)
{
	float r=5.0;
	float i=0.0;

	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x-25,y);
	glColor3f(1.0,0.8,0.1);
	glVertex2f(x-25,y+25);
	glColor3f(1.0,0.843137,0.0);
	glVertex2f(x-15,y+65);
	glColor3f(0.752941,0.752941,0.752941);
	glVertex2f(x,y+75);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x+15,y+65);
	glColor3f(1.0,0.843137,0.0);
	glVertex2f(x+25,y+25);
	glColor3f(0.752941,0.752941,0.752941);
	glVertex2f(x+25,y);
	glEnd();



	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(i=0;i<360;i++)
			glVertex2f((x+7+r*cos(i)),(y+55+r*sin(i)));
	glEnd();

	//Golden axe at front
	glColor3f(1.0,0.843137,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-75,y+75);
		glVertex2f(x-75,y+85);
		glVertex2f(x+75,y+85);
		glVertex2f(x+75,y+75);
	glEnd();


	glColor3f(1.0,0.843137,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-70,y+40);
		glVertex2f(x-70,y+95);
		glVertex2f(x-45,y+95);
		glVertex2f(x-45,y+40);
	glEnd();


	//Silver axe behind
	glColor3f(0.752941,0.752941,0.752941);
	glBegin(GL_POLYGON);
		glVertex2f(x-75,y+85);
		glVertex2f(x-70,y+85);
		glVertex2f(x-70,y+90);
		glVertex2f(x-75,y+90);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x-70,y+95);
		glVertex2f(x-45,y+95);
		glVertex2f(x-45,y+100);
		glVertex2f(x-70,y+100);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(x-45,y+85);
		glVertex2f(x+75,y+85);
		glVertex2f(x+75,y+90);
		glVertex2f(x-45,y+90);
	glEnd();

	//Normal Axe behind

	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x-75,y+90);
		glVertex2f(x-70,y+90);
		glVertex2f(x-70,y+95);
		glVertex2f(x-75,y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-70,y+100);
		glVertex2f(x-45,y+100);
		glVertex2f(x-45,y+105);
		glVertex2f(x-70,y+105);
	glEnd();

	glColor3f(0.8456,0.684,0.4424);
	glBegin(GL_POLYGON);
		glVertex2f(x-45,y+90);
		glVertex2f(x+75,y+90);
		glVertex2f(x+75,y+95);
		glVertex2f(x-45,y+95);
	glEnd();

}

void displayTextAll(float y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(900.0,y);
		glVertex2f(950.0,50.0+y);
		glVertex2f(1100.0,50.0+y);
		glVertex2f(1100.0,y-50.0);
		glVertex2f(950.0,y-50.0);
	glEnd();

	displayHelp("These all",950.0,y+20.0);
	displayHelp(" for you...!!!",950.0,y-10.0);
}

void keyTenth(unsigned char key,int x,int y)
{
	if(key=='k'||key=='K')
	{
		createNinthWindow();
	}
}
void rightleg(float x,float y)
{

  	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y-75);
		glVertex2f(x+10,y);
		glVertex2f(x+20,y);
		glVertex2f(x+20,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y-75);
		glVertex2f(x+20,y-65);
		glVertex2f(x+40,y-70);
		glVertex2f(x+40,y-75);
	glEnd();
}
void leftleg(float x,float y)
{

    glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-15,y-75);
		glVertex2f(x-15,y);
		glVertex2f(x-5,y);
		glVertex2f(x-5,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-15,y-75);
		glVertex2f(x-5,y-65);
		glVertex2f(x+15,y-70);
		glVertex2f(x+15,y-75);
	glEnd();
}
void moveleftlegs(float x,float y)
{
    glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-45,y-75);
		glVertex2f(x-15,y);
		glVertex2f(x-5,y);
		glVertex2f(x-25,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-15,y-75);
		glVertex2f(x-5,y-65);
		glVertex2f(x+15,y-70);
		glVertex2f(x+15,y-75);
	glEnd();

}
void moverightlegs(float x,float y)
{
    glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x+30,y-75);
		glVertex2f(x+10,y);
		glVertex2f(x+20,y);
		glVertex2f(x+40,y-75);
	glEnd();


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+10,y-75);
		glVertex2f(x+20,y-65);
		glVertex2f(x+40,y-70);
		glVertex2f(x+40,y-75);
	glEnd();

}
