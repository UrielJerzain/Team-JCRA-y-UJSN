echo compiling
gcc -c MaquinaE.c -o MaquinaE.o
gcc -c MaquinaE2.c -o MaquinaE2.o
gcc -o Ma.exe MaquinaE.o MaquinaE2.o
.\Ma.exe
pause