/*
	CHAPTER 4 - COMPUTATION
	Exercise 13
*/

#include "std_lib_facilities.h"

int main()
{
	vector<int> prime(101, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= 100; ++i) {
		if (prime[i] != false) {
			cout << i << '\n';
			for (int j = i + i; j <= 100; j += i)
				prime[j] = false;
		}
	}

	return 0;
}
