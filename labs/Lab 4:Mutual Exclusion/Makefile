#Conleth Kennedy 16/11/2019
#Make file for compile debug and removal of object files 
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++17 -pthread

#This rule says each 0.file depends on a .cpp file of the same name 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o
	$(CC) -o me Semaphore.o main.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = .DEBUG
DEBUG: ALL


CLEAN:
	rm *.o
