/*
	CHAPTER 4 - COMPUTATION
	Exercise 19
*/

#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> numbers;
	string name_input = "";
	int number_input = 0;

	while (cin >> name_input >> number_input) {
		names.push_back(name_input);
		numbers.push_back(number_input);
		for (int i = 0; i < names.size() - 1; ++i) {
			if (names[names.size() - 1] == names[i])
				simple_error("This name is entered twice.\n");
		}
	}

	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << ", " << numbers[i] << '\n';
	}

	return 0;
}
