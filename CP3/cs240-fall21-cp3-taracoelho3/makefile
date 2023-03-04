all:		cp3

cp3:		cp3.o readFiles.o VenueList.o Venue.o UserList.o User.o Activity.o Occurrence.o
	g++ cp3.o readFiles.o VenueList.o Venue.o UserList.o User.o Activity.o Occurrence.o -o cp3.exe

cp3.o: cp3.cpp 
	g++ -c cp3.cpp 

readFiles.o: readFiles.cpp readFiles.h
	g++ -c readFiles.cpp

VenueList.o: VenueList.cpp VenueList.h
	g++ -c VenueList.cpp 

Venue.o:	Venue.cpp Venue.h
	g++ -c Venue.cpp Venue.h

UserList.o:	UserList.cpp UserList.h
	g++ -c UserList.cpp UserList.h

User.o:	User.cpp User.h
	g++ -c User.cpp User.h

Activity.o: Activity.cpp Activity.h
	g++ -c Activity.cpp Activity.h

Occurrence.o: Occurrence.cpp Occurrence.h
	g++ -c Occurrence.cpp Occurrence.h

clean:
	rm -f *.o *.gch cp3.exe userOut.txt venueOut.txt