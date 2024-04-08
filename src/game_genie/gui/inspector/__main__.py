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


class Inspector(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        layout = QVBoxLayout(self)
        layout.addWidget(QLabel("Inspector"))
        layout.addWidget(QLabel("Object Name 1"))
        layout.addWidget(QLabel("Object Name 2"))
        layout.addWidget(QLabel("Object Name 3"))
