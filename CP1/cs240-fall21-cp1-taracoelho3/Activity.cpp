#include <stdlib.h>
#include <stdio.h>
#include <ostream>
using namespace std;
#include "Activity.h"


Activity::Activity(){
	string title1 = "";
	string creator1 = "";
	string startTime1 = "";
	string endTime1 = "";
	string startDate1 = "";
	string endDate1 = "";
	string venue1 = "";
	bool exclusive1 = false;
}
Activity::Activity(string title, string creator, string startTime, string endTime, string startDate, string endDate, string venue, bool exclusive){
	title1 = title;
	creator1 = creator;
	startTime1 = startTime;
	endTime1 = endTime;
	startDate1 = startDate;
	endDate1 = endDate;
    venue1 = venue;
	exclusive1 = exclusive;
   
	
}

void Activity::print(){
	cout << "Title: " << title1;
	cout << "  Creator: " << creator1;
	cout << "  Begin Date and Time [ "<<  startDate1 << " " << startTime1 << "]";
	cout << "  End Date and Time [ " << endDate1 << " " << endTime1 << "]";
	cout << "  Venue: " << venue1;
	if(exclusive1 == 1){
		cout <<"  (is exclusive)";
	}
	if(exclusive1 == 0){
		cout <<"  (not exclusive)";
	}
	cout << endl;

	return;
}





