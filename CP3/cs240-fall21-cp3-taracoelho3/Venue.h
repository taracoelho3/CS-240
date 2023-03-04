#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Activity.h"
#include "DoublyLinkedList.cpp"

using namespace std;

class Venue{
    public:
        Venue();
        Venue(string name, int capacity, string location );
        Venue(const Venue &v);
        string getName();
        int getCapacity();
        void print();
        bool checkOverlap(Activity a, string activityfile, int line);
        void add(Activity a);
        void displayActs();
        bool searchAct(Activity a);
        Activity& searchReturnAct(Activity &a);
        void addAttendee();
        int getAttendance();
        Venue& operator=(const Venue &v);
        bool operator==(const Venue &v);
        Venue& operator*();
        friend ostream& operator<<(ostream &r, const Venue &v);
        ~Venue();

    private:
        DoublyLinkedList<Activity> acts;
        string name;
        string location;
        int capacity; 
        int counter;
        int numActs;
};