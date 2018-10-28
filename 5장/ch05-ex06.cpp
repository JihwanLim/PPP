/*
	CHAPTER 5 - ERRORS
	Exercise 6
*/

#include "std_lib_facilities.h"

double ctof(double c)
{
	return c * 1.8 + 32;
}

double ftoc(double f)
{
	return (f - 32) / 1.8;
}

int main() try
{
	double n = 0.;
	while (cin >> n) {
		cout << n << "¡É --> " << ctof(n) << "¢µ\n";
		cout << n << "¢µ --> " << ftoc(n) << "¡É\n";
	}
	if (!cin)
		error("You should enter only double values.");

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
