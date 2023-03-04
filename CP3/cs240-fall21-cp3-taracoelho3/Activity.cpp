#include <stdlib.h>
#include <stdio.h>
#include <ostream>
#include <fstream>
using namespace std;
#include "Activity.h"


Activity::Activity(){
	string title1 = "";
	string creator1 = "";
	Occurrence start;
	Occurrence end;
	string venue1 = "";
	char exclusive1 = 'n';
	attendance = 0;

}
Activity::Activity(string title, string creator, Occurrence start, Occurrence end, string venue, char exclusive){
	title1 = title;
	creator1 = creator;
	this->start = start;
	this->end = end;
    venue1 = venue;
	exclusive1 = exclusive;
	attendance = 0;  
	
}

Activity::Activity( const Activity &currUser){
	title1 = currUser.title1;
	creator1 = currUser.creator1;
	start = currUser.start;
	end = currUser.end;
	venue1 = currUser.venue1;
	exclusive1 = currUser.exclusive1;
	attendance = currUser.attendance;
}

string Activity::getTitle(){
	return title1;
}

string Activity::getCreator(){
	return creator1;
}

int Activity::getStartTime(){
	return start.getTime();
}

string Activity::getStartDate(){
	return start.getDate();
}

int Activity::getEndTime(){
	return end.getTime();
}

string Activity::getEndDate(){
	return end.getDate();
}

string Activity::getVenue(){
	return venue1;
}

bool Activity::getExclusive(){
	if(exclusive1 == 'n'){
		return false;
	}
	else{
		return true;
	}
}

int Activity::getAttendance(){
	return attendance;
}

void Activity::addAttendee(){
	attendance++;
}


void Activity::print(){
	cout << "Title: " << title1;
	cout << "  Creator: " << creator1;
	cout << "  Begin Date and Time [ "<<  start.getString() << "]";
	cout << "  End Date and Time [ " << end.getTime() << "]";
	cout << "  Venue: " << venue1;
	if(exclusive1 == 1){
		cout <<"  (is exclusive)";
	}
	if(exclusive1 == 0){
		cout <<"  (not exclusive)";
	}
	cout << endl;

}

bool Activity::checkOverlap(Activity a, string activityfile, int line){
	bool flag = false;
	if(this->getVenue() == a.getVenue()){
	if(a.getStartTime() >= this->getStartTime() && a.getStartTime() <= this->getEndTime() && a.getEndTime() >= 
		this->getStartTime() && this->start.sameDate(a.start) == true){
			if(this->getExclusive() == true || a.getExclusive() == true || (this->getExclusive() == true && a.getExclusive() == true)){
				cout << "Activity file " << activityfile << " line " << line << ": Activity " << a.getTitle() << 
              " would conflict with " << this->getTitle() << "- ignoring" << endl;
				flag = true;
			
			}
	}
			else if(a.getStartTime() <= this->getStartTime() && (a.getEndTime() >= this->getEndTime() || a.getEndTime() >=
				this->getStartTime())  && this->start.sameDate(a.start) == true){
					if(this->getExclusive() == true || a.getExclusive() == true || (this->getExclusive() == true && a.getExclusive() == true)){
						cout << "Activity file " << activityfile << " line " << line << ": Activity " << a.getTitle() << 
             			 " would conflict with " << this->getTitle() << "- ignoring" << endl;
			
						flag = true;
				}
			}
	}

	return flag;
}

bool Activity::checkOverlapAttendance(Activity a, string user, string attendancefile, int line){
	bool result = false;

	if(this->getVenue() == a.getVenue()){
		if( this->start.sameDate(a.start) == true){
	 		if(a.getStartTime() >= this->getStartTime() && a.getStartTime() <= this->getEndTime() && a.getEndTime() >= 
		 	   this->getStartTime()){
					cout << "Attendance file " << attendancefile << " line " << line << ": user " << user << 
              			" is busy with " << this->getTitle()<< " - ignoring" << endl;
					result = true;
				}
			
			else if(a.getStartTime() <= this->getStartTime() && (a.getEndTime() >= this->getEndTime() || a.getEndTime() >=
				this->getStartTime())){
					cout << "Attendance file " << attendancefile << " line " << line << ": user " << user << 
              			" is busy with " << this->getTitle()<< " - ignoring" << endl;
					result = true;
				}
			}
		
	}
   
	return result;
}


Activity& Activity::operator=( const Activity &currUser){
	this->title1 = currUser.title1;
	this->creator1 = currUser.creator1;
	this->start = currUser.start;
	this->end = currUser.end;
	this->venue1 = currUser.venue1;
	this->exclusive1 = currUser.exclusive1;
	this->attendance = currUser.attendance;
	return *this;
}

bool Activity::operator==(const Activity &a){
    if(this->title1 == a.title1){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator <<(ostream &r, const Activity &a){
    r << a.title1 << " " << a.creator1 << " " << a.start << " " << a.end << " " << a.venue1 << " " << a.exclusive1 << " " << endl;
    return r;
}

Activity& Activity::operator*(){
	return *this;
}

Activity::~Activity(){
	
}





