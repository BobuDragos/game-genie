import sys
import math

from PyQt6.QtCore import (
    Qt,
)
from PyQt6.QtWidgets import (
    QApplication,
    QMainWindow,
    QLabel,
    QSplitter,
    QVBoxLayout,
    QLineEdit,
    QPushButton,
)
from PyQt6.QtOpenGLWidgets import (
    QOpenGLWidget,
)

import OpenGL
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class OpenGLWidget(QOpenGLWidget):
    def __init__(self, parent=None):
        super(OpenGLWidget, self).__init__(parent)
        # self.initUI()
        glutInit()

        glClearColor(0.0, 0.0, 0.0, 0.0)
        glShadeModel(GL_FLAT)

        glutDisplayFunc(self.display)
        glutMainLoop()

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT)
        glColor3f(1.0, 1.0, 1.0)
        glLoadIdentity()

        gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0)
        glScalef(1.0, 2.0, 1.0)
        glutWireCube(1.0)
        glFlush()
