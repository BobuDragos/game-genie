print("scene-0 __init__")
from pathlib import Path
import os


def setup():
    gameobjects_dir = f"{Path(__file__).parent.resolve()}/gameobjects"

    gameobjects = os.listdir(gameobjects_dir)
    for go in gameobjects:
        os.system(f"python {gameobjects_dir}/{go}/start.py")

if __name__ == "__main__":
    setup()
