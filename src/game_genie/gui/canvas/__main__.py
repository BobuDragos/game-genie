
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


from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

class OpenGLWidget(QOpenGLWidget):
    def __init__(self, parent=None):
        super(OpenGLWidget, self).__init__(parent)
        self.initUI()

        # Initialize view parameters
        self.zoom_factor = 1.0
        self.translation_x = 0.0
        self.translation_y = 0.0

    def initUI(self):
        # glutInit()  # Move glutInit here
        self.expression_line_edit = QLineEdit(self)
        self.expression_line_edit.setPlaceholderText("Enter a function in terms of 'x' (e.g., sin(x) + x**2)")

        self.plot_button = QPushButton('Plot', self)
        self.plot_button.clicked.connect(self.plotFunction)

        # Connect returnPressed signal to plotFunction method
        self.expression_line_edit.returnPressed.connect(self.plotFunction)

        layout = QVBoxLayout(self)
        layout.addWidget(self.expression_line_edit)
        layout.addWidget(self.plot_button)

    def plotFunction(self):
        expression = self.expression_line_edit.text()
        if expression.lower() in ['quit', 'exit', 'q']:
            sys.exit()

        self.update()

    def paintGL(self):
        expression = self.expression_line_edit.text()
        self.display(expression)

    def initializeGL(self):
        glClearColor(1.0, 1.0, 1.0, 1.0)
        # gluOrtho2D(-5.0, 5.0, -10.0, 10.0)  # Adjusted the range for centering

    def draw_function(self, expression):
        glColor3f(0.0, 0.0, 0.0)
        # change stroke
        # glLineWidth(10.0)

        # Draw axes
        glBegin(GL_LINES)
        glVertex2f(-5.0, 0.0)
        glVertex2f(5.0, 0.0)
        glVertex2f(0.0, -10.0)
        glVertex2f(0.0, 10.0)
        glEnd()

        # Draw axis ticks and labels
        for x_tick in range(-5, 6):
            x_pos = x_tick
            y_pos = 0.2 if x_tick != 0 else 0.4
            glBegin(GL_LINES)
            glVertex2f(x_pos, -0.1)
            glVertex2f(x_pos, 0.1)
            glEnd()

            self.render_text(x_pos - 0.1, -y_pos, str(x_tick))

        for y_tick in range(-10, 11):
            x_pos = 0.2 if y_tick != 0 else 0.4
            y_pos = y_tick
            glBegin(GL_LINES)
            glVertex2f(-0.1, y_pos)
            glVertex2f(0.1, y_pos)
            glEnd()

            self.render_text(x_pos - 0.3, y_pos - 0.1, str(y_tick))

        # Draw function graph
        glBegin(GL_LINE_STRIP)
        for x in range(-50, 51):
            try:
                y = eval(expression, {'x': x / 10.0, 'sin': math.sin, 'cos': math.cos, 'sqrt': math.sqrt, 'exp': math.exp,
                                       'log': math.log, 'log10': math.log10, 'tan': math.tan, 'asin': math.asin,
                                       'acos': math.acos, 'atan': math.atan, 'sinh': math.sinh, 'cosh': math.cosh,
                                       'tanh': math.tanh, 'pi': math.pi, 'e': math.e, 'I': 1j})
                glVertex2f(x / 10.0, y.imag if isinstance(y, complex) else y)
            except (SyntaxError, ValueError, ZeroDivisionError):
                continue
        glEnd()

    def render_text(self, x, y, text):
        glRasterPos2f(x, y)
        # for char in text:
        #     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ord(char))

    def display(self, expression):
        glClear(GL_COLOR_BUFFER_BIT)

        # Apply translation and zoom
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        glTranslatef(self.translation_x, self.translation_y, 0.0)
        glScalef(self.zoom_factor, self.zoom_factor, 1.0)

        # Centered text position
        text_length = len(expression)
        text_x = -text_length / 40.0
        text_y = 9.0

        # Display text
        self.render_text(text_x, text_y, expression)

        # Draw function graph and coordinate system
        self.draw_function(expression)

        glFlush()

    def wheelEvent(self, event):
        # Handle wheel events for zooming
        zoom_factor = 1.2
        if event.angleDelta().y() < 0:
            self.zoom_factor /= zoom_factor
        else:
            self.zoom_factor *= zoom_factor

        self.update()

    def mousePressEvent(self, event):
        # Handle mouse press events for panning
        self.last_pos = event.pos()

    def mouseMoveEvent(self, event):
        # Handle mouse move events for panning
        dx = event.x() - self.last_pos.x()
        dy = event.y() - self.last_pos.y()

        self.translation_x += dx / 100.0
        self.translation_y -= dy / 100.0

        self.last_pos = event.pos()

        self.update()

