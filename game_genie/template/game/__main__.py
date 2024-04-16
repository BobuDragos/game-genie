# print("game/__main__.py")
import os
import json
from pathlib import Path
import sys
import math

from PyQt6.QtWidgets import *
from PyQt6.QtCore import *

import argparse
from pathlib import Path
import os
import sys

parser = argparse.ArgumentParser("the game")
subparsers = parser.add_subparsers(title="subcommands", dest="command")

# the "run" command
parser_run = subparsers.add_parser("run", help="run the game")
# parser_run.add_argument("path", type=str, help="path to the scene selected")
# parser_run.add_argument("path", type=str, help="path to the project folder")
parser_run.add_argument("path", type=str, help="path to the game folder")

args = parser.parse_args()

if args.command == "run":
    game_path= Path(args.path).resolve()
    print(f"GAME/__main__: received {game_path} from cli") 
    print(f"GAME/__main__: starting pyPackage: {game_path}/scene_1") 
    os.system(f"cd {game_path} &&  python -m scene_1")

#
# class MainWindow(QMainWindow):
#     def __init__(self):
#         super().__init__()
#         # self.splitter = QSplitter()
#         ## self.splitter.addWidget(sceneSelector())
#         # self.splitter.addWidget(canvas())
#         # self.setCentralWidget(self.splitter)
#
#
# if __name__ == "__main__":
#     app = QApplication(sys.argv)
#     window = MainWindow()
#     window.show()
#     sys.exit(app.exec())



