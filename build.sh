mkdir build
cd src
gcc -Wall -c lib.c
gcc -Wall -c main.c
cd ..
cd build
gcc -o stoopid ../src/lib.o ../src/main.o
cd ../src
rm *.o
echo build sucessful
