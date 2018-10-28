/*
	CHAPTER 4 - COMPUTATION
	Exercise 21
*/

#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	string name_input = "";
	int score_input = 0;

	while (cin >> name_input >> score_input) {
		names.push_back(name_input);
		scores.push_back(score_input);
		for (int i = 0; i < names.size() - 1; ++i) {
			if (names[names.size() - 1] == names[i])
				simple_error("Name already exists\n");
		}
	}

	cin.clear();
	cin.ignore(256, '\n');
	cout << "Enter an integer: ";
	cin >> score_input;
	bool is_score_found = false;

	for (int i = 0; i < scores.size(); ++i) {
		if (score_input == scores[i]) {
			cout << names[i] << '\n';
			is_score_found = true;
		}
		if (i == scores.size() - 1 && is_score_found == false) {
			cout << "Score not found\n";
		}
	}

	return 0;
}
