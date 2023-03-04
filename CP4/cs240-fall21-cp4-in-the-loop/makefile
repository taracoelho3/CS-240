all:	launch

launch:	launch.o
	g++ -g -Wall -std=c++11 launch.o User.o Vote.o Tree.o Heap.o -o launch

launch.o:	launch.cpp User.o Tree.o Heap.o Vote.o
	g++ -c launch.cpp

Vote.o: Vote.cpp Vote.h
	g++ -c Vote.cpp

User.o: User.cpp User.h
	g++ -c User.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

clean:

	rm -f *.o launch main