cd .\src\
gcc -Wall -c lib.c
gcc -Wall -c main.c

cd ..\build\
gcc -o stoopid ..\src\lib.o ..\src\main.o

cd ..\src\
del lib.o
del main.o