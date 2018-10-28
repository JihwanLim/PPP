
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

// simple Date (too simple?)
struct Date {
	int y;	// year
	int m;	// month in year
	int d;	// day of month
};

void add_day(Date& d)
{
	if (d.m == 2 && d.d == 28) {
		++d.m;
		d.d = 1;
	}
	else if ((d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11) && d.d == 30) {
		++d.m;
		d.d = 1;
	}
	else {
		if (d.d == 31) {
			++d.m;
			d.d = 1;
		}
		else
			++d.d;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << '-' << d.m << '-' << d.d << ')';
}

bool is_valid_date(const Date& d)
{
	if (d.m == 2 && d.d > 28) return false;
	else if ((d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11) && d.d > 30) return false;
	else if (d.d > 31) return false;
	return true;
}

int main()
{
	Date today{ 1978, 1, 31 };
	Date tomorrow = today;

	add_day(tomorrow);
	 
	if (!is_valid_date(today)) return -1;
	cout << today << endl;

	if (!is_valid_date(tomorrow)) return -1;
	cout << tomorrow << endl;
	return 0;
}

