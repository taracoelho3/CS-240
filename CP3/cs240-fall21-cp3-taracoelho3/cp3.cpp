#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "readFiles.h"

using namespace std;


int main(int argc, char** argv) {
    
    string inFileVenue= "";
    string inFileUser = "";
    string inFileActivity = "";
    string inFileAttendance = "";
    
    if( argc == 5 ) {
      inFileVenue = argv[1];
      inFileUser = argv[2];
      inFileActivity = argv[3];
      inFileAttendance = argv[4];
    }
    else {
      cout << "Usage: ./VenueTest InputFile OutputFile\n";
      return 1;
    }

    readFiles reader(inFileVenue, inFileUser, inFileActivity, inFileAttendance);
    reader.readVenues();
    reader.readUsers();
    reader.readActivities();
    reader.readAttendance();
}