
#include "std_lib_facilities.h"

const int not_a_reading = -7777;	// less than absolute zero
const int not_a_month = -1;

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

vector<string> month_input_tb1 = {
	"jan", "feb", "mar", "apr", "may", "jun",
	"jul", "aug", "sep", "oct", "nov", "dec"
};

vector<string> month_print_tb1 = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

struct Day {
	vector<double> hour{ vector<double>(24, not_a_reading) };
};

struct Month {					// a month of temperature readings
	int month{ not_a_month };	// [0:11] Junuary is 0
	vector<Day> day{ 32 };		// [1:31] one vector of readings per day
	// We "waste" day[0] to keep the code simple
};

struct Year {					// a year of temperature readings, organized by month
	int year;					// positive == A.D.
	vector<Month> month{ 12 };	// [0:11] January is 0
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format: ( 3 4 9.7)
// check format, but don't bother with data validity
{
	char ch1;

	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;

	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') error("bad reading");	// messed-up reading
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail()) {	// use term as terminator and/or separator
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;	// all is fine
		error(message);
	}
}

bool is_valid(const Reading& r)
// a rough test
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature)
		return false;
	return true;
}

int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise -1
{
	for (int i = 0; i < 12; ++i) if (month_input_tb1[i] == s) return i;
	return -1;
}

string int_to_month(int i)
// months [0:11]
{
	if (i < 0 || 12 <= i) error("bad month index");
	return month_print_tb1[i];
}

istream& operator>>(istream& is, Month& m)
// read a month from is into m
// format: { month feb ... }
{
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month") error("bad start of month");
	m.month = month_to_int(mm);
	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r; ) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else {
			++invalids;
		}
	}
	if (invalids) error("invalid readings in month", invalids);
	if (duplicates) error("duplicates readings in month", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 ... }
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string year_marker;
	int yy;

	is >> year_marker >> yy;
	if (!is || year_marker != "year") error("bad start of year");
	y.year = yy;
	while (true) {
		Month m;	// get a clean m each time around
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}

void print_year(ofstream& os, Year& y)
{
	for (int i = 0; i < y)
}

int main() try
{
	// get input and output file names:
	string iofname{ "c:/iofilenames.txt" };
	ifstream iofs{ iofname };
	if (!iofs) error("can't open input file", iofname);
	string iname;
	string oname;
	iofs >> iname >> oname;

	// open an input file:
	ifstream ist{ iname };
	if (!ist) error("can't open input file", iname);

	ist.exceptions(ist.exceptions() | ios_base::badbit);	// throw for bad()

	// open an output file:
	ofstream ost{ oname };
	if (!ost) error("can't open output file", oname);

	// read an arbitrary number of years:
	vector<Year> ys;
	while (true) {
		Year y;		// get a freshly initialized Year each time around
		if (!(ist >> y)) break;
		ys.push_back(y);
	}
	cout << "read " << ys.size() << " years of readings\n";

	for (Year& y : ys) print_year(ost, y);

	return 0;
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}

