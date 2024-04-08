print("scene-0 __main__")
from pathlib import Path
import os


def loop():
    gameobjects_dir = f"{Path(__file__).parent.resolve()}/gameobjects"

    gameobjects = os.listdir(gameobjects_dir)
    for go in gameobjects:
        os.system(f"python {gameobjects_dir}/{go}/update.py")

if __name__ == "__main__":
    loop()
