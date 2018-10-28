/*
	CHAPTER 4 - COMPUTATION
	Exercise 14
*/

#include "std_lib_facilities.h"

int main()
{
	int max = 0;
	cout << "Set a max value: ";
	cin >> max;

	vector<int> prime(max + 1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= max; ++i) {
		if (prime[i] != false) {
			cout << i << '\n';
			for (int j = i + i; j <= max; j += i)
				prime[j] = false;
		}
	}

	return 0;
}
