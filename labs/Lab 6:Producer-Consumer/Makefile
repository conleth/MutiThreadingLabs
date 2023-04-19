#Conleth Kennedy 16/11/2019
#Make file for compile debug and removal of object files 
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++17 -pthread -Wall

#This rule says each o.file depends on a .cpp file of the same name 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)
#Compile the files
ALL: main.o Semaphore.o Event.o SafeBuffer.o
	$(CC) -o prodCon Event.o Semaphore.o main.o SafeBuffer.o $(CFLAGS) $(DEBUGFLAGS)
docs:
	doxygen Doxyfile
DEBUG: DEBUGFLAGS = .DEBUG
DEBUG: ALL


CLEAN:
	rm *.o
