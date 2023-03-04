#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Venue.h"
#include "DoublyLinkedList.cpp"

using namespace std;

class VenueList{
    public:
        VenueList();
        VenueList(string filename);
        bool searchVenue(string venueName);
        void addVenue(Venue v);
        bool add(Activity a, string activityfile, int line);
        bool checkOverlap(Activity a, string activityfile, int line);
        bool searchAct(Activity a);
        Activity& searchAndReturnAct(Activity a);
        int getCapacity(string name);
        int getAttendance(string name);
        void addAttendee(string name);
        ~VenueList();
       
    private:
        string filename;
        int numVenues;
        bool available;
        DoublyLinkedList<Venue> venues;
};