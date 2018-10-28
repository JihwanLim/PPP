/*
	CHAPTER 4 - COMPUTATION
	Exercise 5
*/

#include "std_lib_facilities.h"

int main()
{
	double n1 = 0.0, n2 = 0.0;
	char op = ' ';

	cout << "Enter two numbers and an operator(+, -, * or /): ";

	while (cin >> n1 >> n2 >> op) {
		switch (op) {
		case '+':
			cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << ".\n";
			break;
		case '-':
			cout << "The difference of " << n1 << " and " << n2 << " is " << n1 - n2 << ".\n";
			break;
		case '*':
			cout << "The product of " << n1 << " and " << n2 << " is " << n1 * n2 << ".\n";
			break;
		case '/':
			cout << "The ratio of " << n1 << " and " << n2 << " is " << n1 / n2 << ".\n";
			break;
		default:
			cout << "I don't know the operator. Please try again and use '+', '-', '*' or '/'.\n";
		}
	}

	return 0;
}
