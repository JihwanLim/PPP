/*
	CHAPTER 4 - COMPUTATION
	Exercise 7
*/

#include "std_lib_facilities.h"

int main()
{
	string temp1[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string temp2[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	vector<string> arabic_nums(temp1, temp1 + sizeof(temp1) / sizeof(string));
	vector<string> spelled_nums(temp2, temp2 + sizeof(temp2) / sizeof(string));

	string s_n1 = "", s_n2 = "";
	char op = ' ';
	double d_n1 = 0.0, d_n2 = 0.0;
	bool is_n1_valid = false;
	bool is_n2_valid = false;

	cout << "Enter two numbers and an operator(+, -, * or /): ";

	while (cin >> s_n1 >> s_n2 >> op) {
		is_n1_valid = false;
		is_n2_valid = false;

		for (int i = 0; i < arabic_nums.size(); ++i) {
			if (s_n1 == arabic_nums[i] || s_n1 == spelled_nums[i]) {
				d_n1 = i;
				is_n1_valid = true;
			}
			if (s_n2 == arabic_nums[i] || s_n2 == spelled_nums[i]) {
				d_n2 = i;
				is_n2_valid = true;
			}
		}

		if (is_n1_valid && is_n2_valid) {
			switch (op) {
			case '+':
				cout << "The sum of " << d_n1 << " and " << d_n2 << " is " << d_n1 + d_n2 << ".\n";
				break;
			case '-':
				cout << "The difference of " << d_n1 << " and " << d_n2 << " is " << d_n1 - d_n2 << ".\n";
				break;
			case '*':
				cout << "The product of " << d_n1 << " and " << d_n2 << " is " << d_n1 * d_n2 << ".\n";
				break;
			case '/':
				cout << "The ratio of " << d_n1 << " and " << d_n2 << " is " << d_n1 / d_n2 << ".\n";
				break;
			default:
				cout << "I don't know the operator. Please try again and use '+', '-', '*' or '/'.\n";
			}
		}
	}

	return 0;
}
