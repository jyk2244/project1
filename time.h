#ifndef _DATE_H
#define _DATE_H
#include <string>

class date{
	protected:
		int year;
		int month;
		int day;

	public:
		date();
		date(int year, int month, int day);
		date(std::string d);
		date operator+(const int& n);
		int operator-(const date &d);
		void operator=(const date& d);
		std::string getDate();
};

class h_date : public date{
	private:
		int hour;

	public:
		h_date(std::string);
		int getHour();
};

#endif
