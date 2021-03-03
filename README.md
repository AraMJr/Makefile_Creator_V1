# Makefile_Creator_V1

C program to create makefiles in linux terminal.

Takes the folder location and desired makefile name as arguments

User can then:
  1. Automatically configure makefile (currently only supports with .c files)
  2. Manually configure makefile (currently only supports .c files)
  3. Change editor name (by default prints _UNLISTED_ in file heading)
  4. Print generated file name (displays proposed makefile directory)
  0. Terminate program

For the time being, this program only creates makefiles based on the format required for one of my classes (compiles with -Wall), but will soon expand to include a few others

Update (3/2/21): main.c now checks to see if file location is valid before printing menu.

