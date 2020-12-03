echo compiling
gcc -c BML.c -o BML.o
gcc -c Config.c -o Config.o
gcc -c Start1.c -o Start1.o
gcc -o test.exe BML.o Config.o Start1.o
.\test.exe
pause