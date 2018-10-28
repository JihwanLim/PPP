/*
	CHAPTER 5 - ERRORS
	Exercise 4
*/

#include "std_lib_facilities.h"

const double absolute_zero = -273.15;

double ctok(double c)
{
	if (c < absolute_zero)
		error("Cannot enter a number lower than absolute zero(-273.15).");
	return c - absolute_zero;
}

int main() try
{
	double c = 0.;
	cin >> c;

	if (!cin)
		error("Cannot enter a non-double value.");

	double k = ctok(c);
	cout << k << '\n';

	return 0;
}
catch (exception& e)
{
	cout << "Error: " << e.what() << '\n';
}
catch (...)
{
	cout << "Error: Something went wrong.\n";
}
