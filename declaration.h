#include <windows.h>
#include <math.h>


#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include <MMSystem.h>


#include <string.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <stdlib.h>


using namespace std;







void click(int,int,int,int);


void createNewWindow(void);
void initSecondWindow(void);
void mydisplaySecondWindow(void);
//void key(unsigned char,int,int);

void drawTree(void);
void drawWater(void);
void drawLand(void);
void drawGrasses();
void drawGrass(int,int);
void moverightlegs(float,float);
void moveleftlegs(float,float);
void leftleg(float,float);
void rightleg(float,float);



void drawTreeEdges(void);
void drawLeafTriangles(void);


void drawWoodcutter(int,int);
void drawCutter(int,int);
void cutter(float,float);



void createHelpWindow(void);
void displayHelpWindow();

void createThirdWindow();
void mydisplayThirdWindow();
void drawWoodcutterOnTree(float,float);
void drawAxeUp(float,float);
void drawAxeDown(float,float);

void createFourthWindow(void);
void mydisplayFourthWindow(void);

void moveDownAxe(float x,float y);


void plant();
void eli();
void draw_bubble(float);
void bubble(float,float);
void createFifthWindow(void);
void mydisplayFifthWindow(void);
void drawUnderWater(void);
void drawStone(void);
void drawAxeInWater(float,float);

void drawFishes(float);
void drawFish(float,float);
void DrawBubble(void);



void createSixthWindow(void);
void mydisplaySixthWindow(void);
void drawWoodcutterOnRiverSide(float,float);

void drawCutterInFish(float x,float y,int color);

void keySecond(unsigned char,int,int);
void keyThird(unsigned char,int,int);
void keyFourth(unsigned char,int,int);
void keySixth(unsigned char,int,int);
void keySeventh(unsigned char,int,int);
void keyEigth(unsigned char,int,int);

void keyTenth(unsigned char,int,int);

void createSeventhWindow(void);
void mydisplaySeventhWindow(void);
void createEigthWindow(void);
void displayEigthWindow(void);


void displayHelp(char str[],float x,float y);
void displayText();
void displayTextGod();
void displayTextGold(float y);
void displayTextCutterOne(void);
void displayTextCutterTwo(void);
void displayTextThree(void);

void createNinthWindow();
void displayNinthWindow();

void createTenthWindow();
void displayTenthWindow();
void drawCutterInFishThree(float x,float y);

void displayTextAll(float y);




