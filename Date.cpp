#include <iostream>
#include <stdio.h>
using namespace std;

class Date {
public:
  Date(int y, int m, int d);
  ~Date();
	
  int max();
  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};

Date::Date(int y, int m, int d):year(y),month(m),day(d){
}

Date::~Date(){
}

int Date::max(){
	if(month==2){
		if(year%4==0&&year%100!=0||year%400==0){
			return 29;
		}
		else 
			return 28;
	}
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		return 31;
	if(month==4||month==6||month==9||month==11)
		return 30;
}

void Date::nextDay(){
	if(day<max()){
		day++;
		return;
	}
	if(day=max()){
		if(month<12){
			month++;
			day=1;
		}
		else{
			month=1;
			year++;
			day=1;
		}
		return;
	}
}

void Date::previousDay(){
	if(day==1){
		if(month==1){
			year--;
			month=12;
			day=31;
		}
		else{
			month--;
			day=max();
		}
		return;
	}
	day--;
	return;
}

void Date::show(){
	cout<<year<<","<<month<<","<<day<<endl;
}

bool Date::equal(Date other){
	if(other.year==this->year&&other.month==this->month&&other.day==this->day){
		return true;
	}
	return false;
}

int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(int i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
