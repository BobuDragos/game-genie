#!/usr/bin/env python

import argparse
from pathlib import Path
import os
import sys
from shutil import copytree

parser = argparse.ArgumentParser("cli tool to use the game engine in order to create your game")
subparsers = parser.add_subparsers(title="subcommands", dest="command")

# the "init" command
parser_init = subparsers.add_parser("init", help="init a new project (create folder structure)")
parser_init.add_argument("path", type=str, help="path to the project folder")
# parser_init.add_argument("-y", type=bool, help="auto-remove folder in case it is not empty (WARN: dangerous)")


# the "run" command
parser_run = subparsers.add_parser("run", help="run the game")
parser_run.add_argument("path", type=str, help="path to the project folder")


args = parser.parse_args()

if args.command == "init":
    print("creating folder structure")
    project_path = Path(args.path).resolve()
    template_path = Path(__file__).resolve().parent / "template"
    print(f"Copying template files from {template_path} to {project_path}")
    if os.path.exists(project_path):
        print(f"WARN: {project_path} is not an empty directory")
        if input(f"delete it? (y/n)").lower() != "Y".lower():
            print("transaction aborted, nothing changed.")
            exit
        if sys.platform.startswith('win'):
            os.system(f'rmdir /s /q {project_path}')
        elif sys.platform.startswith('linux'):
            os.system(f'rm -r {project_path}')

    copytree(template_path, project_path)
    print("Done.")


if args.command == "run":
    project_path = args.path
    #get full project path
    project_path = Path(project_path).resolve()
    print(f"running the {project_path} game")
    os.system(f"cd {project_path} && python -m game run {project_path}/game")
    print("Done.")
