import os
from pathlib import Path



canvas_path = Path(__file__).parent
print(f"GAME/SCENE_1/__main__:  received {canvas_path} from cli")
os.system(f"cd {Path(__file__).parent} && g++ sceneManager.cpp -o scene -lGL -lGLU -lglut -ldl -lm && ./scene")



