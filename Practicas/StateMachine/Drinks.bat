echo compiling
gcc -c Drinks.c -o Drinks.o
gcc -c Machine.c -o Machine.o
gcc -o Test.exe Drinks.o Machine.o
.\Test.exe
pause