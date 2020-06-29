import subprocess as sp
import os
import argparse

parser = argparse.ArgumentParser(description='TGEngine Clang Compile Script (TCCS).')
parser.add_argument('--linux', action='store_true', help='compile the engine for linux')
parser.add_argument('-v', action='store_true', help='verbose output')
args = parser.parse_args()

if not os.path.exists("out"): os.mkdir("out")

if args.linux: name = "clang-compile-linux.txt"
else: name = "clang-compile.txt"

with open(name) as fp: lines = fp.readlines()
for x in range(len(lines)): lines[x] = lines[x].strip()

regexReplace = {}
walkdir = []
for root, dirs, files in os.walk("."):
    if "\\bin\\" in root or "/bin/" in root: continue
    for name in files: walkdir.append(os.path.join(root, name))

cppFiles = list(filter(lambda x: x.endswith(".cpp"), walkdir))
regexReplace["files"] = " ".join(cppFiles)

lines = list(filter(lambda x: x and not x.startswith("#"), lines))
oFiles = cppFiles.copy()
for x in range(len(oFiles)):
    splitstr = os.path.basename(oFiles[x])
    oFiles[x] = splitstr.replace(".cpp", ".o")
regexReplace["filesout"] = " ".join(oFiles)

def replaceAll():
    for x in range(0, len(lines)):
        if x >= len(lines): break
        line = lines[x]
        if ":=" in line:
            setter = line.split(":=")
            regexReplace[setter[0].strip()] = setter[1].strip()
            lines.remove(line)
            continue

        for toreplace, replace in regexReplace.items():
            lines[x] = lines[x].replace("%" + toreplace + "%", replace)

replaceAll()
replaceAll()
replaceAll()
replaceAll()

for line in lines:
    if args.v:
        print(line)
    sp.run(line, shell=True)
