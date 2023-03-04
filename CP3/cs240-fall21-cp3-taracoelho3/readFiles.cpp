#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "readFiles.h"

using namespace std;

readFiles::readFiles() : venuesList() , usersList(){
    venuefile = "";
    userfile = "";
    activityfile = "";
    attendancefile = "";

}

readFiles::readFiles(string venueFile, string userFile, string activityFile, string attendanceFile) 
: venuesList() , usersList(){
    venuefile = venueFile;
    userfile = userFile;
    activityfile = activityFile;
    attendancefile = attendanceFile;
}

void readFiles::readVenues(){
    ifstream inFS;
    ofstream outFS;
    string currName;
    int lineNum = 0;
    
    inFS.open(this->venuefile);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }

    outFS.open("venues.cp3out.txt");

    if(!outFS.is_open()){
        cout << "Could not open file." << endl;
    }
  
    while(!inFS.eof()){
        string name;
        string location;
        int capacity;
        string line;
  
        getline(inFS, line);
        lineNum++;

        stringstream ss(line);

        ss >> name;
        ss >> capacity;
        ss >> location;

        Venue venue1(name, capacity, location);
    
        if(venuesList.searchVenue(name) == false){
            venuesList.addVenue(venue1);
            outFS << line << endl;
        }
        else{
            cout << "Venue file " << this->venuefile << " line " << lineNum << ": venue " << name << " exists - ignoring" <<endl;
        }
    }
 
    inFS.close();
    outFS.close();
}

void readFiles::readUsers(){
    ifstream inFS;
    ofstream outFS;
    string currName;
    int lineNum = 0;

    inFS.open(this->userfile);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }

    outFS.open("users.cp3out.txt");

    if(!outFS.is_open()){
        cout << "Could not open file." << endl;
    }
  
    while(!inFS.eof()){
        string userID;
        string firstname;
        string lastname;
        string line;

        getline(inFS, line);
        lineNum++;

        stringstream ss(line);

        ss >> userID;
        ss >> firstname;
        ss >> lastname;

        User user1(userID, firstname, lastname);

        if(usersList.searchUser(userID) == false){
            usersList.addUser(user1);
            outFS << line << endl;
        }
        else{
            cout << "User file " << this->userfile << " line " << lineNum << ": userid " << userID << " exists - ignoring" <<endl;
        }
       
    }

    inFS.close();
    outFS.close();
}

void readFiles::readActivities(){
    ifstream inFS;
    ofstream outFS;
    string currAct;
    int lineNum = 0;

    inFS.open(activityfile);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }

    outFS.open("activities.cp3out.txt");

    if(!outFS.is_open()){
        cout << "Could not open file." << endl;
    }
  
    while(!inFS.eof()){
        string title;
        string creator;
        string beginTime;
        string beginDate;
        string endTime;
        string endDate;
        string venueName;
        bool validVenue = false;
        bool validUser = false;
        char exclusive;
        string line;

        getline(inFS, line);
        lineNum++;

        stringstream ss(line);

        ss >> title;
        ss >> creator;
        ss >> beginTime;
        ss >> beginDate;
        ss >> endTime;
        ss >> endDate;
        ss >> venueName;
        ss >> exclusive;
cout << title << "  name" << endl;
	if(title == ""){
		break;
	}

        Occurrence start(beginTime, beginDate);
        Occurrence end(endTime, endDate);
        Activity activity1(title, creator, start, end, venueName, exclusive);
    
        if(usersList.searchUser(creator) == 1){
            validUser = true;
        }
        else{
          cout << "Activity file " << activityfile << " line " << lineNum << ": user " << creator << " does not exist" <<endl;
        }
        if(venuesList.searchVenue(venueName) == 1){
          validVenue = true;
        }
        else{
            cout << "Activity file " << activityfile << " line " << lineNum << ": venue " << venueName << " does not exsit" <<endl;
        }

        if(validVenue == 1 && validUser == 1){
          Activity act = venuesList.searchAndReturnAct(activity1);
          Activity newAct(act);
    
          bool result = venuesList.add(newAct, activityfile, lineNum);
        
          if(result == 1){
              outFS << line << endl;
          }else{
         
          }
        }

    }
    inFS.close();
    outFS.close();
}

void readFiles::readAttendance(){
    ifstream inFS2;
    ofstream outFS2;
    int lineNum = 0;

    inFS2.open(attendancefile);
   
    if(!inFS2.is_open()){
        cout << "Could not open file" << endl;
    }

    outFS2.open("attendance.cp3out.txt");

    if(!outFS2.is_open()){
        cout << "Could not open file." << endl;
    }

    while(!inFS2.eof()){
        string activity;
        string user;
        string line;
        bool validUser = false;
        bool validAct = false;

        getline(inFS2, line);
        lineNum++;

        stringstream ss(line);

        ss >> activity;
        ss >> user;

        Occurrence start;
        Occurrence end;
        Activity a(activity, "", start, end, "", 'n');
    
        if(usersList.searchUser(user) == 1){
            validUser = true;
        }
        else{
          cout << "Attendance file " << attendancefile << " line " << lineNum << ": user " << user << " does not exist" <<endl;
        }
        if(venuesList.searchAct(a) == 1){
          validAct = true;
        }
        else{
          cout << "Attendance file " << attendancefile << " line " << lineNum << ": activity " << activity << " does not exsit" <<endl;
        }

        if(validAct == 1 && validUser == 1){

            Activity act = venuesList.searchAndReturnAct(a);
            Activity newAct(act);
    
            if(venuesList.getAttendance(newAct.getVenue()) > venuesList.getCapacity(newAct.getVenue())){
                cout << "Attendance file " << attendancefile << " line " << lineNum << ": user " << user << " cannot attend " << activity <<
                " because venue is full - ignoring " << endl;
            }else{
             venuesList.addAttendee(newAct.getVenue());
      
             bool result = usersList.addAct(newAct, user, attendancefile, lineNum);
      
             if(result == 1){
               outFS2 << line << endl;
            }else{
              
           }
        }
        }

    } 

    inFS2.close();
    outFS2.close();
}

readFiles::~readFiles(){

}
