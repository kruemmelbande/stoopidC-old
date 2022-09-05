@echo off
echo compiling scripts...
cd .\src\
gcc -Wall -c lib.c
gcc -Wall -c global.c
gcc -Wall -c main.c
echo compiled scripts
echo:

echo building exe...
cd ..\build\
gcc -o stoopid ..\src\lib.o ..\src\global.o ..\src\main.o
echo build finished
echo:

cd ..\src\
del lib.o
del main.o
echo successfully build exe
echo:
@echo on