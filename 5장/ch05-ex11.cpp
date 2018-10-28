/*
	CHAPTER 5 - ERRORS
	Exercise 11
*/

#include "std_lib_facilities.h"

int main() try
{
	int prev1 = 1;
	int prev2 = 1;
	int curr = prev1 + prev2;

	while (true) {
		prev1 = prev2;
		prev2 = curr;
		curr = prev1 + prev2;
		if (curr < 0)
			error("Buffer overflow");
		cout << curr << '\n';
	}

	return 0;
}
catch (exception& e)
{
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...)
{
	cerr << "Unknown exception\n";
	keep_window_open();
	return 2;
}