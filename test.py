import os 

def setup():
    if os.path.exists("./games-built/0"):
        os.system('rmdir /s /q "./games-built/0"')
    os.system("python ./functional-game-engine/__main__.py init games-built/0")

def test():
    os.system("python ./functional-game-engine/__main__.py run games-built/0")
    pass

if __name__ == "__main__":
    setup()
    test()