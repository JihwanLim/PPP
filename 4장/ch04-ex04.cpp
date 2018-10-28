/*
	CHAPTER 4 - COMPUTATION
	Exercise 4
*/

#include "std_lib_facilities.h"

int main()
{
	int min = 1;
	int max = 100;
	int avg = (min + max - 1) / 2;
	char ans = ' ';

	while (1) {
		cout << "Is the number you thought " << avg << "? (y or n): ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			cout << "I did it!\n";
			break;
		}
		else if (ans == 'n' || ans == 'N') {
			cout << "Up? or down? compared with " << avg << " (u or d): ";
			while (cin >> ans) {
				if (ans == 'u' || ans == 'U') {
					min = avg;
					break;
				}
				else if (ans == 'd' || ans == 'D') {
					max = avg;
					break;
				}
				else
					cout << "You've entered an incorrect character. Please enter 'u' or 'd': ";
			}
			avg = (min + max - 1) / 2;
		}
	}

	return 0;
}
