
# from game.scene_0 import OpenGLWidget as canvas

# def setup():
#     for scene in scenes:
#         # os.system(f"cd {scenes_dir} && python -m {scene}")
#         os.system(f"python {scenes_dir}/{scene}/start.py")








# def loop():
#     print("game loop")
#     scenes_dir = f"{Path(__file__).parent.resolve()}/assets/scenes"
#
#     scenes = os.listdir(scenes_dir)
#     for scene in scenes:
#         os.system(f"python {scenes_dir}/{scene}/update.py")
#     # os.system(f"python -m {Path(__file__) + "/assets/"}"})
#
# if __name__ == "__main__":
#     # setup()
#     frames = 0
#     while True:
#         loop()
#         frames += 1
#         if frames > 10:
#             break









    # class sceneSelector(QWidget):
    #
    #     def loadScene(self, scene_path):
    #         activeScene_path = scene_path
    #         MainWindow.setActiveScene(activeScene_path)
    #         print(f"{activeScene_path}")
    #
    #     def __init__(self):
    #         super().__init__()
    #         main_layout = QVBoxLayout()
    #         self.setLayout(main_layout)
    #
    #         scenes_dir = f"{Path(__file__).parent.resolve()}/assets/scenes"
    #         scenes = os.listdir(scenes_dir)
    #         
    #         for scene in scenes:
    #             choice = QWidget()
    #             choice_layout = QVBoxLayout()
    #             choice.setLayout(choice_layout)
    #
    #             self.play_button = QPushButton(f"{scene}")
    #             self.play_button.clicked.connect(lambda x: self.loadScene(f"{scenes_dir}/{scene}")) 
    #
    #             choice_layout.addWidget(self.play_button)
    #
    #             main_layout.addWidget(choice)
    #
    #     def setActiveScene(self,scene_path):
    #         # TODO: import dynamically
    #         from game.assets.scenes.scene_0.__main__ import OpenGLWidget as canvas
    #
    #         self.splitter.addWidget(canvas)
    #
