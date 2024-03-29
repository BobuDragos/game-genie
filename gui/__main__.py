from PyQt6.QtWidgets import (
    QApplication, 
    QMainWindow, 
    QLabel,
    QSplitter,
)
from PyQt6.QtCore import (
    Qt,
)


from gui.canvas.__main__ import OpenGLWidget as canvas 

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Editor")
        spliter = QSplitter()

        inspector = QLabel("Inspector")
        spliter.addWidget(inspector)

        spliter.addWidget(canvas())

        properties = QLabel("Properties")
        spliter.addWidget(properties)

        self.setCentralWidget(spliter)



if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())