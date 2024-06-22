#pragma once
#include <iostream>

using std::cout;
using std::endl;

short int check(short int value, short int current, short int valid);

const int months[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class Date
{
	short int day, month, year;

public:
	Date(short int day_, short int month_);
	Date(short int day_, short int month_, short int year_);

	short int get_day() const;
	void set_day(short int value);

	short int get_month() const;
	void set_month(short int value);

	short int get_year() const;
	void set_year(short int value);


	int days() const;
	static bool is_leap(short int year);
	static Date today();
	int operator-(const Date& other) const;
	Date& operator+=(int daysToAdd);
	int suma() const;
	friend std::ostream& operator<<(std::ostream& out, const Date& c);
	friend std::istream& operator>>(std::istream& in, Date& c);
};

