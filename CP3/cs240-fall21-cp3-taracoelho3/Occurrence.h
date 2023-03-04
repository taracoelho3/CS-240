#ifndef OCCURRENCE_H
#define OCCURRENCE_H
#include <stdlib.h>
#include <string>
using namespace std;
#endif

class Occurrence{
    
    public:
        Occurrence();
        Occurrence(string time, string date);
        Occurrence(const Occurrence &o);
        string getString();
        bool sameDate(Occurrence o);
        Occurrence& operator=(const Occurrence &o);
        friend ostream& operator<<(ostream &r, const Occurrence &o);
        string getDate();
        int getTime();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        int getDay();
        int getMonth();
        int getYear();
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);
        int getHours();
        int getMinutes();
        int getSeconds();
 
    
    private:
        int hours, minutes, seconds, day, month, year, timeTotal;
        string time, date;
};
