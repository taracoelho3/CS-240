#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "User.h"
#include "DoublyLinkedList.cpp"

using namespace std;

class UserList{
    public:
        UserList();
        UserList(string filename);
        bool searchUser(string userName);
        void addUser(User u);
        bool addAct(Activity a, string user, string attendancefile, int line);
        bool checkOverlap(Activity a, string user, string attendancefile, int line);
        string getFileName();
        int getAttendance(Activity a, string user);
        ~UserList();
    private:
        string filename;
        int numUsers;
        DoublyLinkedList<User> users;
};