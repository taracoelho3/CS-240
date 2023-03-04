#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "VenueList.h"
#include "DoublyLinkedList.cpp"

using namespace std;

class User{

	public:
        User();
        User(string userID, string firstname, string lastname);
        User(const User &u);
        void add(Activity &act);
        int getAttendance(Activity a);
        bool checkOverlap(Activity a, string user, string attendancefile, int line);
        string getUserID();
        int getNumActs();
        void setUserID(string userID);
        void display();
        User& operator=(const User &currUser);
        bool operator==(const User &u);
        User& operator*();
        friend ostream& operator<<(ostream &r, const User &u);
        ~User();
    
    private:
        DoublyLinkedList<Activity> acts;
        string userID;
        string firstname;
        string lastname;
        int numActs;
};