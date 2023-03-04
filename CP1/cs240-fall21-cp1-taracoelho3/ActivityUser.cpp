#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;
#include "Activity.h"



int main(){

	string input, choice, title, creator, startDate, startTime, endDate, endTime, venue;
	vector<Activity*> activityList;
	string userInput;
	bool exclusive;

	while(userInput != "Quit"){

	cout <<"Type \"Create\" to create and store a new activity to the" 
	<<" collection" << endl;
	cout << "Type \"Display\" to show all activities in the collection"<< endl;
	cout<< "Type \"Quit\" to end the program" << endl;

	cin >> userInput;

	if(userInput != "Create"){
		if(userInput != "Display"){
			if(userInput != "Quit"){
				cout << "--------Please enter another choice--------" << endl;
			 }
		}
	
	}

	

	if(userInput == "Display"){
		cout << "-----Displaying current Activity List-----" << endl;
		cout << "Activities: " << activityList.size() << endl;
		if(activityList.size() != 0){
			for(int i = 0; i < activityList.size(); i++){
				activityList.at(i)->print();
			}
		cout << "-----All activities currently displayed-----" << endl;
		}else{
			cout << "-----There are no activities to display-----" << endl;
		}
	
	}

	if(userInput == "Create"){
		cout << "Please enter a title." << endl;
		cin >> title;
		cout << "Please enter a creator." << endl;
		cin >> creator;
		cout << "Please enter a start time in the format HH:MM:SS ." << endl;
		cin >> startTime;
		cout << "Please enter an end time in the format HH:MM:SS ." << endl;
		cin >> endTime;
		cout << "Please enter a start date in the format DD-MM-YYYY ." << endl;
		cin >> startDate;
		cout << "Please enter a start date in the format DD-MM-YYYY ." << endl;
		cin >> endDate;
		cout << "Please enter a venue." << endl;
		cin >> venue;
		cout << "Please enter if this event is exclusive (yes, type 1, no type 0)" << endl;
		cin >> exclusive;

		Activity *actUser = new Activity(title, creator, startTime, endTime, startDate, endDate, venue, exclusive);
		activityList.push_back(actUser);

		cout << "-----Activity created-----" << endl;	
	}
	
	if(userInput == "Quit"){
		cout << "Exiting..." << endl;
		break;
	}


	}

return 0;
	
}
