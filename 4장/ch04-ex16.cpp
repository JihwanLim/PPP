/*
	CHAPTER 4 - COMPUTATION
	Exercise 16
*/

#include "std_lib_facilities.h"

int main()
{
	unsigned int vals[] = { 3, 1, 4, 2, 3, 1, 4, 2, 3 };	// mode value: 3
	vector<unsigned int> vec(vals, vals + sizeof(vals) / sizeof(unsigned int));

	sort(vec.begin(), vec.end());
	
	int current_count = 0;
	int max_count = 0;
	int mode_value = -1;

	for (int i = 1; i < vec.size(); ++i) {
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

	cout << "The mode value: " << mode_value << '\n';

	return 0;
}
