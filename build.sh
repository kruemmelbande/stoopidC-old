mkdir build
cd src
gcc -Wall -c *.c
cd ..
cd build
gcc -o stoopid ../src/*.o 
cd ../src
rm *.o
echo build sucessful
