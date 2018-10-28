/*
	CHAPTER 5 - ERRORS
	Exercise 7
*/

#include "std_lib_facilities.h"

void show_root(double a, double b, double c)
{
	if (a == 0) {
		if (b == 0)
			error("There are no solutions.");

		// just to prevent showing -0
		double result = -c / b;
		if (result == -0)
			result = -result;

		cout << "x: " << result << '\n';
	}
	else {
		// calculates a discriminant
		const double D = b*b - 4*a*c;

		if (D < 0) {
			error("There are no solutions.");
		}
		else if (D > 0) {
			double x1 = (-b + sqrt(D)) / (2 * a);
			double x2 = (-b - sqrt(D)) / (2 * a);
			cout << "x1: " << x1 << '\n';
			cout << "x2: " << x2 << '\n';
		}
		else if (D == 0) {
			double x = (-b + sqrt(D)) / (2 - a);
			cout << "x: " << x << '\n';
		}
	}
}

int main() try
{
	cout << "Enter coefficients for quadratic equation a*x^2 + b*x + c = 0\n";
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	
	if (!cin) error("You should enter only integer values.");
	
	show_root(a, b, c);

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
	cerr << "Unknown error\n";
	keep_window_open();
	return 2;
}