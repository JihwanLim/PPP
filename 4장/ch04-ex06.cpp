/*
	CHAPTER 4 - COMPUTATION	
	Exercise 6
*/

#include "std_lib_facilities.h"

int main()
{
	string t1[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string t2[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	vector<string> spelled_nums(t1, t1 + sizeof(t1) / sizeof(string));
	vector<string> arabian_nums(t2, t2 + sizeof(t2) / sizeof(string));

	cout << "Enter a digit\n";

	for (string input; cin >> input; ) {
		for (int i = 0; i < spelled_nums.size(); ++i) {
			if (input == spelled_nums[i])
				cout << arabian_nums[i] << '\n';
			if (input == arabian_nums[i])
				cout << spelled_nums[i] << '\n';
		}
	}

	return 0;
}
