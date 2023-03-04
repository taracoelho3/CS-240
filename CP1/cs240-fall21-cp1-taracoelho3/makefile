# Specifiy the target
all:	ActivityUser 

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
ActivityUser:	ActivityUser.o Activity.o
	g++ ActivityUser.o Activity.o -o ActivityUser



# Specify how the object files should be created from source files
Activity.o:	Activity.cpp Activity.h
	g++ -c Activity.cpp Activity.h
ActivityUser.o: ActivityUser.cpp Activity.h
	g++ -c ActivityUser.cpp Activity.h

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o ActivityUser.exe   	
