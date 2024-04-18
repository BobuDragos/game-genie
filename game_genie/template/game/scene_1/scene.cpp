#include <stdio.h>


#include "go_0/object.cpp"





void Display(void){
  renderCube(0,0,0);
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



/*
 *
 * HID devices
 *
 */


unsigned char prevKey;

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

