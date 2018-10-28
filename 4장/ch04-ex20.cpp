/*
	CHAPTER 4 - COMPUTATION
	Exercise 20
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
				simple_error("Name already exists\n");
		}
	}

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Enter a name: ";
	cin >> name_input;
	bool is_name_found = false;

	for (int i = 0; i < names.size(); ++i) {
		if (name_input == names[i]) {
			cout << name_input << "'s score: " << numbers[i] << '\n';
			is_name_found = true;
		}
		if (i == names.size() - 1 && is_name_found == false) {
			cout << "Name not found\n";
		}
	}

	return 0;
}
