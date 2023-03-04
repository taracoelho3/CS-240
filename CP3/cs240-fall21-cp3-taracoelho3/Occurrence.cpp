#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;
#include "Occurrence.h"


Occurrence::Occurrence(){
    time = "";
    date = "";
    hours = 0;
	minutes = 0;
	seconds = 0;
	day = 0;
	month = 0;
	year = 0;
	timeTotal = 0;
}

Occurrence::Occurrence(string time, string date){

	this->time = time;
	this->date = date;
	this->hours = std::stoi(time.substr(0, 2));
	this->minutes = std::stoi(time.substr(3, 2));
	this->seconds = std::stoi(time.substr(6, 2));

	this->day = std::stoi(date.substr(0, 2));
	this->month = std::stoi(date.substr(3, 2));
	this->year = std::stoi(date.substr(6, 4));

	int Hours = hours * 3600;
	int Minutes = minutes * 60;
	int Seconds = seconds;

	this->timeTotal = Hours + Minutes + Seconds;
    
}
Occurrence::Occurrence( const Occurrence &o){
	hours = o.hours;
	minutes = o.minutes;
	seconds = o.seconds;
	day = o.day;
	month = o.month;
	year = o.year;
	time = o.time;
	date = o.date;
	timeTotal = o.timeTotal;

}

bool Occurrence::sameDate(Occurrence o){
	if(this->day == o.getDay() && this->month == o.getMonth() && this->year == o.getYear()){
		return true;
	}
	else{
		return false;
	}
}

string Occurrence::getString(){
	string dateTime = date + "   " + time;
    return dateTime;
}

Occurrence& Occurrence::operator=( const Occurrence &o){
	this->hours = o.hours;
	this->minutes = o.minutes;
	this->seconds = o.seconds;
	this->day = o.day;
	this->month = o.month;
	this->year = o.year;
	this->time = o.time;
	this->date = o.date;
	this->timeTotal = o.timeTotal;

	return *this;
}

ostream& operator <<(ostream &r, const Occurrence &o){
    r << o.time << " " << o.date << endl;
    return r;
}

string Occurrence::getDate(){
    return date;
}

int Occurrence::getTime(){
    return timeTotal;
}

void Occurrence::setMonth(int month){
	month = month;
}

void Occurrence::setYear(int year){
	year = year;
}
void Occurrence::setDay(int day){
	day = day;
}
int Occurrence::getMonth(){
	return month;
}
int Occurrence::getYear(){
	return year;
}
int Occurrence::getDay(){
	return day;
}

void Occurrence::setHours(int hours){
	hours = hours;
}
void Occurrence::setMinutes(int minutes){
	minutes = minutes;
}
void Occurrence::setSeconds(int seconds){
	seconds = seconds;
}
int Occurrence::getHours(){
	return hours;
}
int Occurrence::getMinutes(){
	return minutes;
}
int Occurrence::getSeconds(){
	return seconds;
}

