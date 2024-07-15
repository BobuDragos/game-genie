#include <stdio.h>

#include <GL/glut.h>
#include <GL/freeglut.h>

#include "scene.cpp"

int activeScene_idx = 0;

unsigned char prevKey;

void Reshape(int w, int h) 
{
   // functia void glViewport (GLint x, GLint y,
   //                          GLsizei width, GLsizei height)
   // defineste poarta de afisare : acea suprafata dreptunghiulara
   // din fereastra de afisare folosita pentru vizualizare.
   // x, y sunt coordonatele pct. din stg. jos iar 
   // width si height sunt latimea si inaltimea in pixeli.
   // In cazul de mai jos poarta de afisare si fereastra coincid
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void KeyboardFunc(unsigned char key, int x, int y) 
{
  printf("Ati tastat <%c>. Mouse-ul este in pozitia %d, %d.\n", key, x, y);
  prevKey = key;
  if (key == 27) // escape
    exit(0);
  glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) 
{
   printf("Call MouseFunc : ati %s butonul %s in pozitia %d %d\n", (state == GLUT_DOWN) ? "apasat" : "eliberat",(button == GLUT_LEFT_BUTTON) ? "stang" : ((button == GLUT_RIGHT_BUTTON) ? "drept": "mijlociu"), x, y);
}


void Display()
{
  Game.updateScene(activeScene_idx);
}




class Game
{
  Scene scenes[255];
  int sceneCount = 0;
  char name[255];
  public:
    Game()
    {
      Game("New Game", 1000, 1000);
    }
    Game(char* name, int width, int height)
    {
     // // Initializarea bibliotecii GLUT. 
     // // !! apelul oricarei functii din biblioteca GLUT sa se faca dupa void glutInit(int *argcp, char **argv)
     // glutInit(0,0); 
      
     // size of window in pixels
     glutInitWindowSize(width, height);

     // the coordinates of the upper-left window corner [(-1 -1) = default]
     glutInitWindowPosition(0, 0);

     // Functia void glutInitDisplayMode (unsigned int mode) seteaza modul initial de afisare. Acesta se obtine printr-un SAU pe biti intre diverse masti de display
     // (constante ale bibliotecii GLUT) :
     // 1. GLUT_SINGLE : un singur buffer de imagine. Reprezinta optiunea implicita ptr. nr. de buffere de de imagine.
     // 2. GLUT_DOUBLE : 2 buffere de imagine.
     // 3. GLUT_RGB sau GLUT_RGBA : culorile vor fi afisate in modul RGB.
     // 4. GLUT_INDEX : modul indexat de selectare al culorii.
     // ... (and more)
     glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);

     // Functia int glutCreateWindow (char *name) creeaza o fereastra cu denumirea data de argumentul name si intoarce un identificator de fereastra.
     glutCreateWindow (name);


     // Scene activeScene = scenes[idx];
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
     // glutIdleFunc(Display);
     glutMainLoop();
    }

    int addScene(Scene newScene)
    {
      newScene.idx = sceneCount;
      scenes[sceneCount++] = newScene;
      return sceneCount-1;
    }

    void renderScene(Scene newActiveScene)
    {
      activeScene_idx = newActiveScene.idx;
    }

    static void update(int sceneidx)
    {
      scenes[sceneidx].update();
    }
};

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

