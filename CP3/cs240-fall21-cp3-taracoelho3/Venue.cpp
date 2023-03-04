#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include "Venue.h"

using namespace std;

Venue::Venue() : acts(){
    name = "";
    location = "";
    capacity = 0;
    counter = 0;
    numActs = 0;
 
}

Venue::Venue(string name, int capacity, string location ) : acts() {

    this->name = name;
    this->location = location;
    this->capacity = capacity;
    this->counter = 0;
    this->numActs = 0;

}

Venue::Venue(const Venue &v) : acts(){
    acts = v.acts;
    name = v.name;
    location = v.location;
    capacity = v.capacity;
    counter = v.counter; 
}

void Venue::print(){
    cout << this->name << " " << this->location << " " << this->capacity  << endl;
}

bool flag = false;
bool Venue::checkOverlap(Activity a, string activityfile, int line){
    bool result = false;
    bool flag = false;
    for(int i = 1; i < numActs; i++){
        result = acts.returnAt(i).checkOverlap(a, activityfile, line);
        if(result == 1){
            flag = true;
        }
    }
    return flag;
}

void Venue::add(Activity a){
    acts.add(a);
    numActs++;
}

void Venue::displayActs(){
    acts.display();
}

bool Venue::searchAct(Activity a){
    
   bool result = acts.search(a);
   if(result == 1){
       flag = true;
   }

    return flag;
}

Activity& Venue::searchReturnAct(Activity &a){
    int i = acts.searchAndReturnIndex(a);
  
    if(i == 0){
        return a;
    }
    else{
        return acts.returnAt(i);
    }
}

void Venue::addAttendee(){
    counter++;
}

int Venue::getAttendance(){
    return counter;
}

string Venue::getName(){
     return name;
}

int Venue::getCapacity(){
    return capacity;
}

Venue& Venue::operator=(const Venue &v){
    this->acts = v.acts;
    this->name = v.name;
    this->location = v.location;
    this->capacity = v.capacity;
    this->counter = v.counter; 
    return *this;
}

bool Venue::operator==(const Venue &v){
    if(this->name == v.name){
        return true;
    }
    else{
        return false;
    }
}

Venue& Venue::operator*(){
    return *this;
} 

ostream& operator <<(ostream &r, const Venue &v){
    r << v.name << " " << v.location << " " << v.capacity << " " << v.counter << endl;
    return r;
}

Venue::~Venue(){

}




