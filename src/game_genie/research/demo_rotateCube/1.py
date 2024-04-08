from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from OpenGL import *

from PyQt6.QtOpenGL import *
from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import *
from PyQt6.QtOpenGLWidgets import (
    QOpenGLWidget,
)




import sys,time
class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()

        self.widget = glWidget(self)
        # mainLayout = QVBoxLayout()
        # mainLayout.addWidget(self.widget)
        # self.setLayout(mainLayout)

class glWidget(QOpenGLWidget):

    def __init__(self):
        QOpenGLWidget.__init__(self)

        #self.setMinimumSize(400, 400)

        self.verticies = (
            (1,-1,-1),
            (1,1,-1),
            (-1,1,-1),
            (-1,-1,-1),
            (1,-1,1),
            (1,1,1),
            (-1,-1,1),
            (-1,1,1))
        self.edges = (
            (0,1),
            (0,3),
            (0,4),
            (2,1),
            (2,3),
            (2,7),
            (6,3),
            (6,4),
            (6,7),
            (5,1),
            (5,4),
            (5,7))

    def paintGL(self):
        while True:
            #glRotatef(1,3,1,1)
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
            glBegin(GL_LINE)
            for self.edge in self.edges:
                for self.vertex in self.edge:
                    glVertex3fv(self.verticies[self.vertex])
            glEnd()
            glFlush()
            time.sleep(1)       

    def resizeGL(self, w, h):
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        glOrtho(-50, 50, -50, 50, -50.0, 50.0)
        glViewport(0, 0, w, h)

    def initializeGL(self):

        #glClearColor(0.0, 0.0, 0.0, 1.0)
        # gluPerspective(45,800/600,0.1,50.0)
        glTranslatef(0.0,0.0,-5)
        glRotatef(0,0,0,0)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = glWidget()
    window.show()
    app.exec_()
