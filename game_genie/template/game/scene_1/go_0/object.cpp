
void loadCube()
{

}

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
