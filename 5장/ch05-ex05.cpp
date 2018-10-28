/*
	CHAPTER 5 - ERRORS
	Exercise 5
*/

#include "std_lib_facilities.h"

const double absolute_zero = -273.15;

double ctok(double c)
{
	if (c < absolute_zero)
		error("Cannot enter a number lower than absolute zero(-273.15กษ).");
	return c - absolute_zero;
}

double ktoc(double k)
{
	if (k < 0)
		error("Cannot enter a number lower than absolute zero(0K)");
	return k + absolute_zero;
}

int main() try
{
	double k = 0.;
	cin >> k;

	if (!cin)
		error("Cannot enter a non-double value.");

	double c = ktoc(k);
	cout << c << '\n';

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
