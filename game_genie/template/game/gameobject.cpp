
enum go_type {cube, sphere};


class Vector3
{
  public:
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0)
    {
      this->x = x;
      this->y = y;
      this->z = z;
    }

};


class Transform 
{
  public:
    char* name[255];

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    
    Transform()
    {
      this->position = Vector3();
      this->rotation = Vector3();
      this->scale = Vector3(1, 1, 1);
    }

};



class GameObject
{
  public:
    Transform transform;

    GameObject(go_type type=cube, const char* name="cube", Transform transform = Transform())
    {

    }
    void display()
    {
      glPushMatrix();
      glTranslatef(transform.position.x, transform.position.y, transform.position.z);
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
};
