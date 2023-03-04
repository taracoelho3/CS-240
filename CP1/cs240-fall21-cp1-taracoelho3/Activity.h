#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
//#include "Occurrence.h"
#endif

class Activity{

	public:
		Activity();
		Activity(string title, string creator, string startTime, string endTime, string startDate, string endDate, string venue, bool exclusive);
		//void setValues(string title, string creator, string startTime, string endTime, string startDate, string endDate, string venue, bool exclusive);
		void print();
	

	private:
		string title1;
		string creator1;
		string startTime1;
		string endTime1;
		string startDate1;
		string endDate1;
		string venue1;
		bool exclusive1;
		
};




