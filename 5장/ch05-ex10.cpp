/*
	CHAPTER 5 - ERRORS
	Exercise 10
*/

#include "std_lib_facilities.h"

void new_keep_window_open()
{
	cin.clear();
	cin.ignore(256, '\n');
	keep_window_open();
}

int main() try
{
	/* input data */
	cout << "Please enter the number of values you want to sum\n";
	int n = 0;
	cin >> n;

	if (!cin)
		error("Incorrect input, only integer values");
	if (n <= 0)
		error("You should enter a number more than 0");

	cout << "Please enter some integers (press '|' to stop)\n";
	vector<double> v1;
	for (double input = 0; cin >> input; ) {
		v1.push_back(input);
	}

	/* print v1 vector that has user-inputted data */
	double sum = 0;
	cout << "The sum of the first " << n << " number";
	if (n > 1) cout << 's';	// plural form
	cout << " ( ";
	for (int i = 0; i < n; ++i) {
		sum += v1[i];
		cout << v1[i] << ' ';
	}
	cout << ") is " << sum << ".\n";

	/* write out */
	vector<double> v2;
	int diff = 0;
	for (int i = 0; i < v1.size() - 1; ++i) {
		if (v1[i] != v1[i + 1]) {
			diff = v1[i] - v1[i + 1];
			if (diff < 0)
				diff = -diff;
			v2.push_back(diff);
		}
	}
	
	/* print v2 vector that has differences between adjacent values of v1 */
	for (int i = 0; i < v2.size(); ++i)
		cout << v2[i] << ' ';
	cout << '\n';

	new_keep_window_open();
	return 0;
}
catch (out_of_range& e)
{
	cerr << '\n' << e.what() << '\n';
	new_keep_window_open();
	return 1;
}
catch (exception& e)
{
	cerr << "Error: " << e.what() << '\n';
	new_keep_window_open();
	return 2;
}
catch (...)
{
	cerr << "Unknown exception\n";
	new_keep_window_open();
	return 3;
}