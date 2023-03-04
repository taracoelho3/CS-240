#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "VenueList.h"

using namespace std;

VenueList::VenueList() : venues(){
    filename = "";
    numVenues = 0;
    available = true;

}

VenueList::VenueList(string filename) : venues(){
    this->filename = filename;
    numVenues = 0;
    available = true;
 
}

bool VenueList::searchVenue(string venueName){
    Venue temp(venueName, 0, "");
    return venues.search(temp);
}

void VenueList::addVenue(Venue v){
    venues.add(v);
    numVenues++;
}

bool VenueList::add(Activity a, string activityfile, int line){
    bool result = this->checkOverlap(a, activityfile, line);

    if(result == true){
        return false;
    }
    else{
        Venue search(a.getTitle(), 0, "");
        int i = venues.searchAndReturnIndex(search);
        venues.returnAt(i).add(a);
        return true;
    }
}



bool VenueList::checkOverlap(Activity a, string activityfile, int line){
   bool result = false;
   bool flag = false;
   for(int i = 1; i < numVenues; i++){
        result = venues.returnAt(i).checkOverlap(a, activityfile, line);
        if(result == 1){
            flag = true;
        }
   }
   return flag;
}

bool VenueList::searchAct(Activity a){
    bool result = false;
    for(int i = 0; i < numVenues; i++){
        result = venues.returnAt(i).searchAct(a);
    }

    return result;
}


Activity& VenueList::searchAndReturnAct(Activity a){
    bool result = false;
    int key = 0;
    for(int i = 0; i < numVenues; i++){

        result = venues.returnAt(i).searchAct(a);
        if(result == 1){
            key = i;
            break;
        }
    }
    return venues.returnAt(key).searchReturnAct(a);
}



int VenueList::getCapacity(string name){
    Venue search(name, 0, "");
    int i = venues.searchAndReturnIndex(search);
    Venue curr = venues.returnAt(i);
    return curr.getCapacity();
}

int VenueList::getAttendance(string name){
    Venue search(name, 0, "");
    int i = venues.searchAndReturnIndex(search);
    Venue curr = venues.returnAt(i);
    return curr.getAttendance();
}

void VenueList::addAttendee(string name){
    Venue search(name, 0, "");
    int i = venues.searchAndReturnIndex(search);
    venues.returnAt(i).addAttendee();
}

VenueList::~VenueList(){

}