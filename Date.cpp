#include "Date.h"

#include <iomanip>


short int check(short int value, short int current, short int valid) {
	if (value > 0 && value <=valid) {
		return value;
	}
	cout << "Wartosc musi byc wieksza od 0 i mniejsza od " << valid << endl;
	return current;
}


Date::Date(short int day_, short int month_) :
	day{ day_ }, month{ month_ }, year{0} {}

Date::Date(short int day_, short int month_, short int year_) :
	day{day_}, month{month_}, year{year_} {}
short int Date::get_day() const {
	return day;
}
void Date::set_day(short int value) {
	day = check(value,day,31);
}

short int Date::get_month() const {
	return month;
}
void Date::set_month(short int value) {
	month = check(value, month, 12);
}

short int Date::get_year() const {
	return year;
}
void Date::set_year(short int value) {
	year = check(value,year,32000);
}
int Date::days() const { //dni od poczatku roku
	int sum = day;
	for (short int j = 0; j < month; j++) {
		sum += months[j];
	}

	if (is_leap(year)) {
		sum++;
	}
	return sum;
}

int Date::suma() const{
	int sum = days();
	for (short int i = 1; i < year; i++) {
		if (is_leap(i)) {
			sum += 366;
		}
		else {
			sum += 365;
		}
	}
	return sum;
}





bool Date::is_leap(short int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	if (year % 400 == 0) {
		return true;
		
	}
	return false;
}
std::ostream& operator<<(std::ostream& out, const Date& c) {
	cout << c.day << "/" << c.month%12 << "/" << c.year << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Date& c) {
	in >> c.day >> c.month >> c.year;
	return in;
}
Date Date:: today() {
	std::time_t now = std::time(0);
	std::tm localt;
	localtime_s(&localt,&now);
	short int tday = localt.tm_mday;
	short int tmonth = localt.tm_mon;
	short int tyear = 1900 + localt.tm_year;
	return Date(tday, tmonth, tyear);
}
int Date::operator-(const Date& other) const {
	return std::abs(this->suma() - other.suma()+1);
}
Date& Date::operator+=(int daysToAdd) {
    while (daysToAdd > 0) {
        short int daysInMonth = months[month - 1];
        if (month == 2 && is_leap(year)) {
            daysInMonth = 29;
        }

        if (day + daysToAdd <= daysInMonth) {
            day += daysToAdd;
            break;
        } else {
            daysToAdd -= (daysInMonth - day + 1);
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            } else {
                month++;
            }
        }
    }
    return *this;
}