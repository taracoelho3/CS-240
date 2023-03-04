#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
#include "Occurrence.h"
#endif

class Activity{

	public:
		Activity();
		Activity(string title, string creator, Occurrence start, Occurrence end, string venue, char exclusive);
		Activity(const Activity &currUser);
		void print();
		void addAttendee();
		int getAttendance();
		string getTitle();
		string getCreator();
		int getStartTime();
		string getStartDate();
		int getEndTime();
		string getEndDate();
		string getVenue();
		bool getExclusive();
		bool checkOverlap(Activity a, string activityfile, int line);
		bool checkOverlapAttendance(Activity a, string user, string attendancefile, int line);
		Activity& operator=(const Activity &currUser);
		bool operator==(const Activity &a);
		friend ostream& operator<<(ostream &r, const Activity &a);
		bool operator&&(const Activity &a);
		Activity& operator*();
		~Activity();
	

	private:
		string title1;
		string creator1;
		Occurrence start;
		Occurrence end;
		string venue1;
		char exclusive1;
		int attendance;
		
};