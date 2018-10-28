/*
	CHAPTER 4 - COMPUTATION
	Exercise 17
*/

#include "std_lib_facilities.h"

int main()
{
	string vals[] = { "3", "1", "4", "2", "3", "1", "4", "2", "3" };	// mode value: 3
	vector<string> vec(vals, vals + sizeof(vals) / sizeof(string));

	sort(vec.begin(), vec.end());
	
	int current_count = 0;
	int max_count = 0;
	string mode_value = "-1";
	string min_value, max_value;

	for (int i = 1; i < vec.size(); ++i) {
		/* getting the min and max values */
		if (1 == i) {
			min_value = vec[0];
			max_value = vec[0];
		}
		if (min_value > vec[i]) min_value = vec[i];
		if (max_value < vec[i]) max_value = vec[i];

		/* getting the mode value */
		if (vec[i] == vec[i - 1]) {
			++current_count;
			if (max_count < current_count) {
				max_count = current_count;
				mode_value = vec[i];
			}
		}
		else {
			current_count = 0;
		}
	}

	cout << "The max value: " << max_value << '\n';
	cout << "The min value: " << min_value << '\n';
	cout << "The mode value: " << mode_value << '\n';
	return 0;
}
