echo compiling
gcc -c McDonalds.c -o McDonalds.o
gcc -c McDonalds2.c -o McDonalds2.o
gcc -o test.exe McDonalds.o McDonalds2.o
.\test.exe
pause