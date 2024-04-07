import os 
import sys

exec_path = "/home/admin/git/functional-game-engine"

def setup():
    if os.path.exists("./games-built/0"):
        if sys.platform.startswith('win'):
            os.system('rmdir /s /q "./games-built/0"')
        elif sys.platform.startswith('linux'):
            os.system('rm -r "./games-built/0"')
    os.system(f"python {exec_path}/__main__.py init games-built/0")

def test():
    os.system(f"cd games-built/0 && python {exec_path}/__main__.py run .")
    pass

if __name__ == "__main__":
    setup()
    test()
