#!/usr/bin/env python

import argparse
from pathlib import Path
import os
from shutil import copytree

parser = argparse.ArgumentParser(
    "cli tool to use the game engine in order to create your game"
)
subparsers = parser.add_subparsers(title="subcommands", dest="command")

# the "init" command
parser_init = subparsers.add_parser(
    "init", help="init a new project (create folder structure)"
)
parser_init.add_argument("path", type=str, help="path to the project folder")

args = parser.parse_args()

if args.command == "init":
    print("creating file structure for your game")
    project_path = args.path
    print("creating directories")
    # os.makedirs(project_path, exist_ok=True)
    template_path = Path(__file__).resolve().parent / "template"
    print(f"Copying template files from {template_path} to {project_path}")
    copytree(template_path, project_path)
    print("Done.")
