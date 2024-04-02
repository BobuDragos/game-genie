#!/usr/bin/env python

import argparse
from pathlib import Path
import os
from shutil import copytree

parser = argparse.ArgumentParser("cli tool to use the game engine in order to create your game")
subparsers = parser.add_subparsers(title="subcommands", dest="command")

# the "init" command
parser_init = subparsers.add_parser("init", help="init a new project (create folder structure)")
parser_init.add_argument("path", type=str, help="path to the project folder")


# the "run" command
parser_run = subparsers.add_parser("run", help="run the game")
parser_run.add_argument("path", type=str, help="path to the project folder")


args = parser.parse_args()

if args.command == "init":
    print("creating file structure")
    project_path = Path(args.path).resolve()
    template_path = Path(__file__).resolve().parent / "template"
    print(f"Copying template files from {template_path} to {project_path}")
    copytree(template_path, project_path)
    print("Done.")


if args.command == "run":
    print("running the game")
    project_path = args.path
    #get full project path
    project_path = Path(project_path).resolve()
    print(f"running the game from {project_path}")
    os.system(f"cd {project_path} && python -m game")
    print("Done.")
