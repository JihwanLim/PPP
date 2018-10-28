/*
	CHAPTER 5 - ERRORS
	Exercise 8
*/

#include "std_lib_facilities.h"

int main() try
{
	cout << "Please enter the number of values you want to sum\n";
	int n = 0;
	cin >> n;

	if (!cin)
		error("Incorrect input, only integer values");
	if (n <= 0)
		error("You should enter a number more than 0");

	cout << "Please enter some integers (press '|' to stop)\n";
	vector<int> v;
	for (int input = 0; cin >> input; ) {
		v.push_back(input);
	}

	int sum = 0;
	cout << "The sum of the first " << n << " number";
	if (n > 1) cout << 's';	// plural form
	cout << " ( ";
	for (int i = 0; i < n; ++i) {
		sum += v[i];
		cout << v[i] << ' ';
	}
	cout << ") is " << sum << ".\n";

	return 0;
}
catch (out_of_range& e)
{
	cerr << '\n' << e.what() << '\n';
	cin.clear();
	cin.ignore(256, '\n');
	keep_window_open();
	return 1;
}
catch (exception& e)
{
	cerr << "Error: " << e.what() << '\n';
	cin.clear();
	cin.ignore(256, '\n');
	keep_window_open();
	return 2;
}
catch (...)
{
	cerr << "Unknown exception\n";
	cin.clear();
	cin.ignore(256, '\n');
	keep_window_open();
	return 3;
}