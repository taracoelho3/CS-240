#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include "UserList.h"

using namespace std;

class readFiles{
    public:
        readFiles();
        readFiles(string venueFile, string userFile, string activityFile, string attendanceFile);
        void readVenues();
        void readUsers();
        void readActivities();
        void readAttendance();
        ~readFiles();
    private:
        string venuefile;
        string userfile;
        string activityfile;
        string attendancefile;
        VenueList venuesList;
        UserList usersList;
};