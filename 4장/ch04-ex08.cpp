/*
	CHAPTER 4 - COMPUTATION
	Exercise 8
*/

#include "std_lib_facilities.h"

int main()
{
	int current_square = 1;
	int num_of_grains = 1;	// on the current square
	int sum_of_grains = 0;

	while (sum_of_grains < 1000) {
		cout << "Current square: " << current_square++ << '\n';
		cout << "The number of grains on the current square: " << num_of_grains << '\n';
		sum_of_grains += num_of_grains;
		num_of_grains *= 2;
		cout << "The sum of grains on all previous squares: " << sum_of_grains << "\n\n";
	}

	return 0;
}
