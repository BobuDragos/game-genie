import argparse
from pathlib import Path

parser = argparse.ArgumentParser(description="File Manager Utility")

subparsers = parser.add_subparsers(title="subcommands", dest="command")

# create the parser for the "init" command
parser_init = subparsers.add_parser(
    "init", help="init a new project (create folder structure)"
)

parser_init.add_argument("path", type=Path, help="path to the project folder")

args = parser.parse_args()

if args.command == "init":
    print(args.path)
