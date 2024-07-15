#include <stdio.h>

#include <GL/glut.h>
#include <GL/freeglut.h>

#include "gameobject.cpp"


class Scene
{
  private:
    GameObject gameobjects[255];
  public:
    int idx;
    Scene()
    {
      glClearColor(1, 1, 1, 1);
      glLineWidth(2);

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-10, 10, -10, 10, 30, -30);

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glRotated(20, 1, 0, 0);
      glRotated(-20, 0, 1, 0);
      printf("test");

      gameobjects[idx++] = GameObject();

    }
    
    void test()
    {
      printf("test");
    }

    void update()
    {
      for (int i = 0; i < go_count; i++)
      {
        gameobjects[i].display();
      }
      glutSwapBuffers();
    }


};
