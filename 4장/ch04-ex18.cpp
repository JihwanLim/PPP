/*
	CHAPTER 4 - COMPUTATION
	Exercise 18
*/

#include "std_lib_facilities.h"

int main()
{
	double a = 0.;
	double b = 0.;
	double c = 0.;
	cout << "Enter a, b, and c\n";
	cin >> a >> b >> c;

	const double D = b*b - 4*a*c;

	if (D < 0) {
		cout << "There are no solutions\n";
	}
	else {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		cout << "x1: " << x1 << '\n';
		cout << "x2: " << x2 << '\n';
	}
	return 0;
}
