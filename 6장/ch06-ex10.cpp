#include "std_lib_facilities.h"

/*
	CHAPTER 6 - WRITING A PROGRAM
	Exercise 10

	<designing this program simply>
	first, input two numbers (no any other type)
	second, if not entered only two numbers, print a prompt to re-enter, and do it
	third, then select permutation(1) or combination(2)
		if entered any numbers except 1 and 2, print a prompt to re-enter, and do it
	fourth, print a result of permutation or combination
*/

long factorial(int n)
{
	int c;
	long result = 1;

	for (c = 1; c <= n; c++)
		result = result * c;

	return result;
}

double P(double a, double b)
{
	double dividend = factorial(a - b);
	if (dividend == 0)
		error("divide by zero");
	return factorial(a) / dividend;
}

double C(double a, double b)
{
	double dividend = factorial(b);
	if (dividend == 0)
		error("divide by zero");
	return P(a, b) / dividend;
}

int main() try
{
	int a, b;

	cout << "Enter two numbers: ";
	while (true)
	{
		cin >> a >> b;
		if (cin)
			break;
		else {
			cerr << "Your input's gone wrong. Please try to enter only two numbers.\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	int selection;
	cout << "Select permutation(1) or combination(2) by entering a number.\n";
	while (true)
	{
		cin >> selection;
		if (selection == 1 || selection == 2)
			break;
		else {
			cerr << "Your input's gone wrong. Please try to enter only 1 or 2.\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	cout << "Result: ";
	if (selection == 1)
		cout << P(a, b) << " (permutation)\n";
	else
		cout << C(a, b) << " (combination)\n";

	keep_window_open();
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
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 10;
}