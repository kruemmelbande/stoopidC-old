@echo off
mkdir build

echo compiling scripts...
cd .\src\
gcc -Wall -c lib.c
gcc -Wall -c global.c
g++ -Wall -c variables.cpp
gcc -Wall -c main.c
echo compiled scripts
echo:

echo building exe...
cd ..\build\
g++ -o stoopid ..\src\lib.o ..\src\global.o ..\src\variables.o ..\src\main.o
echo build finished
echo:

cd ..\src\
del lib.o
del main.o
del global.o
del variables.o
echo successfully build exe
echo:
@echo on