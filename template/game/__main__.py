print("game/__main__.py")
import os
import json
from pathlib import Path


def dir_to_json(directory):
    def create_node(path):
        node = {
            # "name": os.path.basename(path),
            # "path": os.path.abspath(path),
        }
        if os.path.isdir(path):
            # node["type"] = "folder"
            node[f"{os.path.basename(path)}"] = [create_node(os.path.join(path, child)) for child in os.listdir(path)]
        else:
            node[f"{os.path.basename(path)}"] = open(path, "r").read()
        return node

    return create_node(directory)

def setup():
    scenes_dir = f"{Path(__file__).resolve().parent}/assets/scenes"

    # load all the data from the disk
    scenes = dir_to_json(scenes_dir)
    print(json.dumps(scenes, indent=1, sort_keys=True))

    # scenes = []

    # for scene in os.listdir(scenes_dir):
    #     gameobjects_dir = f"{scenes_dir}/{scene}/gameobjects"
    #     objects = []

    #     for gameobject in os.listdir(gameobjects_dir):
    #         components_dir = f"{gameobjects_dir}/{gameobject}/components"
    #         components = []

    #         for component in os.listdir(components_dir):
    #             components.append({
    #                 "name": component,
    #                 "path": str(Path(f"{components_dir}/{component}").resolve())
    #             })



    #         objects.append({
    #             "name": gameobject,
    #             "path": str(Path(f"{gameobjects_dir}/{gameobject}").resolve()),
    #             "components": components,
    #         })

    #     scenes.append({
    #         "name": scene,
    #         "path": str(Path(f"{scenes_dir}/{scene}").resolve()),
    #         "objects": objects
    #     })

    print(json.dumps(scenes, indent=1, sort_keys=True))



def loop():
    print("game loop")
    # os.system(" python -m  ")

if __name__ == "__main__":
    setup()
    frames = 0
    while True:
        loop()
        frames += 1
        if frames > 10:
            break