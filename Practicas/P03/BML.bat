echo compiling
gcc -c BML.c -o BML.o
gcc -c Config.c -o Config.o
gcc -o test.exe BML.o Config.o 
.\test.exe
pause