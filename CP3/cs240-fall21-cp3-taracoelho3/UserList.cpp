#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "UserList.h"


using namespace std;

UserList::UserList() : users(){
    filename = "";
    numUsers = 0;

}

UserList::UserList(string filename) : users(){
    this->filename = filename;
    this->numUsers = 0;
    
}

bool UserList::searchUser(string userName){
    User temp(userName,"", "");
    return users.search(temp);
}

bool UserList::addAct(Activity a, string user, string attendancefile, int line){

    User search(user, "", "");
    int i = users.searchAndReturnIndex(search);
    bool result = false;
    bool flag = false;
   
    if(users.returnAt(i).getNumActs() == 0){
        users.returnAt(i).add(a);
        return true;
    }
    else if(users.returnAt(i).checkOverlap(a, user, attendancefile, line) == false){
        users.returnAt(i).add(a);
        return true;
    }
    else{
        return false;
    } 
}

void UserList::addUser(User u){
    users.add(u);
    numUsers++;
}

bool UserList::checkOverlap(Activity a, string user, string attendancefile, int line){
   bool result = false;
   bool flag = false;
   for(int i = 0; i < numUsers; i++){
        result = users.returnAt(i).checkOverlap(a, user, attendancefile, line);
        if(result == true){
            flag = true;
        }  
   }
   return true;
}

string UserList::getFileName(){
    return filename;
}

int UserList::getAttendance(Activity a, string user){
    User search(user, "", "");
    int i = users.searchAndReturnIndex(search);
    return users.returnAt(i).getAttendance(a);
}

UserList::~UserList(){

}