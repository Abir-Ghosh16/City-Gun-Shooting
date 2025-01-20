/*#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<math.h>
#define pi 3.142857
#include <iostream>
#include<mmsystem.h>
#include <fstream>
#include <string>


using namespace std;

// Enum for game states
typedef enum {
    MAIN_MENU,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    OPTIONS
} GameState;

GameState currentGameState = MAIN_MENU;

// Function prototypes
void displaymenu();
void reshape(int, int);
void keyboardm(unsigned char, int, int);
void mousem(int, int, int, int);

// Helper function to draw text
void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// Main menu display
void displayMainMenu() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    // Draw menu text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 700, "MAIN MENU");
    drawText(250, 600, "1. Level 1");
    drawText(250, 500, "2. Level 2");
    drawText(250, 400, "3. Level 3");
    drawText(250, 300, "4. Options");
    drawText(250, 200, "Press the corresponding number key");

    glFlush();
}

// Level 1 display
void displayLevel1() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Draw Level 1 text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 400, "Welcome to Level 1");
    drawText(250, 300, "Press 'm' to return to the main menu");

    glFlush();
}
///=================================================================================================================================
// Level 2 display
void displayLevel2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);

    // Draw Level 2 text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 400, "Welcome to Level 2");
    drawText(250, 300, "Press 'm' to return to the main menu");

    glFlush();
}
///===============================================================================================================================
// Level 3 display
void displayLevel3() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

    // Draw Level 3 text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 400, "Welcome to Level 3");
    drawText(250, 300, "Press 'm' to return to the main menu");

    glFlush();
}

// Options display
void displayOptions() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    // Draw Options text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 400, "Options Menu");
    drawText(250, 300, "Press 'm' to return to the main menu");

    glFlush();
}

// Display callback
void displaymenu() {
    switch (currentGameState) {
        case MAIN_MENU:
            displayMainMenu();
            break;
        case LEVEL_1:
            displayLevel1();
            break;
        case LEVEL_2:
            displayLevel2();
            break;
        case LEVEL_3:
            displayLevel3();
            break;
        case OPTIONS:
            displayOptions();
            break;
    }
}

// Reshape callback
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 800);
    glMatrixMode(GL_MODELVIEW);
}

// Keyboard callback
void keyboardm(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            currentGameState = LEVEL_1;
            break;
        case '2':
            currentGameState = LEVEL_2;
            break;
        case '3':
            currentGameState = LEVEL_3;
            break;
        case '4':
            currentGameState = OPTIONS;
            break;
        case 'm':
            currentGameState = MAIN_MENU;
            break;
        case 27: // ESC key
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Mouse callback (optional, not used here)
void mousem(int button, int state, int x, int y) {
    // Add mouse interaction if needed
}


void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1450, 750); // Set window size
    glutCreateWindow("Game Menu Example");

    glutDisplayFunc(displaymenu);
    //glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardm);
    glutMouseFunc(mousem);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);

    glutMainLoop();
    return 0;
}

*/

///,//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<math.h>
#define pi 3.142857
#include <iostream>
#include<mmsystem.h>
#include <fstream>
#include <string>

using namespace std;


const int WINDOW_WIDTH = 1450;
const int WINDOW_HEIGHT = 750;

// Define the target structure
struct Target {
    float x, y;       // Position
    float dx;         // Movement delta
    bool isHit;       // Status
};

// Variables for the game
vector<Target> blueTargets;  // List of blue targets
vector<Target> busTargets;   // List of bus targets
vector<Target> carTargets;
vector<Target> ambulanceTargets;
float crosshairX = 350.0f;   // Crosshair position (X)
float crosshairY = 400.0f;   // Crosshair position (Y)
int score = 0;               // Player's score
int level = 1;               // Current level
bool gameOver = false;       // Game status
float p=-10;

// Utility function to generate random float values
float randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

int highScore = 0;

// Function to read the high score from the file
void loadHighScore() {
    ifstream file("C:\\Users\\Admin\\Desktop\\All LAB\\Graphics Design\\g\\highscore.txt");
    if (file.is_open()) {
        file >> highScore; // Read the high score from the file
        file.close();
    } else {
        highScore = 0; // Default to 0 if the file doesn't exist
    }
}

// Function to save the high score to the file
void saveHighScore() {
    ofstream file("C:\\Users\\Admin\\Desktop\\All LAB\\Graphics Design\\g\\highscore.txt");
    if (file.is_open()) {
        file << highScore; // Write the high score to the file
        file.close();
    }
}

// Game over logic
void handleGameOver() {
    if (score > highScore) {
        highScore = score; // Update the high score
        saveHighScore();          // Save the high score to the file
    }

    cout << "Game Over! High Score: " << highScore << endl;
}

/*
void drawCircle(float radius, float segments, float cx, float cy) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1415926f * float(i) / segments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}*/
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}

// Draw the bus
void drawBus(float x, float y) {

///bus body
    glBegin(GL_QUADS);
    glColor3ub(61, 123, 52);
    glVertex2f(x+90,y+98);  //bus...................
    glVertex2f(x+95,y+98);
    glVertex2f(x+95,y+100);
    glVertex2f(x+90,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(x+94,y+89);   // bus font glass
    glVertex2f(x+96,y+89);
    glVertex2f(x+96,y+100);
    glVertex2f(x+94,y+100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(61, 123, 52);
    glVertex2f(x+10,y+80);  //.....bus
    glVertex2f(x+90,y+80);
    glVertex2f(x+90,y+105);
    glVertex2f(x+10,y+105);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(61, 123, 52);
    glVertex2f(x+10,y+55);  //top..........lowerpart
    glVertex2f(x+92,y+55);
    glVertex2f(x+92,y+80);
    glVertex2f(x+10,y+80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(x+11,y+81);  //top..........
    glVertex2f(x+89,y+81);
    glVertex2f(x+89,y+102);
    glVertex2f(x+11,y+102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+12,y+85);  //window..........
    glVertex2f(x+20,y+85);
    glVertex2f(x+20,y+100);
    glVertex2f(x+12,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+22,y+85);  //window..........
    glVertex2f(x+30,y+85);
    glVertex2f(x+30,y+100);
    glVertex2f(x+22,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+32,y+85);  //window..........
    glVertex2f(x+40,y+85);
    glVertex2f(x+40,y+100);
    glVertex2f(x+32,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+42,y+85);  //window..........
    glVertex2f(x+50,y+85);
    glVertex2f(x+50,y+100);
    glVertex2f(x+42,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+52,y+85);  //window..........
    glVertex2f(x+60,y+85);
    glVertex2f(x+60,y+100);
    glVertex2f(x+52,y+100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(x+62,y+55);  //..door..........
    glVertex2f(x+70,y+55);
    glVertex2f(x+70,y+95);
    glVertex2f(x+62,y+95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+72,y+85);  //window..........
    glVertex2f(x+80,y+85);
    glVertex2f(x+80,y+100);
    glVertex2f(x+72,y+100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+82,y+85);  //window..........
    glVertex2f(x+88,y+85);
    glVertex2f(x+88,y+100);
    glVertex2f(x+82,y+100);
    glEnd();

    glColor3ub(176, 168, 92);          //....design
    circle(4,8,x+45,y+65);
    glColor3ub(176, 168, 92);
    circle(2,4,x+55,y+75);
    glColor3ub(176, 168, 92);
    circle(3,6,x+15,y+75);
    glColor3ub(176, 168, 92);
    circle(2,4,x+35,y+65);
    glColor3ub(176, 168, 92);
    circle(2,4,x+75,y+75);


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,x+25,y+55);
    glColor3ub(255,255,255);
    circle(3,6,x+25,y+55);

    glColor3ub(0,0,0);
    circle(5,10,x+78,y+55);
    glColor3ub(255,255,255);
    circle(3,6,x+78,y+55);

    glColor3ub(0, 0, 0);
    glRasterPos2i(x+40,y+65);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'R');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'M');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'Y');

}

void drawCar(float x, float y) {

    glBegin(GL_POLYGON);
    glColor3ub(250, 251, 10);
    glVertex2f(x+10.5, y+37.4*1.6);  //top..........lowerpart
    glVertex2f(x+13.1, y+43.7*1.6);
    glVertex2f(x+18.5, y+44.3*1.6);
    glVertex2f(x+21,   y+45.4*1.6);//e
    glVertex2f(x+25.9, y+47.3*1.6);//g
    glVertex2f(x+30.691, y+48.626*1.6);//i
    glVertex2f(x+35.586, y+48.770*1.6);//k
    glVertex2f(x+40.770, y+48.626*1.6);//m
    glVertex2f(x+46.241, y+48.194*1.6);//o
    glVertex2f(x+50.561, y+46.178*1.6);//Q
    glVertex2f(x+54.592, y+43.875*1.6);//s
    glVertex2f(x+68.990, y+41.859*1.6);//u
    glVertex2f(x+70.286, y+37.827*1.6);//z
    glVertex2f(x+68.990, y+33.076*1.6);//a
    glVertex2f(x+66.255, y+32.212*1.6);//b
    glVertex2f(x+18.885, y+32.068*1.6);//e
    glVertex2f(x+12.693, y+33.076*1.6);//f
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+25.370, y+43.029*1.6);  //window..........
    glVertex2f(x+30.345, y+46.715*1.6);
    glVertex2f(x+37.944, y+47.430*1.6);
    glVertex2f(x+37.944, y+43.497*1.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(x+40.626, y+43.407*1.6);  //window..........
    glVertex2f(x+39.642, y+47.430*1.6);
    glVertex2f(x+46.973, y+46.179*1.6);
    glVertex2f(x+52.695, y+43.05*1.6);
    glEnd();


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,x+25,y+50);
    glColor3ub(255,255,255);
    circle(3,6,x+25,y+50);

    glColor3ub(0,0,0);
    circle(5,10,x+58,y+50);
    glColor3ub(255,255,255);
    circle(3,6,x+58,y+50);

    glColor3ub(0, 0, 0);
    glRasterPos2i(x+30,y+55);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'T');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'X');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'Y');

}

void drawAmbulance(float x, float y) {

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(x+14.897*1.3, y+88.459*1.15);
    glVertex2f(x+18.645*1.3, y+100.470*1.15);
    glVertex2f(x+22.249*1.3, y+103.930*1.15);
    glVertex2f(x+55.912*1.3, y+103.930*1.15);
    glVertex2f(x+57.138*1.3, y+100.470*1.15);
    glVertex2f(x+59.733*1.3, y+92.973*1.15);
    glVertex2f(x+60*1.3, y+65*1.15);//k
    glVertex2f(x+10*1.3, y+65*1.15);//m
    glVertex2f(x+10*1.3, y+85*1.15);//m

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 55);
    glVertex2f(x+17*1.3, y+92*1.15);  //window..........
    glVertex2f(x+20*1.3, y+99*1.15);
    glVertex2f(x+25*1.3, y+99*1.15);
    glVertex2f(x+25*1.3, y+92*1.15);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(230, 255, 55);
    glVertex2f(x+27.7*1.3, y+92.4*1.15);  //window..........
    glVertex2f(x+27.7*1.3, y+99*1.15);
    glVertex2f(x+35.42*1.3, y+99.1*1.15);
    glVertex2f(x+35.42*1.3, y+92.4*1.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 25, 55);
    glVertex2f(x+10*1.3, y+58*1.5);  //window..........
    glVertex2f(x+10*1.3, y+65*1.5);
    glVertex2f(x+60*1.3, y+65*1.5);
    glVertex2f(x+60*1.3, y+58.4*1.5);
    glEnd();


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,x+25,y+75);
    glColor3ub(255,255,255);
    circle(3,6,x+25,y+75);

    glColor3ub(0,0,0);
    circle(5,10,x+58,y+75);
    glColor3ub(255,255,255);
    circle(3,6,x+58,y+75);

    glColor3ub(0, 0, 0);
    glRasterPos2i(x+30,y+85);

    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'M');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'B');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'U');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'L');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'A');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'N');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'C');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,'E');

}

void draw_helicopter(float x, float y)
{
// Helicopter Body --------------------------------------------------------(Shuvo)
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x+360, y+600);
    glVertex2f(x+390, y+600);
    glVertex2f(x+395, y+595);
    glVertex2f(x+395, y+585);
    glVertex2f(x+390, y+580);
    glVertex2f(x+360, y+580);
    glVertex2f(x+355, y+585);
    glVertex2f(x+355, y+595);
    glEnd();

    // Helicopter Window
    glColor3ub(135, 206, 250);
    glBegin(GL_POLYGON);
    glVertex2f(x+362, y+597);
    glVertex2f(x+387, y+597);
    glVertex2f(x+390, y+593);
    glVertex2f(x+390, y+587);
    glVertex2f(x+362, y+587);
    glEnd();

    // Helicopter Tail
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(x+395, y+590);
    glVertex2f(x+420, y+590);
    glVertex2f(x+420, y+588);
    glVertex2f(x+395, y+588);
    glEnd();

    // Tail Rotor
    glBegin(GL_LINES);
    glVertex2f(x+420, y+589);
    glVertex2f(x+430, y+589);
    glVertex2f(x+425, y+584);
    glVertex2f(x+425, y+594);
    glEnd();

    // Top Rotor
    glBegin(GL_LINES);
    glVertex2f(x+355, y+610);
    glVertex2f(x+395, y+610);
    glEnd();

    // Rotor Connection
    glBegin(GL_LINES);
    glVertex2f(x+375, y+600);
    glVertex2f(x+375, y+610);
    glEnd();

    // Landing Skids
    glBegin(GL_LINES);
    glVertex2f(x+358, y+575);
    glVertex2f(x+392, y+575);
    glVertex2f(x+362, y+575);
    glVertex2f(x+362, y+580);
    glVertex2f(x+388, y+575);
    glVertex2f(x+388, y+580);
    glEnd();

}


// Initialize the game state
void initGame() {
    loadHighScore();
    blueTargets.clear();
    busTargets.clear();
    carTargets.clear();
    ambulanceTargets.clear();

    // Initialize blue targets
    int blueCount = 2;///////(level == 1) ? 1 : 2;
for (int i = 0; i < blueCount; ++i) {
    Target t = {randomFloat(850.0f, 950.0f), 600.0f, randomFloat(-2.0f, -1.0f), false};
    blueTargets.push_back(t);
}

// Adjust initialization for bus targets (bottom-up movement)
int busCount = 3;//////////(level == 1) ? 3 : 6;
for (int i = 0; i < busCount; ++i) {
    Target t = {randomFloat(-650.0f, -50.0f), 50.0f, randomFloat(1.7f, 1.0f), false};
    busTargets.push_back(t);
}

int carCount = 2;//////////(level == 1) ? 3 : 6;
for (int i = 0; i < carCount; ++i) {
    Target t = {randomFloat(-150.0f, 650.0f), 50.0f, randomFloat(0.7f, 1.5f), false};
    carTargets.push_back(t);
}

int ambulanceCount = 2;//////////(level == 1) ? 3 : 6;
for (int i = 0; i < ambulanceCount; ++i) {
    Target t = {randomFloat(-150.0f, 650.0f), 50.0f, randomFloat(-0.7f, -1.5f), false};
    ambulanceTargets.push_back(t);
}


    score = 0;
    gameOver = false;
}










///---------------------------------------------------------------
// Enum for game states
typedef enum {
    MAIN_MENU,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    OPTIONS
} GameState;

GameState currentGameState = MAIN_MENU;
// Function prototypes
void displaymenu();
void keyboardm(unsigned char, int, int);
void mousem(int, int, int, int);

// Helper function to draw text
void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

// Main menu display
void displayMainMenu() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    // Draw menu text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(250, 700, "MAIN MENU");
    drawText(250, 600, "1. Level 1");
    drawText(250, 500, "2. Level 2");
    drawText(250, 400, "3. Level 3");
    drawText(250, 300, "4. ON/ OFF MUSIC");
    drawText(250, 200, "Press the corresponding number key");

    glutSwapBuffers();
}

void displayLevel1() {///#######################################################################################################
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);//sky white
  //  glColor3ub(255, 255, 147);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glColor3ub(102, 204, 255);
    glVertex2f(800,800);
    glVertex2f(0,800);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(16, 208, 0);
    glVertex2f(0,100);        //number 1 green step
    glVertex2f(800,100);
    glVertex2f(800,119.5);
    glVertex2f(0,119.5);
    glEnd();

    glBegin(GL_QUADS);//gray road
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0,30);
    glVertex2f(800,30);
    glVertex2f(800,80);
    glVertex2f(0,80);
    glEnd();

    glBegin(GL_LINES);//Road top bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,81);
    glVertex2i(800,81);
    glEnd();

    glBegin(GL_LINES);//Road middle bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,62);
    glVertex2i(800,62);
    glEnd();

    glBegin(GL_LINES);//Road Bottop bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,39);
    glVertex2i(800,39);
    glEnd();


    glBegin(GL_QUADS);// 2nd green bar
    glColor3ub(12, 165, 25);
    glVertex2f(0,82);
    glVertex2f(800,82);
    glVertex2f(800,90);
    glVertex2f(0,90);
    glEnd();

    glBegin(GL_QUADS);// 3rd green bar
    glColor3ub(30, 208, 15);
    glVertex2f(0,38);
    glVertex2f(800,38);
    glVertex2f(800,0);
    glVertex2f(0,0);
    glEnd();

   ///-------------------------------------------------------------------------------------------------------------------------------------------------

    ///1st Building Design///Top////////////////////////////////////////////////////////


///white part///
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);///1st Building main part 2
    glVertex2f(72.5,119);
    glVertex2f(165.5,119);
    glVertex2f(165.5,442);
    glVertex2f(72.5,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 154, 255);
    glVertex2f(75,119);        ///1st Building main part 2
    glVertex2f(163,119);
    glVertex2f(163,434);
    glVertex2f(75,434);
    glEnd();

    ///floor divided y+40//
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,150);  ///1st Building 1st floor1
    glVertex2f(163,150);
    glVertex2f(163,154);
    glVertex2f(75,154);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,190);  ///1st Building 2nd floor1
    glVertex2f(163,190);
    glVertex2f(163,193);
    glVertex2f(75,193);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,230);  ///1st Building 3rd floor1
    glVertex2f(163,230);
    glVertex2f(163,234);
    glVertex2f(75,234);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,270);  ///1st Building 4th floor1
    glVertex2f(163,270);
    glVertex2f(163,273);
    glVertex2f(75,273);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,310);  ///1st Building 5th floor1
    glVertex2f(163,310);
    glVertex2f(163,314);
    glVertex2f(75,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,310);  ///1st Building 6th floor1
    glVertex2f(163,310);
    glVertex2f(163,314);
    glVertex2f(75,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,350);  ///1st Building 7th floor1
    glVertex2f(163,350);
    glVertex2f(163,353);
    glVertex2f(75,353);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,390);  ///1st Building 8th floor1
    glVertex2f(163,390);
    glVertex2f(163,394);
    glVertex2f(75,394);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(105,119);  /// 1st Building white line vertical
    glVertex2f(105.5,119);
    glVertex2f(105.5,440);
    glVertex2f(105,440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(133,119);  /// 1st Building white line vertical
    glVertex2f(133.5,119);
    glVertex2f(133.5,440);
    glVertex2f(133,440);
    glEnd();


    ///Door
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(112,140);  ///1st Building 1st floor1
    glVertex2f(127,140);
    glVertex2f(127,144);
    glVertex2f(112,144);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(112,119);  /// 1st Building white line vertical
    glVertex2f(113.6,119);
    glVertex2f(113.6,140);
    glVertex2f(112,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(125,119);  /// 1st Building white line vertical
    glVertex2f(126.6,119);
    glVertex2f(126.6,140);
    glVertex2f(125,140);
    glEnd();

    ///End 1st Building//////////////////////////////////////////////////////////////////////



    ///2nd building main part/////////////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3ub(252, 58, 116);
    glVertex2f(200,120);
    glVertex2f(287,120);
    glVertex2f(287,395);
    glVertex2f(200,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(202.5,120);        //2nd building main part 2
    glVertex2f(284,120);
    glVertex2f(284,380);
    glVertex2f(202.5,380);
    glEnd();

   ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,125);   //part 2 2nd building 1st floor red.........
    glVertex2f(281,125);
    glVertex2f(281,155);
    glVertex2f(205,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,125);   //part 2 2nd building 1st floor.......red
    glVertex2f(267,125);
    glVertex2f(267,155);
    glVertex2f(281,155);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,160);  //2nd building 1st floor1
    glVertex2f(284,160);
    glVertex2f(284,175);
    glVertex2f(202.5,175);
    glEnd();

       ///....2nd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,180);   //part 2 2nd building 2nd floor red.........
    glVertex2f(281,180);
    glVertex2f(281,210);
    glVertex2f(205,210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,180);   //part 2 2nd building 2nd floor.......red
    glVertex2f(264,180);
    glVertex2f(264,210);
    glVertex2f(281,210);
    glEnd();


    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,215);  //2nd building 2nd floor1
    glVertex2f(284,215);
    glVertex2f(284,230);
    glVertex2f(202.5,230);
    glEnd();

    ///....3rd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,235);   //part 2 2nd building 3rd floor red.........
    glVertex2f(281,235);
    glVertex2f(281,265);
    glVertex2f(205,265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,235);   //part 2 2nd building 3rd floor.......red
    glVertex2f(264,235);
    glVertex2f(264,265);
    glVertex2f(281,265);
    glEnd();


    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,270);  //2nd building 3rd floor1
    glVertex2f(284,270);
    glVertex2f(284,285);
    glVertex2f(202.5,285);
    glEnd();

    ///....4th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,290);   //part 2 2nd building 4th floor red.........
    glVertex2f(281,290);
    glVertex2f(281,320);
    glVertex2f(205,320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,290);   //part 2 2nd building 4th floor.......red
    glVertex2f(264,290);
    glVertex2f(264,320);
    glVertex2f(281,320);
    glEnd();


     //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,325);  //2nd building 4th floor1
    glVertex2f(284,325);
    glVertex2f(284,340);
    glVertex2f(202.5,340);
    glEnd();

    ///....5th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,345);   //part 2 2nd building 5th floor red.........
    glVertex2f(281,345);
    glVertex2f(281,375);
    glVertex2f(205,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,345);   //part 2 2nd building 5th floor.......red
    glVertex2f(264,345);
    glVertex2f(264,375);
    glVertex2f(281,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(202,120);
    glVertex2f(237,120);
    glVertex2f(237,380);
    glVertex2f(202,380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 58, 116);
    glVertex2f(205,120);
    glVertex2f(234,120);
    glVertex2f(234,375);
    glVertex2f(205,375);
    glEnd();

    ///End 2nd building//////////////////////////////////////////////


    ///3rd Building Design///////////////////////////////////////////

    ///white part roof///
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(300,270);
    glVertex2f(378,340);
    glVertex2f(456,270);
    glEnd();

    ///blue roof part///
    glBegin(GL_TRIANGLES);
    glColor3ub(22, 0, 89);
    glVertex2f(320,280);
    glVertex2f(378,330);
    glVertex2f(435,280);
    glEnd();


///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(310,115);
    glVertex2f(446,115);
    glVertex2f(446,270);
    glVertex2f(310,270);
    glEnd();

    ///strip///
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,270);
    glVertex2f(446,270);
    glVertex2f(446,260);
    glVertex2f(310,260);
    glEnd();

    ///strip///
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,190);
    glVertex2f(446,190);
    glVertex2f(446,180);
    glVertex2f(310,180);
    glEnd();
/// strip
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,125);
    glVertex2f(446,125);
    glVertex2f(446,115);
    glVertex2f(310,115);
    glEnd();

    /// 4th Building Design/////////////////////////////////////////////////////
///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(470,115);
    glVertex2f(560,115);
    glVertex2f(560,405);
    glVertex2f(470,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 40, 3);
    glVertex2f(475,118);
    glVertex2f(555,118);
    glVertex2f(555,395);
    glVertex2f(475,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(513,118);
    glVertex2f(517,118);
    glVertex2f(517,395);
    glVertex2f(513,395);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(491,118);
    glVertex2f(495,118);
    glVertex2f(495,395);
    glVertex2f(491,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(532,118);
    glVertex2f(537,118);
    glVertex2f(537,395);
    glVertex2f(532,395);
    glEnd();


///5th Building Design//////////////////////////////////////////////////////////
///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 120);
    glVertex2f(575,90);
    glVertex2f(635,90);
    glVertex2f(635,475);
    glVertex2f(575,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(71, 255, 25);
    glVertex2f(597,200);        // Building main part 2
    glVertex2f(614,200);
    glVertex2f(614,460);
    glVertex2f(597,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 254, 254);
    glVertex2f(635,90);   // Building
    glVertex2f(667,90);
    glVertex2f(667,475);
    glVertex2f(635,475);
    glEnd();

     ///design of main building....1st and 3rd strip....

    glBegin(GL_QUADS);
    glColor3ub(252, 50, 50);
    glVertex2f(577.5,120);  //1st
    glVertex2f(592,120);
    glVertex2f(592,460);
    glVertex2f(577.5,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 144, 25);
    glVertex2f(620,255);  // 3rd
    glVertex2f(631,255);
    glVertex2f(631,460);
    glVertex2f(620,460);
    glEnd();

///////////////////////

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(665,90);  // part2 last black line
    glVertex2f(666,90);
    glVertex2f(666,460);
    glVertex2f(665,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,420);  //7 2nd part3
    glVertex2f(662.5,420);
    glVertex2f(662.5,460);
    glVertex2f(635,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,365);  //6 2nd part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,405);
    glVertex2f(635,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,310);  //5 part3
    glVertex2f(662.5,310);
    glVertex2f(662.5,350);
    glVertex2f(635,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,255);  //4 2nd part3
    glVertex2f(662.5,255);
    glVertex2f(662.5,295);
    glVertex2f(635,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,200);  //3 2nd part3
    glVertex2f(662.5,200);
    glVertex2f(662.5,240);
    glVertex2f(635,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,145);  //2 2nd part3
    glVertex2f(662.5,145);
    glVertex2f(662.5,185);
    glVertex2f(635,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(635,90);  //1 5th Building main part3
    glVertex2f(662.5,90);
    glVertex2f(662.5,130);
    glVertex2f(635,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(642,90);  //1 main part3
    glVertex2f(643,90);
    glVertex2f(643,130);
    glVertex2f(642,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(652,90);  //1 main part3
    glVertex2f(653,90);
    glVertex2f(653,130);
    glVertex2f(652,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(643,100);  //1 main part3
    glVertex2f(644,100);
    glVertex2f(644,120);
    glVertex2f(643,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(653,100);  ///1 main part3
    glVertex2f(654,100);
    glVertex2f(654,120);
    glVertex2f(653,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(635,90);   ///partation of Blue line
    glVertex2f(636,90);
    glVertex2f(636,460);
    glVertex2f(635,460);
    glEnd();

///End 5th Building/////////////////////////////////////////////////////////


/// Tree--------------------------------------------------Tree-------------------------------------------------------------------------------------------
    ///....3rd small circle tree ///
    glColor3ub(44, 94, 19);
    circle(3,6,468,101);
    glColor3ub(44, 94, 19);
    circle(5,12,463,111);
    glColor3ub(44, 94, 19);
    circle(5,12,473,111);
    glColor3ub(44, 94, 19);
    circle(5,12,478,106);
    glColor3ub(44, 94, 19);
    circle(5,12,458,121);


    glColor3ub(27, 140, 3);
    circle(5,12,463,123);
    glColor3ub(27, 140, 3);
    circle(5,12,464,123);
    glColor3ub(27, 140, 3);
    circle(5,12,468,141);
    glColor3ub(27, 140, 3);
    circle(4,10,463,136);
    glColor3ub(27, 140, 3);
    circle(4,10,465,134);

    glColor3ub(27, 140, 3);
    circle(4,10,466,133);

    glColor3ub(27, 140, 3);
    circle(5,12,478,131);
    glColor3ub(27, 140, 3);
    circle(5,12,473,131);
    glColor3ub(27, 140, 3);
    circle(5,12,472,126);
    glColor3ub(27, 140, 3);
    circle(5,12,471,125);
    glColor3ub(27, 140, 3);
    circle(5,12,483,121);
    glColor3ub(27, 140, 3);
    circle(5,12,478,116);
    glColor3ub(27, 140, 3);
    circle(5,12,477,116);
    glColor3ub(27, 140, 3);
    circle(5,12,468,119);
    glColor3ub(27, 140, 3);
    circle(5,12,480,141);



    glColor3ub(227, 91, 137);         ///Fruite.
    circle(1,2,468,119);
    glColor3ub(227, 91, 137);
    circle(1,2,468,133);
    glColor3ub(227, 91, 137);
    circle(1,2,478,133);
    glColor3ub(227, 91, 137);
    circle(1,2,483,128);
    glColor3ub(227, 91, 137);
    circle(1,2,457,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,463,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,464,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,478,106);
    glColor3ub(227, 91, 137);
    circle(1,3,483,119);
    glColor3ub(227, 91, 137);
    circle(1,3,473,103);


    glBegin(GL_TRIANGLE_FAN);  ///wood ........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(475,100);
    glVertex2f(470,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(472,100);
    glVertex2f(466,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(472,90);
    glVertex2f(476,90);
    glVertex2f(477,110);
    glVertex2f(480,140);
    glEnd();
///End 3rd small circle tree////////////////////////////////////////////////////////////


/// 2nd big tree leaf circle////////////////////////////////////////////////////////////

    glColor3ub(56, 183, 27);
    circle(8,22,500,150);
    glColor3ub(56, 183, 27);
    circle(8,22,510,170);
    glColor3ub(56, 183, 27);
    circle(8,22,513,140);
    glColor3ub(56, 183, 27);
    circle(7,25,522,150);
    glColor3ub(56, 183, 27);
    circle(8,22,530,150);
    glColor3ub(56, 183, 27);
    circle(10,40,500,250);

    glColor3ub(56, 183, 27);
    circle(9,22,530,295);
    glColor3ub(56, 183, 27);
    circle(8,15,530,293);

    glColor3ub(56, 183, 27);
    circle(9,22,545,285);
    glColor3ub(56, 183, 27);
    circle(9,22,545,280);
    glColor3ub(56, 183, 27);
    circle(8,15,545,275);

    glColor3ub(56, 183, 27);
    circle(9,22,555,235);
    glColor3ub(56, 183, 27);
    circle(9,32,550,255);

    glColor3ub(56, 183, 27);
    circle(9,22,559,225);
    glColor3ub(56, 183, 27);
    circle(9,22,556,255);
    glColor3ub(56, 183, 27);
    circle(9,22,563,195);
    glColor3ub(56, 183, 27);
    circle(9,22,550,180);
    glColor3ub(56, 183, 27);
    circle(9,22,558,165);
    glColor3ub(56, 183, 27);
    circle(9,22,549,150);
    glColor3ub(56, 183, 27);
    circle(9,22,538,140);


    glColor3ub(0, 77, 26);
    circle(10,20,555,190);
    glColor3ub(12, 165, 25);
    circle(9.5,19,555,190);


    glColor3ub(0, 77, 26);
    circle(10,20,555,205);
    glColor3ub(12, 165, 25);
    circle(9.5,20,555,205);


    glColor3ub(0, 77, 26);
    circle(10,20,550,218);
    glColor3ub(12, 165, 25);
    circle(9.5,20,550,218);


    glColor3ub(12, 165, 25);
    circle(10,20,527,130);


    glColor3ub(12, 165, 25);
    circle(35,70,520,200);
    glColor3ub(12, 165, 25);
    circle(15,30,530,255);


    glColor3ub(0, 77, 26);
    circle(10,20,542,225);
    glColor3ub(12, 165, 25);
    circle(9.5,20,542,224);


    glColor3ub(0, 77, 26);
    circle(10,20,530,225);
    glColor3ub(12, 165, 25);
    circle(10,20,530,224);


    glColor3ub(0, 77, 26);
    circle(10,18,542,263);
    glColor3ub(12, 165, 25);
    circle(10,18,542,262);


    glColor3ub(0, 77, 26);
    circle(10,20,530,180);
    glColor3ub(12, 165, 25);
    circle(10,20,530,179);

    glColor3ub(0, 77, 26);
    circle(10,20,520,180);
    glColor3ub(12, 165, 25);
    circle(10,20,520,179);

    glColor3ub(0, 77, 26);
    circle(10,20,540,155);
    glColor3ub(12, 165, 25);
    circle(10,20,540,156);


    glColor3ub(12, 165, 25);
    circle(9,22,520,280);
    glColor3ub(0, 77, 26);
    circle(9,21,520,270);
    glColor3ub(12, 165, 25);
    circle(9,21,520,269);


    glColor3ub(12, 165, 25);
    circle(9,22,510,255);
    glColor3ub(0, 77, 26);
    circle(9,20,510,245);
    glColor3ub(12, 165, 25);
    circle(9,20,510.5,244);


    glColor3ub(12, 165, 25);
    circle(9,22,485,245);
    glColor3ub(0, 77, 26);
    circle(9,20,485,235);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,234);


    glColor3ub(56, 183, 27);
    circle(9,22,485,205);
    glColor3ub(0, 77, 26);
    circle(9,20,485,195);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,194);


    glColor3ub(12, 165, 25);
    circle(9,22,509,288);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,164);
    glColor3ub(0, 77, 26);
    circle(9,20,495,165);
    glColor3ub(12, 165, 25);
    circle(9,20,495,164);


    ///2nd big........Tree........D-1........///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex2f(515,90);
    glVertex2f(522,90);
    glVertex2f(521,100);
    glVertex2f(520,110);
    glVertex2f(518,120);
    glVertex2f(516,130);
    glVertex2f(517,140);
    glVertex2f(518,145);
    glVertex2f(520,150);
    glVertex2f(522,150);
    glVertex2f(521,147);
    glVertex2f(520,145);
    glVertex2f(518,140);
    glVertex2f(516,130);
    glVertex2f(513,120);
    glVertex2f(516,130);
    glVertex2f(518,140);
    glVertex2f(520,145);
    glVertex2f(522,150);
    glVertex2f(522,160);
    glVertex2f(518,150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///........Tree........D-2.......///
    glColor3ub(575,35,5);
    glVertex2f(515,125);
    glVertex2f(519,130);
    glVertex2f(514,140);
    glVertex2f(514,150);
    glVertex2f(513,160);
    glVertex2f(510,170);
    glVertex2f(512,170);
    glVertex2f(512,160);
    glVertex2f(511,150);
    glVertex2f(511,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   /// tree...................D-3 p2  ///
    glColor3ub(575,35,5);
    glVertex2f(531,140);
    glVertex2f(529,140);
    glVertex2f(528,120);
    glVertex2f(525,120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  /// tree..................D-3 p1   ///
    glColor3ub(575,35,5);
    glVertex2f(516,100);
    glVertex2f(521,100);
    glVertex2f(524.5,120);
    glVertex2f(528,120);
    glEnd();

///end 2nd big tree//////////////////////////////////////////////////////


///....2nd small circle tree..... /////////////////////////////////////
    glColor3ub(27, 140, 3);
    circle(3,6,280,101);
    glColor3ub(27, 140, 3);
    circle(5,12,275,111);
    glColor3ub(27, 140, 3);
    circle(5,12,285,111);
    glColor3ub(27, 140, 3);
    circle(5,12,290,106);
    glColor3ub(27, 140, 3);
    circle(5,12,270,121);


    glColor3ub(26, 81, 14);
    circle(5,12,275,123);
    glColor3ub(26, 81, 14);
    circle(5,12,276,123);
    glColor3ub(26, 81, 14);
    circle(5,12,280,141);
    glColor3ub(26, 81, 14);
    circle(4,10,275,136);
    glColor3ub(26, 81, 14);
    circle(4,10,277,134);

    glColor3ub(26, 81, 14);
    circle(4,10,278,133);

    glColor3ub(26, 81, 14);
    circle(5,12,290,131);
    glColor3ub(26, 81, 14);
    circle(5,12,285,131);
    glColor3ub(26, 81, 14);
    circle(5,12,284,126);
    glColor3ub(26, 81, 14);
    circle(5,12,283,125);
    glColor3ub(26, 81, 14);
    circle(5,12,295,121);
    glColor3ub(26, 81, 14);
    circle(5,12,290,116);
    glColor3ub(26, 81, 14);
    circle(5,12,289,116);
    glColor3ub(26, 81, 14);
    circle(5,12,280,119);
    glColor3ub(26, 81, 14);
    circle(5,12,292,141);



    glColor3ub(227, 91, 137);         ///Fruite.
    circle(1,2,280,119);
    glColor3ub(227, 91, 137);
    circle(1,2,280,133);
    glColor3ub(227, 91, 137);
    circle(1,2,290,133);
    glColor3ub(227, 91, 137);
    circle(1,2,295,128);
    glColor3ub(227, 91, 137);
    circle(1,2,269,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,275,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,276,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,290,106);
    glColor3ub(227, 91, 137);
    circle(1,3,295,119);
    glColor3ub(227, 91, 137);
    circle(1,3,285,103);


    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(287,100);
    glVertex2f(282,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(284,100);
    glVertex2f(278,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood.......6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(284,90);
    glVertex2f(288,90);
    glVertex2f(289,110);
    glVertex2f(292,140);
    glEnd();
///End  2nd smallL circle tree///


///1st tree leaf circle///////////////////////////////////////////

    glColor3ub(56, 183, 27);
    circle(8,22,0,150);
    glColor3ub(56, 183, 27);
    circle(8,22,10,170);
    glColor3ub(56, 183, 27);
    circle(8,22,13,140);
    glColor3ub(56, 183, 27);
    circle(7,25,22,150);
    glColor3ub(56, 183, 27);
    circle(8,22,30,150);
    glColor3ub(56, 183, 27);
    circle(10,40,0,250);

    glColor3ub(56, 183, 27);
    circle(9,22,30,295);
    glColor3ub(56, 183, 27);
    circle(8,15,30,293);

    glColor3ub(56, 183, 27);
    circle(9,22,45,285);
    glColor3ub(56, 183, 27);
    circle(9,22,45,280);
    glColor3ub(56, 183, 27);
    circle(8,15,45,275);

    glColor3ub(56, 183, 27);
    circle(9,22,55,235);
    glColor3ub(56, 183, 27);
    circle(9,32,50,255);

    glColor3ub(56, 183, 27);
    circle(9,22,59,225);
    glColor3ub(56, 183, 27);
    circle(9,22,56,255);
    glColor3ub(56, 183, 27);
    circle(9,22,63,195);
    glColor3ub(56, 183, 27);
    circle(9,22,50,180);
    glColor3ub(56, 183, 27);
    circle(9,22,58,165);
    glColor3ub(56, 183, 27);
    circle(9,22,49,150);
    glColor3ub(56, 183, 27);
    circle(9,22,38,140);


    glColor3ub(0, 77, 26);
    circle(10,20,55,190);
    glColor3ub(12, 165, 25);
    circle(9.5,19,55,190);


    glColor3ub(0, 77, 26);
    circle(10,20,55,205);
    glColor3ub(12, 165, 25);
    circle(9.5,20,55,205);


    glColor3ub(0, 77, 26);
    circle(10,20,50,218);
    glColor3ub(12, 165, 25);
    circle(9.5,20,50,218);


    glColor3ub(12, 165, 25);
    circle(10,20,27,130);


    glColor3ub(12, 165, 25);
    circle(35,70,20,200);
    glColor3ub(12, 165, 25);
    circle(15,30,30,255);


    glColor3ub(0, 77, 26);
    circle(10,20,42,225);
    glColor3ub(12, 165, 25);
    circle(9.5,20,42,224);


    glColor3ub(0, 77, 26);
    circle(10,20,30,225);
    glColor3ub(12, 165, 25);
    circle(10,20,30,224);


    glColor3ub(0, 77, 26);
    circle(10,18,42,263);
    glColor3ub(12, 165, 25);
    circle(10,18,42,262);


    glColor3ub(0, 77, 26);
    circle(10,20,30,180);
    glColor3ub(12, 165, 25);
    circle(10,20,30,179);

    glColor3ub(0, 77, 26);
    circle(10,20,20,180);
    glColor3ub(12, 165, 25);
    circle(10,20,20,179);

    glColor3ub(0, 77, 26);
    circle(10,20,40,155);
    glColor3ub(12, 165, 25);
    circle(10,20,40,156);


    glColor3ub(12, 165, 25);
    circle(9,22,20,280);
    glColor3ub(0, 77, 26);
    circle(9,21,20,270);
    glColor3ub(12, 165, 25);
    circle(9,21,20,269);


    glColor3ub(12, 165, 25);
    circle(9,22,10,255);
    glColor3ub(0, 77, 26);
    circle(9,20,10,245);
    glColor3ub(12, 165, 25);
    circle(9,20,10.5,244);


    ///1st........Tree........D-1........///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex2f(15,90);
    glVertex2f(22,90);
    glVertex2f(21,100);
    glVertex2f(20,110);
    glVertex2f(18,120);
    glVertex2f(16,130);
    glVertex2f(17,140);
    glVertex2f(18,145);
    glVertex2f(20,150);
    glVertex2f(22,150);
    glVertex2f(21,147);
    glVertex2f(20,145);
    glVertex2f(18,140);
    glVertex2f(16,130);
    glVertex2f(13,120);
    glVertex2f(16,130);
    glVertex2f(18,140);
    glVertex2f(20,145);
    glVertex2f(22,150);
    glVertex2f(22,160);
    glVertex2f(18,150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///1st........Tree........D-2.......///
    glColor3ub(75,35,5);
    glVertex2f(15,125);
    glVertex2f(19,130);
    glVertex2f(14,140);
    glVertex2f(14,150);
    glVertex2f(13,160);
    glVertex2f(10,170);
    glVertex2f(12,170);
    glVertex2f(12,160);
    glVertex2f(11,150);
    glVertex2f(11,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   ///1st tree...................D-3 p2  ///
    glColor3ub(75,35,5);
    glVertex2f(31,140);
    glVertex2f(29,140);
    glVertex2f(28,120);
    glVertex2f(25,120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///1st tree..................D-3 p1   ///
    glColor3ub(75,35,5);
    glVertex2f(16,100);
    glVertex2f(21,100);
    glVertex2f(24.5,120);
    glVertex2f(28,120);
    glEnd();
///End !st small tree////////////////////////////////////////////////////////////////

///5th small tree////////////////////////////////////////////////////////////////////
    glColor3ub(0, 153, 51);
    circle(3,6,575,100);
    glColor3ub(0, 153, 51);
    circle(5,12,570,110);
    glColor3ub(0, 153, 51);
    circle(5,12,580,110);
    glColor3ub(0, 153, 51);
    circle(5,12,585,105);
    glColor3ub(0, 153, 51);
    circle(5,12,565,120);


    glColor3ub(0, 102, 00);
    circle(5,12,570,122);
    glColor3ub(0, 153, 51);
    circle(5,12,571,122);
    glColor3ub(0, 153, 51);
    circle(5,12,575,140);
    glColor3ub(0, 153, 51);
    circle(4,10,570,135);
    glColor3ub(0, 102, 0);
    circle(4,10,572,133);

    glColor3ub(0, 153, 51);
    circle(4,10,573,132);

    glColor3ub(0, 153, 51);
    circle(5,12,585,130);
    glColor3ub(0, 153, 51);
    circle(5,12,580,130);
    glColor3ub(0, 102, 0);
    circle(5,12,579,125);
    glColor3ub(0, 153, 51);
    circle(5,12,578,124);
    glColor3ub(0, 153, 51);
    circle(5,12,590,120);
    glColor3ub(0, 102, 0);
    circle(5,12,585,115);
    glColor3ub(0, 153, 51);
    circle(5,12,584,115);
    glColor3ub(0, 153, 51);
    circle(5,12,575,118);
    glColor3ub(0, 153, 51);
    circle(5,12,587,140);



    glColor3ub(255, 255, 255);         ///5th..........tree fruite.
    circle(1,2,575,118);
    glColor3ub(255, 255, 255);
    circle(1,2,575,138);
    glColor3ub(255, 255, 255);
    circle(1,2,585,138);
    glColor3ub(255, 255, 255);
    circle(1,2,580,127);
    glColor3ub(255, 255, 255);
    circle(1,2,564,118);
    glColor3ub(255, 255, 255);
    circle(1,2.5,570,133);
    glColor3ub(255, 255, 255);
    circle(1,1.5,571,109);
    glColor3ub(255, 255, 255);
    circle(1,2.5,585,105);
    glColor3ub(255, 255, 255);
    circle(1,3,590,118);
    glColor3ub(255, 255, 255);
    circle(1,3,585,120);


    glBegin(GL_TRIANGLE_FAN);  ///5th tree.........wood  ///
    glColor3ub(75,35,5);
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(582,100);
    glVertex2f(577,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood  ///
    glColor3ub(75,35,5);
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(579,100);
    glVertex2f(573,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood   ///
    glColor3ub(75,35,5);
    glVertex2f(579,90);
    glVertex2f(583,90);
    glVertex2f(584,110);
    glVertex2f(587,140);
    glEnd();

///End 5th small tree///////////////////////////////////////////////////////

///waiting room/////////////////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3ub(196, 66, 145);
    glVertex2f(375,110);  //body..........
    glVertex2f(410,110);
    glVertex2f(410,155);
    glVertex2f(375,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(171, 29, 140);
    glVertex2f(370,160);  //roof..........
    glVertex2f(415,160);
    glVertex2f(410,168);
    glVertex2f(375,168);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(374,105);  //left stip..........
    glVertex2f(376,105);
    glVertex2f(376,160);
    glVertex2f(374,160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(391,105);  //middle stip..........
    glVertex2f(393,105);
    glVertex2f(393,160);
    glVertex2f(391,160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(379,115);  //sit stip..........
    glVertex2f(388,115);
    glVertex2f(388,118);
    glVertex2f(379,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(379,105);  //sit left stip..........
    glVertex2f(380,105);
    glVertex2f(380,118);
    glVertex2f(379,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(387,105);  //sit stip..........
    glVertex2f(388,105);
    glVertex2f(388,118);
    glVertex2f(387,118);
    glEnd();


glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(409,105);  //right stip..........
    glVertex2f(411,105);
    glVertex2f(411,160);
    glVertex2f(409,160);
    glEnd();

    //chair

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(330,105);  //left stip..........
    glVertex2f(332,105);
    glVertex2f(332,140);
    glVertex2f(330,140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(351,105);  //right stip..........
    glVertex2f(353,105);
    glVertex2f(353,140);
    glVertex2f(351,140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(320,115);  //sit stip..........
    glVertex2f(361,115);
    glVertex2f(361,118);
    glVertex2f(320,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,123);  //back stip..........
    glVertex2f(358,123);
    glVertex2f(358,126);
    glVertex2f(323,126);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,128);  //back stip..........
    glVertex2f(358,128);
    glVertex2f(358,131);
    glVertex2f(323,131);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,133);  //back stip..........
    glVertex2f(358,133);
    glVertex2f(358,136);
    glVertex2f(323,136);
    glEnd();

///Sky----------------------------------------------------------------------SKY-----------------------------------------------------

    glColor3ub(253, 183, 77);    ///.........S U N.....................////////////////////////
    circle(18,36,400,705);
    glColor3ub(253, 183, 77);
    circle(16.5,33,400,705);
    glColor3ub(253, 183, 77);
    circle(14.5,30,400,705);
    glColor3ub(253, 183, 77);
    circle(12.5,27,400,705);


    glColor3ub(232,241,255);        ///....Megh.......1 covering sun..../////////////////////////
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

    glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);


    glColor3ub(232,241,255);        ///....Megh.......2.....///////////////////////////////////////////////////
    circle(13,20,p+200,745);
    glColor3ub(252,254,255);
    circle(11,18,p+200,745);

    glColor3ub(232,241,255);
    circle(10,20,p+210,755);
    glColor3ub(252,254,255);
    circle(10,20,p+212,762);

    glColor3ub(232,241,255);
    circle(13,20,p+210,735);

    glColor3ub(221,229,247);
    circle(9,20,p+220,750);
    glColor3ub(252,254,255);
    circle(8,18,p+220,759);

    glColor3ub(232,241,255);
    circle(9,20,p+220,756);
    glColor3ub(252,254,255);
    circle(8,18,p+220,752);

    glColor3ub(232,241,255);
    circle(9,20,p+230,765);
    glColor3ub(252,254,255);
    circle(8,18,p+230,761);

    glColor3ub(232,241,255);
    circle(9,20,p+225,745);
    glColor3ub(252,254,255);
    circle(8,18,p+235,747);

    glColor3ub(232,241,255);
    circle(9,20,p+240,755);

    glColor3ub(221,229,247);
    circle(8,18,p+243,745);
    glColor3ub(252,254,255);
    circle(8,18,p+240,743);
    glColor3ub(173,197,224);
    circle(8,18,p+230,733);
    glColor3ub(252,254,255);
    circle(8,18,p+230,738);
    glColor3ub(173,197,224);
    circle(8,18,p+220,723);
    glColor3ub(252,254,255);
    circle(8,18,p+220,728);



    glColor3ub(252,254,255);
    circle(23,9,p+245,744);
    glColor3ub(173,197,224);
    circle(21,10,p+240,720);
    glColor3ub(252,254,255);
    circle(21,11,p+238,723);


    glColor3ub(252,254,255);
    circle(18,18,p+210,744);
    glColor3ub(252,254,255);
    circle(18,25,p+220,745);

    glColor3ub(173,197,224);
    circle(10,20,p+235,715);
    glColor3ub(252,254,255);
    circle(10,20,p+235,719);



    glColor3ub(173,197,224);        ///....Megh.......3.....//////////////////////////////////////
    circle(9,15,p+20,685);
    glColor3ub(252,254,255);
    circle(6,14,p+21,685);

    glColor3ub(232,241,255);
    circle(7,16,p+30,695);
    glColor3ub(252,254,255);
    circle(7,14,p+32,692);

    glColor3ub(252,254,255);
    circle(12,16,p+28,680);

    glColor3ub(221,229,247);
    circle(10,15,p+45,690);
    glColor3ub(252,254,255);
    circle(9,13,p+43,685);
    glColor3ub(252,254,255);
    circle(15,18,p+48,670);

    glColor3ub(173,197,224);
    circle(6,14,p+30,680);
    glColor3ub(252,254,255);
    circle(6,13,p+30,677);

    glColor3ub(173,197,224);
    circle(6,14,p+38,668);
    glColor3ub(252,254,255);
    circle(6,13,p+36,667);


    glColor3ub(252,254,255);
    circle(11,15,p+29,668);

     ///....Megh.......4.....///////////////////////////////////////////////////////

    glColor3ub(173,197,224);
    circle(9,15,590,695);
    glColor3ub(252,254,255);
    circle(6,14,591,695);

    glColor3ub(232,241,255);
    circle(7,16,600,705);
    glColor3ub(252,254,255);
    circle(7,14,602,702);

    glColor3ub(252,254,255);
    circle(12,16,598,690);

    glColor3ub(221,229,247);
    circle(10,15,615,700);
    glColor3ub(252,254,255);
    circle(9,13,613,695);
    glColor3ub(252,254,255);
    circle(15,18,618,680);

    glColor3ub(173,197,224);
    circle(6,14,600,690);
    glColor3ub(252,254,255);
    circle(6,13,600,687);

    glColor3ub(173,197,224);
    circle(6,14,608,678);
    glColor3ub(252,254,255);
    circle(6,13,606,677);


    glColor3ub(252,254,255);
    circle(11,15,599,678);



    if(p<= 800)
        p = p + 0.1;
    else
        p = -10;



///-------------------------------------------------------------------------------------------------------------------------------------------------



// Draw blue targets as helicopters
for (const auto& target : blueTargets) {
    if (!target.isHit) {
        draw_helicopter(target.x - 375, target.y - 600); // Adjust offsets if needed
    }
}

for (const auto& target : ambulanceTargets) {
        if (!target.isHit) {
            drawAmbulance(target.x - 50, target.y - 50);
        }
    }

    // Draw bus targets
    for (const auto& target : busTargets) {
        if (!target.isHit) {
            drawBus(target.x - 50, target.y - 50);
        }
    }

    /*for (const auto& target : carTargets) {
        if (!target.isHit) {
            drawCar(target.x - 50, target.y - 50);
        }
    }*/



    // Draw crosshair
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(crosshairX - 10, crosshairY);
    glVertex2f(crosshairX + 10, crosshairY);
    glVertex2f(crosshairX, crosshairY - 20);
    glVertex2f(crosshairX, crosshairY + 20);
    glEnd();


    // Display score and level
glColor3f(1.0f, 1.0f, 1.0f);
glRasterPos2f(20.0f, 770.0f); // Position near the top-left corner
string hud = "Score: " + to_string(score) + " Level: " + to_string(level) + " High Score: " + to_string(highScore);
for (char c : hud) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// Display game over message if needed
if (gameOver) {
handleGameOver();
glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(250.0f, 400.0f); // Centered horizontally, middle of the screen
    string message = "Game Over! Press R to Restart";
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


    glutSwapBuffers();
}

void displayLevel2() {///##########################################################################################################
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);//sky white
    glColor3ub(255, 255, 147);
    glVertex2f(0,100);
    glVertex2f(800,100);
   // glColor3ub(102, 204, 255);
    glVertex2f(800,800);
    glVertex2f(0,800);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(16, 208, 0);
    glVertex2f(0,100);        //number 1 green step
    glVertex2f(800,100);
    glVertex2f(800,119.5);
    glVertex2f(0,119.5);
    glEnd();

    glBegin(GL_QUADS);//gray road
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0,30);
    glVertex2f(800,30);
    glVertex2f(800,80);
    glVertex2f(0,80);
    glEnd();

    glBegin(GL_LINES);//Road top bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,81);
    glVertex2i(800,81);
    glEnd();

    glBegin(GL_LINES);//Road middle bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,62);
    glVertex2i(800,62);
    glEnd();

    glBegin(GL_LINES);//Road Bottop bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2i(0,39);
    glVertex2i(800,39);
    glEnd();


    glBegin(GL_QUADS);// 2nd green bar
    glColor3ub(12, 165, 25);
    glVertex2f(0,82);
    glVertex2f(800,82);
    glVertex2f(800,90);
    glVertex2f(0,90);
    glEnd();

    glBegin(GL_QUADS);// 3rd green bar
    glColor3ub(30, 208, 15);
    glVertex2f(0,38);
    glVertex2f(800,38);
    glVertex2f(800,0);
    glVertex2f(0,0);
    glEnd();

   ///-------------------------------------------------------------------------------------------------------------------------------------------------

    ///1st Building Design///Top////////////////////////////////////////////////////////


///white part///
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);///1st Building main part 2
    glVertex2f(72.5,119);
    glVertex2f(165.5,119);
    glVertex2f(165.5,442);
    glVertex2f(72.5,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 154, 255);
    glVertex2f(75,119);        ///1st Building main part 2
    glVertex2f(163,119);
    glVertex2f(163,434);
    glVertex2f(75,434);
    glEnd();

    ///floor divided y+40//
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,150);  ///1st Building 1st floor1
    glVertex2f(163,150);
    glVertex2f(163,154);
    glVertex2f(75,154);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,190);  ///1st Building 2nd floor1
    glVertex2f(163,190);
    glVertex2f(163,193);
    glVertex2f(75,193);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,230);  ///1st Building 3rd floor1
    glVertex2f(163,230);
    glVertex2f(163,234);
    glVertex2f(75,234);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,270);  ///1st Building 4th floor1
    glVertex2f(163,270);
    glVertex2f(163,273);
    glVertex2f(75,273);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,310);  ///1st Building 5th floor1
    glVertex2f(163,310);
    glVertex2f(163,314);
    glVertex2f(75,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,310);  ///1st Building 6th floor1
    glVertex2f(163,310);
    glVertex2f(163,314);
    glVertex2f(75,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,350);  ///1st Building 7th floor1
    glVertex2f(163,350);
    glVertex2f(163,353);
    glVertex2f(75,353);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(75,390);  ///1st Building 8th floor1
    glVertex2f(163,390);
    glVertex2f(163,394);
    glVertex2f(75,394);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(105,119);  /// 1st Building white line vertical
    glVertex2f(105.5,119);
    glVertex2f(105.5,440);
    glVertex2f(105,440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(133,119);  /// 1st Building white line vertical
    glVertex2f(133.5,119);
    glVertex2f(133.5,440);
    glVertex2f(133,440);
    glEnd();


    ///Door
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(112,140);  ///1st Building 1st floor1
    glVertex2f(127,140);
    glVertex2f(127,144);
    glVertex2f(112,144);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(112,119);  /// 1st Building white line vertical
    glVertex2f(113.6,119);
    glVertex2f(113.6,140);
    glVertex2f(112,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(125,119);  /// 1st Building white line vertical
    glVertex2f(126.6,119);
    glVertex2f(126.6,140);
    glVertex2f(125,140);
    glEnd();

    ///End 1st Building//////////////////////////////////////////////////////////////////////



    ///2nd building main part/////////////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3ub(252, 58, 116);
    glVertex2f(200,120);
    glVertex2f(287,120);
    glVertex2f(287,395);
    glVertex2f(200,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(202.5,120);        //2nd building main part 2
    glVertex2f(284,120);
    glVertex2f(284,380);
    glVertex2f(202.5,380);
    glEnd();

   ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,125);   //part 2 2nd building 1st floor red.........
    glVertex2f(281,125);
    glVertex2f(281,155);
    glVertex2f(205,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,125);   //part 2 2nd building 1st floor.......red
    glVertex2f(267,125);
    glVertex2f(267,155);
    glVertex2f(281,155);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,160);  //2nd building 1st floor1
    glVertex2f(284,160);
    glVertex2f(284,175);
    glVertex2f(202.5,175);
    glEnd();

       ///....2nd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,180);   //part 2 2nd building 2nd floor red.........
    glVertex2f(281,180);
    glVertex2f(281,210);
    glVertex2f(205,210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,180);   //part 2 2nd building 2nd floor.......red
    glVertex2f(264,180);
    glVertex2f(264,210);
    glVertex2f(281,210);
    glEnd();


    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,215);  //2nd building 2nd floor1
    glVertex2f(284,215);
    glVertex2f(284,230);
    glVertex2f(202.5,230);
    glEnd();

    ///....3rd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,235);   //part 2 2nd building 3rd floor red.........
    glVertex2f(281,235);
    glVertex2f(281,265);
    glVertex2f(205,265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,235);   //part 2 2nd building 3rd floor.......red
    glVertex2f(264,235);
    glVertex2f(264,265);
    glVertex2f(281,265);
    glEnd();


    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,270);  //2nd building 3rd floor1
    glVertex2f(284,270);
    glVertex2f(284,285);
    glVertex2f(202.5,285);
    glEnd();

    ///....4th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,290);   //part 2 2nd building 4th floor red.........
    glVertex2f(281,290);
    glVertex2f(281,320);
    glVertex2f(205,320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,290);   //part 2 2nd building 4th floor.......red
    glVertex2f(264,290);
    glVertex2f(264,320);
    glVertex2f(281,320);
    glEnd();


     //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,325);  //2nd building 4th floor1
    glVertex2f(284,325);
    glVertex2f(284,340);
    glVertex2f(202.5,340);
    glEnd();

    ///....5th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(205,345);   //part 2 2nd building 5th floor red.........
    glVertex2f(281,345);
    glVertex2f(281,375);
    glVertex2f(205,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 79, 148);
    glVertex2f(281,345);   //part 2 2nd building 5th floor.......red
    glVertex2f(264,345);
    glVertex2f(264,375);
    glVertex2f(281,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(202,120);
    glVertex2f(237,120);
    glVertex2f(237,380);
    glVertex2f(202,380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 58, 116);
    glVertex2f(205,120);
    glVertex2f(234,120);
    glVertex2f(234,375);
    glVertex2f(205,375);
    glEnd();

    ///End 2nd building//////////////////////////////////////////////


    ///3rd Building Design///////////////////////////////////////////

    ///white part roof///
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(300,270);
    glVertex2f(378,340);
    glVertex2f(456,270);
    glEnd();

    ///blue roof part///
    glBegin(GL_TRIANGLES);
    glColor3ub(22, 0, 89);
    glVertex2f(320,280);
    glVertex2f(378,330);
    glVertex2f(435,280);
    glEnd();


///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(310,115);
    glVertex2f(446,115);
    glVertex2f(446,270);
    glVertex2f(310,270);
    glEnd();

    ///strip///
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,270);
    glVertex2f(446,270);
    glVertex2f(446,260);
    glVertex2f(310,260);
    glEnd();

    ///strip///
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,190);
    glVertex2f(446,190);
    glVertex2f(446,180);
    glVertex2f(310,180);
    glEnd();
/// strip
    glBegin(GL_QUADS);
    glColor3ub(22, 0, 89);
    glVertex2f(310,125);
    glVertex2f(446,125);
    glVertex2f(446,115);
    glVertex2f(310,115);
    glEnd();

    /// 4th Building Design/////////////////////////////////////////////////////
///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(470,115);
    glVertex2f(560,115);
    glVertex2f(560,405);
    glVertex2f(470,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 40, 3);
    glVertex2f(475,118);
    glVertex2f(555,118);
    glVertex2f(555,395);
    glVertex2f(475,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(513,118);
    glVertex2f(517,118);
    glVertex2f(517,395);
    glVertex2f(513,395);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(491,118);
    glVertex2f(495,118);
    glVertex2f(495,395);
    glVertex2f(491,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 255, 255);
    glVertex2f(532,118);
    glVertex2f(537,118);
    glVertex2f(537,395);
    glVertex2f(532,395);
    glEnd();


///5th Building Design//////////////////////////////////////////////////////////
///white part///
    glBegin(GL_QUADS);
    glColor3ub(253, 255, 120);
    glVertex2f(575,90);
    glVertex2f(635,90);
    glVertex2f(635,475);
    glVertex2f(575,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(71, 255, 25);
    glVertex2f(597,200);        // Building main part 2
    glVertex2f(614,200);
    glVertex2f(614,460);
    glVertex2f(597,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(254, 254, 254);
    glVertex2f(635,90);   // Building
    glVertex2f(667,90);
    glVertex2f(667,475);
    glVertex2f(635,475);
    glEnd();

     ///design of main building....1st and 3rd strip....

    glBegin(GL_QUADS);
    glColor3ub(252, 50, 50);
    glVertex2f(577.5,120);  //1st
    glVertex2f(592,120);
    glVertex2f(592,460);
    glVertex2f(577.5,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 144, 25);
    glVertex2f(620,255);  // 3rd
    glVertex2f(631,255);
    glVertex2f(631,460);
    glVertex2f(620,460);
    glEnd();

///////////////////////

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(665,90);  // part2 last black line
    glVertex2f(666,90);
    glVertex2f(666,460);
    glVertex2f(665,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,420);  //7 2nd part3
    glVertex2f(662.5,420);
    glVertex2f(662.5,460);
    glVertex2f(635,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,365);  //6 2nd part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,405);
    glVertex2f(635,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,310);  //5 part3
    glVertex2f(662.5,310);
    glVertex2f(662.5,350);
    glVertex2f(635,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,255);  //4 2nd part3
    glVertex2f(662.5,255);
    glVertex2f(662.5,295);
    glVertex2f(635,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,200);  //3 2nd part3
    glVertex2f(662.5,200);
    glVertex2f(662.5,240);
    glVertex2f(635,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(25, 125, 255);
    glVertex2f(635,145);  //2 2nd part3
    glVertex2f(662.5,145);
    glVertex2f(662.5,185);
    glVertex2f(635,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(635,90);  //1 5th Building main part3
    glVertex2f(662.5,90);
    glVertex2f(662.5,130);
    glVertex2f(635,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(642,90);  //1 main part3
    glVertex2f(643,90);
    glVertex2f(643,130);
    glVertex2f(642,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(652,90);  //1 main part3
    glVertex2f(653,90);
    glVertex2f(653,130);
    glVertex2f(652,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(643,100);  //1 main part3
    glVertex2f(644,100);
    glVertex2f(644,120);
    glVertex2f(643,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(653,100);  ///1 main part3
    glVertex2f(654,100);
    glVertex2f(654,120);
    glVertex2f(653,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(635,90);   ///partation of Blue line
    glVertex2f(636,90);
    glVertex2f(636,460);
    glVertex2f(635,460);
    glEnd();

///End 5th Building/////////////////////////////////////////////////////////


/// Tree--------------------------------------------------Tree-------------------------------------------------------------------------------------------
    ///....3rd small circle tree ///
    glColor3ub(44, 94, 19);
    circle(3,6,468,101);
    glColor3ub(44, 94, 19);
    circle(5,12,463,111);
    glColor3ub(44, 94, 19);
    circle(5,12,473,111);
    glColor3ub(44, 94, 19);
    circle(5,12,478,106);
    glColor3ub(44, 94, 19);
    circle(5,12,458,121);


    glColor3ub(27, 140, 3);
    circle(5,12,463,123);
    glColor3ub(27, 140, 3);
    circle(5,12,464,123);
    glColor3ub(27, 140, 3);
    circle(5,12,468,141);
    glColor3ub(27, 140, 3);
    circle(4,10,463,136);
    glColor3ub(27, 140, 3);
    circle(4,10,465,134);

    glColor3ub(27, 140, 3);
    circle(4,10,466,133);

    glColor3ub(27, 140, 3);
    circle(5,12,478,131);
    glColor3ub(27, 140, 3);
    circle(5,12,473,131);
    glColor3ub(27, 140, 3);
    circle(5,12,472,126);
    glColor3ub(27, 140, 3);
    circle(5,12,471,125);
    glColor3ub(27, 140, 3);
    circle(5,12,483,121);
    glColor3ub(27, 140, 3);
    circle(5,12,478,116);
    glColor3ub(27, 140, 3);
    circle(5,12,477,116);
    glColor3ub(27, 140, 3);
    circle(5,12,468,119);
    glColor3ub(27, 140, 3);
    circle(5,12,480,141);



    glColor3ub(227, 91, 137);         ///Fruite.
    circle(1,2,468,119);
    glColor3ub(227, 91, 137);
    circle(1,2,468,133);
    glColor3ub(227, 91, 137);
    circle(1,2,478,133);
    glColor3ub(227, 91, 137);
    circle(1,2,483,128);
    glColor3ub(227, 91, 137);
    circle(1,2,457,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,463,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,464,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,478,106);
    glColor3ub(227, 91, 137);
    circle(1,3,483,119);
    glColor3ub(227, 91, 137);
    circle(1,3,473,103);


    glBegin(GL_TRIANGLE_FAN);  ///wood ........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(475,100);
    glVertex2f(470,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(472,100);
    glVertex2f(466,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(472,90);
    glVertex2f(476,90);
    glVertex2f(477,110);
    glVertex2f(480,140);
    glEnd();
///End 3rd small circle tree////////////////////////////////////////////////////////////


/// 2nd big tree leaf circle////////////////////////////////////////////////////////////

    glColor3ub(56, 183, 27);
    circle(8,22,500,150);
    glColor3ub(56, 183, 27);
    circle(8,22,510,170);
    glColor3ub(56, 183, 27);
    circle(8,22,513,140);
    glColor3ub(56, 183, 27);
    circle(7,25,522,150);
    glColor3ub(56, 183, 27);
    circle(8,22,530,150);
    glColor3ub(56, 183, 27);
    circle(10,40,500,250);

    glColor3ub(56, 183, 27);
    circle(9,22,530,295);
    glColor3ub(56, 183, 27);
    circle(8,15,530,293);

    glColor3ub(56, 183, 27);
    circle(9,22,545,285);
    glColor3ub(56, 183, 27);
    circle(9,22,545,280);
    glColor3ub(56, 183, 27);
    circle(8,15,545,275);

    glColor3ub(56, 183, 27);
    circle(9,22,555,235);
    glColor3ub(56, 183, 27);
    circle(9,32,550,255);

    glColor3ub(56, 183, 27);
    circle(9,22,559,225);
    glColor3ub(56, 183, 27);
    circle(9,22,556,255);
    glColor3ub(56, 183, 27);
    circle(9,22,563,195);
    glColor3ub(56, 183, 27);
    circle(9,22,550,180);
    glColor3ub(56, 183, 27);
    circle(9,22,558,165);
    glColor3ub(56, 183, 27);
    circle(9,22,549,150);
    glColor3ub(56, 183, 27);
    circle(9,22,538,140);


    glColor3ub(0, 77, 26);
    circle(10,20,555,190);
    glColor3ub(12, 165, 25);
    circle(9.5,19,555,190);


    glColor3ub(0, 77, 26);
    circle(10,20,555,205);
    glColor3ub(12, 165, 25);
    circle(9.5,20,555,205);


    glColor3ub(0, 77, 26);
    circle(10,20,550,218);
    glColor3ub(12, 165, 25);
    circle(9.5,20,550,218);


    glColor3ub(12, 165, 25);
    circle(10,20,527,130);


    glColor3ub(12, 165, 25);
    circle(35,70,520,200);
    glColor3ub(12, 165, 25);
    circle(15,30,530,255);


    glColor3ub(0, 77, 26);
    circle(10,20,542,225);
    glColor3ub(12, 165, 25);
    circle(9.5,20,542,224);


    glColor3ub(0, 77, 26);
    circle(10,20,530,225);
    glColor3ub(12, 165, 25);
    circle(10,20,530,224);


    glColor3ub(0, 77, 26);
    circle(10,18,542,263);
    glColor3ub(12, 165, 25);
    circle(10,18,542,262);


    glColor3ub(0, 77, 26);
    circle(10,20,530,180);
    glColor3ub(12, 165, 25);
    circle(10,20,530,179);

    glColor3ub(0, 77, 26);
    circle(10,20,520,180);
    glColor3ub(12, 165, 25);
    circle(10,20,520,179);

    glColor3ub(0, 77, 26);
    circle(10,20,540,155);
    glColor3ub(12, 165, 25);
    circle(10,20,540,156);


    glColor3ub(12, 165, 25);
    circle(9,22,520,280);
    glColor3ub(0, 77, 26);
    circle(9,21,520,270);
    glColor3ub(12, 165, 25);
    circle(9,21,520,269);


    glColor3ub(12, 165, 25);
    circle(9,22,510,255);
    glColor3ub(0, 77, 26);
    circle(9,20,510,245);
    glColor3ub(12, 165, 25);
    circle(9,20,510.5,244);


    glColor3ub(12, 165, 25);
    circle(9,22,485,245);
    glColor3ub(0, 77, 26);
    circle(9,20,485,235);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,234);


    glColor3ub(56, 183, 27);
    circle(9,22,485,205);
    glColor3ub(0, 77, 26);
    circle(9,20,485,195);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,194);


    glColor3ub(12, 165, 25);
    circle(9,22,509,288);
    glColor3ub(12, 165, 25);
    circle(9,20,485.5,164);
    glColor3ub(0, 77, 26);
    circle(9,20,495,165);
    glColor3ub(12, 165, 25);
    circle(9,20,495,164);


    ///2nd big........Tree........D-1........///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex2f(515,90);
    glVertex2f(522,90);
    glVertex2f(521,100);
    glVertex2f(520,110);
    glVertex2f(518,120);
    glVertex2f(516,130);
    glVertex2f(517,140);
    glVertex2f(518,145);
    glVertex2f(520,150);
    glVertex2f(522,150);
    glVertex2f(521,147);
    glVertex2f(520,145);
    glVertex2f(518,140);
    glVertex2f(516,130);
    glVertex2f(513,120);
    glVertex2f(516,130);
    glVertex2f(518,140);
    glVertex2f(520,145);
    glVertex2f(522,150);
    glVertex2f(522,160);
    glVertex2f(518,150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///........Tree........D-2.......///
    glColor3ub(575,35,5);
    glVertex2f(515,125);
    glVertex2f(519,130);
    glVertex2f(514,140);
    glVertex2f(514,150);
    glVertex2f(513,160);
    glVertex2f(510,170);
    glVertex2f(512,170);
    glVertex2f(512,160);
    glVertex2f(511,150);
    glVertex2f(511,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   /// tree...................D-3 p2  ///
    glColor3ub(575,35,5);
    glVertex2f(531,140);
    glVertex2f(529,140);
    glVertex2f(528,120);
    glVertex2f(525,120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  /// tree..................D-3 p1   ///
    glColor3ub(575,35,5);
    glVertex2f(516,100);
    glVertex2f(521,100);
    glVertex2f(524.5,120);
    glVertex2f(528,120);
    glEnd();

///end 2nd big tree//////////////////////////////////////////////////////


///....2nd small circle tree..... /////////////////////////////////////
    glColor3ub(27, 140, 3);
    circle(3,6,280,101);
    glColor3ub(27, 140, 3);
    circle(5,12,275,111);
    glColor3ub(27, 140, 3);
    circle(5,12,285,111);
    glColor3ub(27, 140, 3);
    circle(5,12,290,106);
    glColor3ub(27, 140, 3);
    circle(5,12,270,121);


    glColor3ub(26, 81, 14);
    circle(5,12,275,123);
    glColor3ub(26, 81, 14);
    circle(5,12,276,123);
    glColor3ub(26, 81, 14);
    circle(5,12,280,141);
    glColor3ub(26, 81, 14);
    circle(4,10,275,136);
    glColor3ub(26, 81, 14);
    circle(4,10,277,134);

    glColor3ub(26, 81, 14);
    circle(4,10,278,133);

    glColor3ub(26, 81, 14);
    circle(5,12,290,131);
    glColor3ub(26, 81, 14);
    circle(5,12,285,131);
    glColor3ub(26, 81, 14);
    circle(5,12,284,126);
    glColor3ub(26, 81, 14);
    circle(5,12,283,125);
    glColor3ub(26, 81, 14);
    circle(5,12,295,121);
    glColor3ub(26, 81, 14);
    circle(5,12,290,116);
    glColor3ub(26, 81, 14);
    circle(5,12,289,116);
    glColor3ub(26, 81, 14);
    circle(5,12,280,119);
    glColor3ub(26, 81, 14);
    circle(5,12,292,141);



    glColor3ub(227, 91, 137);         ///Fruite.
    circle(1,2,280,119);
    glColor3ub(227, 91, 137);
    circle(1,2,280,133);
    glColor3ub(227, 91, 137);
    circle(1,2,290,133);
    glColor3ub(227, 91, 137);
    circle(1,2,295,128);
    glColor3ub(227, 91, 137);
    circle(1,2,269,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,275,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,276,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,290,106);
    glColor3ub(227, 91, 137);
    circle(1,3,295,119);
    glColor3ub(227, 91, 137);
    circle(1,3,285,103);


    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(287,100);
    glVertex2f(282,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood........6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(284,100);
    glVertex2f(278,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood.......6   ///
    glColor3ub(75, 35, 5);
    glVertex2f(284,90);
    glVertex2f(288,90);
    glVertex2f(289,110);
    glVertex2f(292,140);
    glEnd();
///End  2nd smallL circle tree///


///1st tree leaf circle///////////////////////////////////////////

    glColor3ub(56, 183, 27);
    circle(8,22,0,150);
    glColor3ub(56, 183, 27);
    circle(8,22,10,170);
    glColor3ub(56, 183, 27);
    circle(8,22,13,140);
    glColor3ub(56, 183, 27);
    circle(7,25,22,150);
    glColor3ub(56, 183, 27);
    circle(8,22,30,150);
    glColor3ub(56, 183, 27);
    circle(10,40,0,250);

    glColor3ub(56, 183, 27);
    circle(9,22,30,295);
    glColor3ub(56, 183, 27);
    circle(8,15,30,293);

    glColor3ub(56, 183, 27);
    circle(9,22,45,285);
    glColor3ub(56, 183, 27);
    circle(9,22,45,280);
    glColor3ub(56, 183, 27);
    circle(8,15,45,275);

    glColor3ub(56, 183, 27);
    circle(9,22,55,235);
    glColor3ub(56, 183, 27);
    circle(9,32,50,255);

    glColor3ub(56, 183, 27);
    circle(9,22,59,225);
    glColor3ub(56, 183, 27);
    circle(9,22,56,255);
    glColor3ub(56, 183, 27);
    circle(9,22,63,195);
    glColor3ub(56, 183, 27);
    circle(9,22,50,180);
    glColor3ub(56, 183, 27);
    circle(9,22,58,165);
    glColor3ub(56, 183, 27);
    circle(9,22,49,150);
    glColor3ub(56, 183, 27);
    circle(9,22,38,140);


    glColor3ub(0, 77, 26);
    circle(10,20,55,190);
    glColor3ub(12, 165, 25);
    circle(9.5,19,55,190);


    glColor3ub(0, 77, 26);
    circle(10,20,55,205);
    glColor3ub(12, 165, 25);
    circle(9.5,20,55,205);


    glColor3ub(0, 77, 26);
    circle(10,20,50,218);
    glColor3ub(12, 165, 25);
    circle(9.5,20,50,218);


    glColor3ub(12, 165, 25);
    circle(10,20,27,130);


    glColor3ub(12, 165, 25);
    circle(35,70,20,200);
    glColor3ub(12, 165, 25);
    circle(15,30,30,255);


    glColor3ub(0, 77, 26);
    circle(10,20,42,225);
    glColor3ub(12, 165, 25);
    circle(9.5,20,42,224);


    glColor3ub(0, 77, 26);
    circle(10,20,30,225);
    glColor3ub(12, 165, 25);
    circle(10,20,30,224);


    glColor3ub(0, 77, 26);
    circle(10,18,42,263);
    glColor3ub(12, 165, 25);
    circle(10,18,42,262);


    glColor3ub(0, 77, 26);
    circle(10,20,30,180);
    glColor3ub(12, 165, 25);
    circle(10,20,30,179);

    glColor3ub(0, 77, 26);
    circle(10,20,20,180);
    glColor3ub(12, 165, 25);
    circle(10,20,20,179);

    glColor3ub(0, 77, 26);
    circle(10,20,40,155);
    glColor3ub(12, 165, 25);
    circle(10,20,40,156);


    glColor3ub(12, 165, 25);
    circle(9,22,20,280);
    glColor3ub(0, 77, 26);
    circle(9,21,20,270);
    glColor3ub(12, 165, 25);
    circle(9,21,20,269);


    glColor3ub(12, 165, 25);
    circle(9,22,10,255);
    glColor3ub(0, 77, 26);
    circle(9,20,10,245);
    glColor3ub(12, 165, 25);
    circle(9,20,10.5,244);


    ///1st........Tree........D-1........///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex2f(15,90);
    glVertex2f(22,90);
    glVertex2f(21,100);
    glVertex2f(20,110);
    glVertex2f(18,120);
    glVertex2f(16,130);
    glVertex2f(17,140);
    glVertex2f(18,145);
    glVertex2f(20,150);
    glVertex2f(22,150);
    glVertex2f(21,147);
    glVertex2f(20,145);
    glVertex2f(18,140);
    glVertex2f(16,130);
    glVertex2f(13,120);
    glVertex2f(16,130);
    glVertex2f(18,140);
    glVertex2f(20,145);
    glVertex2f(22,150);
    glVertex2f(22,160);
    glVertex2f(18,150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///1st........Tree........D-2.......///
    glColor3ub(75,35,5);
    glVertex2f(15,125);
    glVertex2f(19,130);
    glVertex2f(14,140);
    glVertex2f(14,150);
    glVertex2f(13,160);
    glVertex2f(10,170);
    glVertex2f(12,170);
    glVertex2f(12,160);
    glVertex2f(11,150);
    glVertex2f(11,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);   ///1st tree...................D-3 p2  ///
    glColor3ub(75,35,5);
    glVertex2f(31,140);
    glVertex2f(29,140);
    glVertex2f(28,120);
    glVertex2f(25,120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///1st tree..................D-3 p1   ///
    glColor3ub(75,35,5);
    glVertex2f(16,100);
    glVertex2f(21,100);
    glVertex2f(24.5,120);
    glVertex2f(28,120);
    glEnd();
///End !st small tree////////////////////////////////////////////////////////////////

///5th small tree////////////////////////////////////////////////////////////////////
    glColor3ub(0, 153, 51);
    circle(3,6,575,100);
    glColor3ub(0, 153, 51);
    circle(5,12,570,110);
    glColor3ub(0, 153, 51);
    circle(5,12,580,110);
    glColor3ub(0, 153, 51);
    circle(5,12,585,105);
    glColor3ub(0, 153, 51);
    circle(5,12,565,120);


    glColor3ub(0, 102, 00);
    circle(5,12,570,122);
    glColor3ub(0, 153, 51);
    circle(5,12,571,122);
    glColor3ub(0, 153, 51);
    circle(5,12,575,140);
    glColor3ub(0, 153, 51);
    circle(4,10,570,135);
    glColor3ub(0, 102, 0);
    circle(4,10,572,133);

    glColor3ub(0, 153, 51);
    circle(4,10,573,132);

    glColor3ub(0, 153, 51);
    circle(5,12,585,130);
    glColor3ub(0, 153, 51);
    circle(5,12,580,130);
    glColor3ub(0, 102, 0);
    circle(5,12,579,125);
    glColor3ub(0, 153, 51);
    circle(5,12,578,124);
    glColor3ub(0, 153, 51);
    circle(5,12,590,120);
    glColor3ub(0, 102, 0);
    circle(5,12,585,115);
    glColor3ub(0, 153, 51);
    circle(5,12,584,115);
    glColor3ub(0, 153, 51);
    circle(5,12,575,118);
    glColor3ub(0, 153, 51);
    circle(5,12,587,140);



    glColor3ub(255, 255, 255);         ///5th..........tree fruite.
    circle(1,2,575,118);
    glColor3ub(255, 255, 255);
    circle(1,2,575,138);
    glColor3ub(255, 255, 255);
    circle(1,2,585,138);
    glColor3ub(255, 255, 255);
    circle(1,2,580,127);
    glColor3ub(255, 255, 255);
    circle(1,2,564,118);
    glColor3ub(255, 255, 255);
    circle(1,2.5,570,133);
    glColor3ub(255, 255, 255);
    circle(1,1.5,571,109);
    glColor3ub(255, 255, 255);
    circle(1,2.5,585,105);
    glColor3ub(255, 255, 255);
    circle(1,3,590,118);
    glColor3ub(255, 255, 255);
    circle(1,3,585,120);


    glBegin(GL_TRIANGLE_FAN);  ///5th tree.........wood  ///
    glColor3ub(75,35,5);
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(582,100);
    glVertex2f(577,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  ///wood  ///
    glColor3ub(75,35,5);
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(579,100);
    glVertex2f(573,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///wood   ///
    glColor3ub(75,35,5);
    glVertex2f(579,90);
    glVertex2f(583,90);
    glVertex2f(584,110);
    glVertex2f(587,140);
    glEnd();

///End 5th small tree///////////////////////////////////////////////////////

///waiting room/////////////////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3ub(196, 66, 145);
    glVertex2f(375,110);  //body..........
    glVertex2f(410,110);
    glVertex2f(410,155);
    glVertex2f(375,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(171, 29, 140);
    glVertex2f(370,160);  //roof..........
    glVertex2f(415,160);
    glVertex2f(410,168);
    glVertex2f(375,168);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(374,105);  //left stip..........
    glVertex2f(376,105);
    glVertex2f(376,160);
    glVertex2f(374,160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(391,105);  //middle stip..........
    glVertex2f(393,105);
    glVertex2f(393,160);
    glVertex2f(391,160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(379,115);  //sit stip..........
    glVertex2f(388,115);
    glVertex2f(388,118);
    glVertex2f(379,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(379,105);  //sit left stip..........
    glVertex2f(380,105);
    glVertex2f(380,118);
    glVertex2f(379,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(387,105);  //sit stip..........
    glVertex2f(388,105);
    glVertex2f(388,118);
    glVertex2f(387,118);
    glEnd();


glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(409,105);  //right stip..........
    glVertex2f(411,105);
    glVertex2f(411,160);
    glVertex2f(409,160);
    glEnd();

    //chair

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(330,105);  //left stip..........
    glVertex2f(332,105);
    glVertex2f(332,140);
    glVertex2f(330,140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(97, 19, 101);
    glVertex2f(351,105);  //right stip..........
    glVertex2f(353,105);
    glVertex2f(353,140);
    glVertex2f(351,140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(320,115);  //sit stip..........
    glVertex2f(361,115);
    glVertex2f(361,118);
    glVertex2f(320,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,123);  //back stip..........
    glVertex2f(358,123);
    glVertex2f(358,126);
    glVertex2f(323,126);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,128);  //back stip..........
    glVertex2f(358,128);
    glVertex2f(358,131);
    glVertex2f(323,131);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(194, 75, 48);
    glVertex2f(323,133);  //back stip..........
    glVertex2f(358,133);
    glVertex2f(358,136);
    glVertex2f(323,136);
    glEnd();

///Sky----------------------------------------------------------------------SKY-----------------------------------------------------

    glColor3ub(253, 183, 77);    ///.........S U N.....................////////////////////////
    circle(18,36,400,705);
    glColor3ub(253, 183, 77);
    circle(16.5,33,400,705);
    glColor3ub(253, 183, 77);
    circle(14.5,30,400,705);
    glColor3ub(253, 183, 77);
    circle(12.5,27,400,705);


    glColor3ub(232,241,255);        ///....Megh.......1 covering sun..../////////////////////////
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

    glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);


    glColor3ub(232,241,255);        ///....Megh.......2.....///////////////////////////////////////////////////
    circle(13,20,p+200,745);
    glColor3ub(252,254,255);
    circle(11,18,p+200,745);

    glColor3ub(232,241,255);
    circle(10,20,p+210,755);
    glColor3ub(252,254,255);
    circle(10,20,p+212,762);

    glColor3ub(232,241,255);
    circle(13,20,p+210,735);

    glColor3ub(221,229,247);
    circle(9,20,p+220,750);
    glColor3ub(252,254,255);
    circle(8,18,p+220,759);

    glColor3ub(232,241,255);
    circle(9,20,p+220,756);
    glColor3ub(252,254,255);
    circle(8,18,p+220,752);

    glColor3ub(232,241,255);
    circle(9,20,p+230,765);
    glColor3ub(252,254,255);
    circle(8,18,p+230,761);

    glColor3ub(232,241,255);
    circle(9,20,p+225,745);
    glColor3ub(252,254,255);
    circle(8,18,p+235,747);

    glColor3ub(232,241,255);
    circle(9,20,p+240,755);

    glColor3ub(221,229,247);
    circle(8,18,p+243,745);
    glColor3ub(252,254,255);
    circle(8,18,p+240,743);
    glColor3ub(173,197,224);
    circle(8,18,p+230,733);
    glColor3ub(252,254,255);
    circle(8,18,p+230,738);
    glColor3ub(173,197,224);
    circle(8,18,p+220,723);
    glColor3ub(252,254,255);
    circle(8,18,p+220,728);



    glColor3ub(252,254,255);
    circle(23,9,p+245,744);
    glColor3ub(173,197,224);
    circle(21,10,p+240,720);
    glColor3ub(252,254,255);
    circle(21,11,p+238,723);


    glColor3ub(252,254,255);
    circle(18,18,p+210,744);
    glColor3ub(252,254,255);
    circle(18,25,p+220,745);

    glColor3ub(173,197,224);
    circle(10,20,p+235,715);
    glColor3ub(252,254,255);
    circle(10,20,p+235,719);



    glColor3ub(173,197,224);        ///....Megh.......3.....//////////////////////////////////////
    circle(9,15,p+20,685);
    glColor3ub(252,254,255);
    circle(6,14,p+21,685);

    glColor3ub(232,241,255);
    circle(7,16,p+30,695);
    glColor3ub(252,254,255);
    circle(7,14,p+32,692);

    glColor3ub(252,254,255);
    circle(12,16,p+28,680);

    glColor3ub(221,229,247);
    circle(10,15,p+45,690);
    glColor3ub(252,254,255);
    circle(9,13,p+43,685);
    glColor3ub(252,254,255);
    circle(15,18,p+48,670);

    glColor3ub(173,197,224);
    circle(6,14,p+30,680);
    glColor3ub(252,254,255);
    circle(6,13,p+30,677);

    glColor3ub(173,197,224);
    circle(6,14,p+38,668);
    glColor3ub(252,254,255);
    circle(6,13,p+36,667);


    glColor3ub(252,254,255);
    circle(11,15,p+29,668);

     ///....Megh.......4.....///////////////////////////////////////////////////////

    glColor3ub(173,197,224);
    circle(9,15,590,695);
    glColor3ub(252,254,255);
    circle(6,14,591,695);

    glColor3ub(232,241,255);
    circle(7,16,600,705);
    glColor3ub(252,254,255);
    circle(7,14,602,702);

    glColor3ub(252,254,255);
    circle(12,16,598,690);

    glColor3ub(221,229,247);
    circle(10,15,615,700);
    glColor3ub(252,254,255);
    circle(9,13,613,695);
    glColor3ub(252,254,255);
    circle(15,18,618,680);

    glColor3ub(173,197,224);
    circle(6,14,600,690);
    glColor3ub(252,254,255);
    circle(6,13,600,687);

    glColor3ub(173,197,224);
    circle(6,14,608,678);
    glColor3ub(252,254,255);
    circle(6,13,606,677);


    glColor3ub(252,254,255);
    circle(11,15,599,678);



    if(p<= 800)
        p = p + 0.1;
    else
        p = -10;



///-------------------------------------------------------------------------------------------------------------------------------------------------



// Draw blue targets as helicopters
for (const auto& target : blueTargets) {
    if (!target.isHit) {
        draw_helicopter(target.x - 375, target.y - 600); // Adjust offsets if needed
    }
}

for (const auto& target : ambulanceTargets) {
        if (!target.isHit) {
            drawAmbulance(target.x - 50, target.y - 50);
        }
    }

    // Draw bus targets
    for (const auto& target : busTargets) {
        if (!target.isHit) {
            drawBus(target.x - 50, target.y - 50);
        }
    }

    for (const auto& target : carTargets) {
        if (!target.isHit) {
            drawCar(target.x - 50, target.y - 50);
        }
    }



    // Draw crosshair
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(crosshairX - 10, crosshairY);
    glVertex2f(crosshairX + 10, crosshairY);
    glVertex2f(crosshairX, crosshairY - 20);
    glVertex2f(crosshairX, crosshairY + 20);
    glEnd();


    // Display score and level
glColor3f(0.0f, 0.0f, 0.0f);
glRasterPos2f(20.0f, 770.0f); // Position near the top-left corner
string hud = "Score: " + to_string(score) + " Level: " + "2" + " High Score: " + to_string(highScore);
for (char c : hud) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// Display game over message if needed
if (gameOver) {
handleGameOver();
glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(250.0f, 400.0f); // Centered horizontally, middle of the screen
    string message = "Game Over! Press R to Restart";
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


    glutSwapBuffers();
}

void displayLevel3() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

    // Draw Level 3 text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(200, 600, "Welcome to Level 3");
    drawText(200, 500, "Press 'm' to return to the main menu");

    glutSwapBuffers();
}

void displayOptions() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    // Draw Options text
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(200, 600, "Options Menu");
    drawText(200, 500, "Press 'm' to return to the main menu");

    glutSwapBuffers();
}

// Display callback
void displaymenu() {
    switch (currentGameState) {
        case MAIN_MENU:
            displayMainMenu();
            break;
        case LEVEL_1:
            displayLevel1();
            break;
        case LEVEL_2:
            displayLevel2();
            break;
        case LEVEL_3:
            displayLevel3();
            break;
        case OPTIONS:
            sndPlaySound(NULL, SND_ASYNC);
            break;
    }
}

bool isSoundPlaying = true;
// Keyboard callback
void keyboardm(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            currentGameState = LEVEL_1;
            break;
        case '2':
            currentGameState = LEVEL_2;
            break;
        case '3':
            currentGameState = LEVEL_3;
            break;
        case '4':
            if (isSoundPlaying) {
                sndPlaySound(NULL, SND_ASYNC);
                isSoundPlaying = false;
            }
            //break;

            else if (!isSoundPlaying) {
                sndPlaySound("PUBG.wav", SND_ASYNC);
                isSoundPlaying = true;
            }
            break;

        case 'm':
            currentGameState = MAIN_MENU;
            break;
        case 'r':
            initGame();
            break;
        case 27: // ESC key
            exit(0);
            break;
    }
    glutPostRedisplay();
}


// Timer callback
void update(int value) {
    if (!gameOver) {
        for (auto& target : blueTargets) {
    if (!target.isHit) {
        target.x += target.dx; // Blue targets move down
        if (target.x < -50) target.x = 800.0f; // Reset to top if it goes out of view
    }

}

for (auto& target : busTargets) {
    if (!target.isHit) {
        target.x += target.dx; // Bus targets move up
        if (target.x > 800) target.x = 0.0f; // Reset to bottom if it goes out of view
    }
}

for (auto& target : carTargets) {
    if (!target.isHit) {
        target.x += target.dx; // car targets move up
        if (target.x > 800) target.x = 0.0f; // Reset to bottom if it goes out of view
    }
}

for (auto& target : ambulanceTargets) {
    if (!target.isHit) {
        target.x += target.dx; // car targets move up
        if (target.x <-50) target.x = 800.0f; // Reset to bottom if it goes out of view
    }
}
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}


// Mouse callback
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !gameOver) {
        float normX = x * (700.0f / 1450.0f);
        float normY = 800.0f - (y * (800.0f / 750.0f));

        for (auto& target : blueTargets) {
            if (!target.isHit &&
                normX >= target.x - 40 && normX <= target.x + 40 &&
                normY >= target.y - 40 && normY <= target.y + 40) {
                target.isHit = true;
                score += 50;
            }
        }

        for (auto& target : busTargets) {
            if (!target.isHit &&
                normX >= target.x - 50 && normX <= target.x + 50 &&
                normY >= target.y - 50 && normY <= target.y + 50) {
                target.isHit = true;
                score += 20;
            }
        }

        for (auto& target : carTargets) {
            if (!target.isHit &&
                normX >= target.x - 30 && normX <= target.x + 30 &&
                normY >= target.y - 30 && normY <= target.y + 30) {
                target.isHit = true;
                score -= 20;
            }
        }

        for (auto& target : ambulanceTargets) {
            if (!target.isHit &&
                normX >= target.x - 50 && normX <= target.x + 50 &&
                normY >= target.y - 50 && normY <= target.y + 50) {
                target.isHit = true;
                gameOver=true;

            }
        }

        // Check if all targets are hit
        bool allHit = true;
        for (const auto& target : busTargets) {
            if (!target.isHit) {
                allHit = false;
                break;
            }
        }
        // Regenerate bus targets if all are hit
        if (allHit) {
            busTargets.clear();
            int busCount = 3; // Or adjust based on level or difficulty
            for (int i = 0; i < busCount; ++i) {
                Target t = {randomFloat(-150.0f, -650.0f), 50.0f, randomFloat(0.7f, 1.5f), false};
                busTargets.push_back(t);
            }
        }


        // Check if all targets are hit
        bool allHit_car = true;
        for (const auto& target : carTargets) {
            if (!target.isHit) {
                allHit_car = false;
                break;
            }
        }
        // Regenerate bus targets if all are hit
        if (allHit_car) {
            carTargets.clear();
            int carCount = 3; // Or adjust based on level or difficulty
            for (int i = 0; i < carCount; ++i) {
                Target t = {randomFloat(-150.0f, -650.0f), 50.0f, randomFloat(0.7f, 1.5f), false};
                carTargets.push_back(t);
            }
        }


        bool allHit_helocopter = true;
        for (const auto& target : blueTargets) {
            if (!target.isHit) {
                allHit_helocopter = false;
                break;
            }
        }

         // Regenerate blue targets if all are hit (optional)
        if (allHit_helocopter) {
            blueTargets.clear();
            int blueCount = 2; // Or adjust based on level or difficulty
            for (int i = 0; i < blueCount; ++i) {
                Target t = {randomFloat(800.0f, 650.0f), 600.0f, randomFloat(-2.0f, -1.0f), false};
                blueTargets.push_back(t);
            }
        }


        if (allHit==true && allHit_helocopter==true) {
            if (level < 1) {
                //++level;
                initGame();
            } else {
                gameOver = true;
            }
        }



    }
}

void motion(int x, int y) {
    // Map x and y from window size (1450, 750) to orthographic size (700, 800)
    crosshairX = (float)x * (700.0f / 1450.0f);           // Scale x to fit orthographic width
    crosshairY = 800.0f - (float)y * (800.0f / 750.0f);   // Scale y to fit orthographic height and flip vertically
    glutPostRedisplay();
}


// Initialization
void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Bus and Blue Targets");

    initOpenGL();
    initGame();

    glutDisplayFunc(displaymenu);
    glutKeyboardFunc(keyboardm);
   // glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    glutTimerFunc(16, update, 0);
sndPlaySound("PUBG.wav", SND_ASYNC);
    glutMainLoop();
    return 0;
}

///,//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

