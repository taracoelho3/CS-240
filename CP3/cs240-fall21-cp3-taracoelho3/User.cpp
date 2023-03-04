#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;
#include "User.h"


User::User() : acts(){
   numActs = 0;
    userID = "";
    firstname = "";
    lastname = "";
}

User::User(string userID, string firstname, string lastname) : acts(){
    this->numActs =0;
    this->userID = userID;
    this->firstname = firstname;
    this->lastname = lastname;
}

User::User(const User &u): acts(){
    numActs = u.numActs;
    userID = u.userID;
    firstname = u.firstname;
    lastname = u.lastname;
    acts = u.acts;
}

void User::add(Activity &act){
    acts.add(act);
    act.addAttendee();
    numActs++;
}

int User::getAttendance(Activity act){
    int i = acts.searchAndReturnIndex(act);
    return acts.returnAt(i).getAttendance();
}


bool User::checkOverlap(Activity a, string user, string attendancefile, int line){
    bool result = false;
    bool flag = false;
    for(int i = 1; i < numActs; i++){
        result = acts.returnAt(i).checkOverlapAttendance(a, user, attendancefile, line);
        if(result == 1){
            flag = true;
        }
    }

    return flag;
}


string User::getUserID(){
    return userID;
}

int User::getNumActs(){
    return numActs;
}

void User::setUserID(string userID){
    this->userID = userID;
}

void User::display(){
    acts.display();
}

 User& User::operator=( const User &currUser){

    this->userID = currUser.userID;
    this->firstname = currUser.firstname;
    this->lastname = currUser.lastname;
    this->numActs = currUser.numActs;
    this->acts = currUser.acts;
	return *this;
}

bool User::operator==(const User &u){

    if(this->userID == u.userID){
        return true;
    }
    else{
        return false;
    }
}

User& User::operator*(){
    return *this;
}

ostream& operator <<(ostream &r, const User &u){
    r << u.userID << " " << u.firstname << " " << u.lastname << endl;
    return r;
}

User::~User(){
   // ~acts;
}

