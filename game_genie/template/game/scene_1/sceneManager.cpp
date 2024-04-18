/**********************************

  H O W  T O  R E A D  T H I S  P R O G R A M ?
  
  Start from the function "main" and follow the 
  instruction flow, paying attention to the fact that
  this program belongs to the event-driven programming
  paradigm. So pay attention to what happens when 
  the user presses a key, moves the mouse or presses a
  mouse button. There are also some special events: the
  redrawing of the application window, etc.
  Identify what happens in the program when one of these
  events occurs.

  **********************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <GL/glut.h>
#include <GL/freeglut.h>

#include <cmath>

#include "goManager.cpp"

// dimensiunea ferestrei in pixeli
#define dim 300

unsigned char prevKey;

void drawAxis() {
  int length = 200;

  glLineWidth(2);

  // axa Ox - verde
  glColor3f(0, 1, 0);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(length,0,0);
  glEnd();

  // axa Oy - albastru
  glColor3f(0, 0, 1);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(0,length,0);
  glEnd();

  // axa Oz - rosu
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(0,0,length);
  glEnd();

  glLineWidth(1);

}

// // cub wireframe
// void Display1() {
//    glColor3f(1,0,0);
//    glutWireCube(1);
// }
//
// // cub solid
// void Display2() {
//    glColor3f(1,0,0);
//    glutSolidCube(1);
// }
//
// // sfera wireframe
// void Display3() {
//    glColor3f(0,0,1);
//    glutWireSphere(1, 10, 10);
// }
//
// // sfera solida
// void Display4() {
//    glColor3f(0,0,1);
//    glutSolidSphere(1, 10, 10);
// }
//
// void DisplayObiect()
// {
//   switch (ob)
//   {
//   case cubw:
//     Display1();
//     break;
//   case cubs:
//     Display2();
//     break;
//   case sferaw:
//     Display3();
//     break;
//   case sferas:
//     Display4();
//     break;
//   default:
//     break;
//   }
// }
//
// // rotatia cu un unghi de 10 grade in raport cu axa x
// void DisplayX() {
//   glMatrixMode(GL_MODELVIEW);
//   glRotated(10,1,0,0);
// }
//
// // rotatia cu un unghi de 10 grade in raport cu axa y
// void DisplayY() {
//   glMatrixMode(GL_MODELVIEW);
//   glRotated(10,0,1,0);
// }
//
// // rotatia cu un unghi de 10 grade in raport cu axa z
// void DisplayZ() {
//   glMatrixMode(GL_MODELVIEW);
//   glRotated(10,0,0,1);
// }
//
// // Translatia cu 0.2, 0.2, 0.2
// void DisplayT() {
//   glMatrixMode(GL_MODELVIEW);
//   glTranslatef(0.2, 0.2, 0.2);
// }
//
// // Scalarea cu 1.2, 1.2, 1.2
// void DisplayS() {
//   glMatrixMode(GL_MODELVIEW);
//   glScalef(1.2, 1.2, 1.2);
// }

void Init(void) {
  glClearColor(1, 1, 1, 1);
  glLineWidth(2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10, 10, -10, 10, 30, -30);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotated(20, 1, 0, 0);
  glRotated(-20, 0, 1, 0);
}

/*
 *
v 0.0 0.0 0.0  # 1 a
v 0.0 1.0 0.0  # 2 b
v 1.0 1.0 0.0  # 3 c
v 1.0 0.0 0.0  # 4 d

v 0.0 0.0 1.0  # 5 e
v 0.0 1.0 1.0  # 6 f
v 1.0 1.0 1.0  # 7 g
v 1.0 0.0 1.0  # 8 h
 */

void renderCube(int x, int y, int z)
{

  glPushMatrix();
  glTranslatef(x, y, z);
  // glRotated(x * 90,0,0,0);
  glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);

    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
  glEnd();
  glPopMatrix();
}

void Display(void) {

  // drawAxis();
  // // for every gameobject:
  // for (int i=0; i <= 1; i++)
  // {
  //   renderCube(0,0,0);
  //   renderCube(1,1,1);
  //   renderCube(2,2,2);
  //   renderCube(3,3,3);
  //   renderCube(9,9,9);
  // }


  // render(0);
  glCallList(loadObj("go_0/mesh.obj"));

  // switch(prevKey) 
  // {
  // // case 'a':
  // //   DisplayAxe();
  // //   break;
  // case '0':
  //   glClear(GL_COLOR_BUFFER_BIT);
  //   glMatrixMode(GL_MODELVIEW);
  //   glLoadIdentity();
  //   glRotated(20, 1, 0, 0);
  //   glRotated(-20, 0, 1, 0);
  //   break;
  // case '1':
  //   Display1();
  //   ob = cubw;
  //   break;
  // case '2':
  //   Display2();
  //   ob = cubs;
  //   break;
  // case '3':
  //   Display3();
  //   ob = sferaw;
  //   break;
  // case '4':
  //   Display4();
  //   ob = sferas;
  //   break;
  // case 'x':
  //   // glClear(GL_COLOR_BUFFER_BIT);
  //   DisplayX();
  //   DisplayAxe();
  //   // DisplayObiect();
  //   break;
  // case 'y':
  //   glClear(GL_COLOR_BUFFER_BIT);
  //   DisplayY();
  //   DisplayAxe();
  //   DisplayObiect();
  //   break;
  // case 'z':
  //   glClear(GL_COLOR_BUFFER_BIT);
  //   DisplayZ();
  //   DisplayAxe();
  //   DisplayObiect();
  //   break;
  // case 't':
  //   glClear(GL_COLOR_BUFFER_BIT);
  //   DisplayT();
  //   DisplayAxe();
  //   DisplayObiect();
  //   break;
  // case 's':
  //   glClear(GL_COLOR_BUFFER_BIT);
  //   DisplayS();
  //   DisplayAxe();
  //   DisplayObiect();
  //   break;
  // default:
  //   break;
  // }
  glutSwapBuffers();
}

void Reshape(int w, int h) {
   // functia void glViewport (GLint x, GLint y,
   //                          GLsizei width, GLsizei height)
   // defineste poarta de afisare : acea suprafata dreptunghiulara
   // din fereastra de afisare folosita pentru vizualizare.
   // x, y sunt coordonatele pct. din stg. jos iar 
   // width si height sunt latimea si inaltimea in pixeli.
   // In cazul de mai jos poarta de afisare si fereastra coincid
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
  printf("Ati tastat <%c>. Mouse-ul este in pozitia %d, %d.\n", key, x, y);
  prevKey = key;
  if (key == 27) // escape
    exit(0);
  glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
     printf("Call MouseFunc : ati %s butonul %s in pozitia %d %d\n",
      (state == GLUT_DOWN) ? "apasat" : "eliberat",
      (button == GLUT_LEFT_BUTTON) ? 
      "stang" : 
      ((button == GLUT_RIGHT_BUTTON) ? "drept": "mijlociu"),
      x, y);
}
void loop(){
  glClear(GL_COLOR_BUFFER_BIT);
  Display();
}

int main(int argc, char** argv) {
  // Initializarea bibliotecii GLUT. Argumentele argc
   // si argv sunt argumentele din linia de comanda si nu 
   // trebuie modificate inainte de apelul functiei 
   // void glutInit(int *argcp, char **argv)
   // Se recomanda ca apelul oricarei functii din biblioteca
   // GLUT sa se faca dupa apelul acestei functii.
   glutInit(&argc, argv);
   
   // Argumentele functiei
   // void glutInitWindowSize (int latime, int latime)
   // reprezinta latimea, respectiv inaltimea ferestrei
   // exprimate in pixeli. Valorile predefinite sunt 300, 300.
   glutInitWindowSize(300, 300);

   // Argumentele functiei
   // void glutInitWindowPosition (int x, int y)
   // reprezinta coordonatele varfului din stanga sus
   // al ferestrei, exprimate in pixeli. 
   // Valorile predefinite sunt -1, -1.
   glutInitWindowPosition(100, 100);

   // Functia void glutInitDisplayMode (unsigned int mode)
   // seteaza modul initial de afisare. Acesta se obtine
   // printr-un SAU pe biti intre diverse masti de display
   // (constante ale bibliotecii GLUT) :
   // 1. GLUT_SINGLE : un singur buffer de imagine. Reprezinta
   //    optiunea implicita ptr. nr. de buffere de
   //    de imagine.
   // 2. GLUT_DOUBLE : 2 buffere de imagine.
   // 3. GLUT_RGB sau GLUT_RGBA : culorile vor fi afisate in
   //    modul RGB.
   // 4. GLUT_INDEX : modul indexat de selectare al culorii.
   // etc. (vezi specificatia bibliotecii GLUT)
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   // Functia int glutCreateWindow (char *name)
   // creeaza o fereastra cu denumirea data de argumentul
   // name si intoarce un identificator de fereastra.
   glutCreateWindow (argv[0]);

   Init();

   // Functii callback : functii definite in program si 
   // inregistrate in sistem prin intermediul unor functii
   // GLUT. Ele sunt apelate de catre sistemul de operare
   // in functie de evenimentul aparut

   // Functia 
   // void glutReshapeFunc (void (*Reshape)(int width, int height))
   // inregistreaza functia callback Reshape care este apelata
   // oridecate ori fereastra de afisare isi modifica forma.
   glutReshapeFunc(Reshape);
   
   // Functia 
   // void glutKeyboardFunc (void (*KeyboardFunc)(unsigned char,int,int))
   // inregistreaza functia callback KeyboardFunc care este apelata
   // la actionarea unei taste.
   glutKeyboardFunc(KeyboardFunc);
   
   // Functia 
   // void glutMouseFunc (void (*MouseFunc)(int,int,int,int))
   // inregistreaza functia callback MouseFunc care este apelata
   // la apasarea sau la eliberarea unui buton al mouse-ului.
   glutMouseFunc(MouseFunc);

   // Functia 
   // void glutDisplayFunc (void (*Display)(void))
   // inregistreaza functia callback Display care este apelata
   // oridecate ori este necesara desenarea ferestrei: la 
   // initializare, la modificarea dimensiunilor ferestrei
   // sau la apelul functiei
   // void glutPostRedisplay (void).
   glutDisplayFunc(Display);

   // Functia void glutMainLoop() lanseaza bucla de procesare
   // a evenimentelor GLUT. Din bucla se poate iesi doar prin
   // inchiderea ferestrei aplicatiei. Aceasta functie trebuie
   // apelata cel mult o singura data in program. Functiile
   // callback trebuie inregistrate inainte de apelul acestei
   // functii.
   // Cand coada de evenimente este vida atunci este executata
   // functia callback IdleFunc inregistrata prin apelul functiei
   // void glutIdleFunc (void (*IdleFunc) (void))
   glutIdleFunc(Display);
   glutMainLoop();
   return 0;
}
