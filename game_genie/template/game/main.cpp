#include "game.cpp"


int main(int argc, char** argv)
{
  // Initializarea bibliotecii GLUT. 
  // !! apelul oricarei functii din biblioteca GLUT sa se faca dupa void glutInit(int *argcp, char **argv)
  glutInit(&argc, argv);

  Game myGame = Game();
  Scene sampleScene = Scene();
  myGame.addScene(sampleScene);
  myGame.renderScene(sampleScene);
}
