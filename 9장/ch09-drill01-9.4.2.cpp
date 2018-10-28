
#include "std_lib_facilities.h"

/*
	This drill simply involves getting the sequence of versions of Date to work. For
	each version define a Date called today initialized to June 25, 1978. Then, define a
	Date called tomorrow and give it a value by copying today into it and increasing
	its day by one using add_day(). Finally, output today and tomorrow using a <<
	defined as in §9.8.
	Your check for a valid date may be very simple. Feel free to ignore leap years.
	However, don’t accept a month that is not in the [1,12] range or day of the month
	that is not in the [1,31] range. Test each version with at least one invalid date (e.g.,
	2004, 13, –5).
*/

bool is_valid_date(int yy, int mm, int dd)
{
	if (mm == 2 && dd > 28) return false;
	else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) return false;
	else if (dd > 31) return false;
	return true;
}

// simple Date (too simple?)
struct Date {
	int y;	// year
	int m;	// month in year
	int d;	// day of month

	Date(int yy, int mm, int dd) 
	{
		if (!is_valid_date(yy, mm, dd))	error("invalid date");
		y = yy;
		m = mm;
		d = dd;
	}	

	void add_day()
	{
		if (m == 2 && d == 28) {
			++m;
			d = 1;
		}
		else if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 30) {
			++m;
			d = 1;
		}
		else {
			if (d == 31) {
				++m;
				d = 1;
			}
			else
				++d;
		}
	}
};

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << '-' << d.m << '-' << d.d << ')';
}

int main()
{
	Date today{ 1978, 1, 2 };
	Date tomorrow = today;
	tomorrow.add_day();

	cout << today << endl;
	cout << tomorrow << endl;
	return 0;
}

