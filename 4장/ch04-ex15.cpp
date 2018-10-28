/*
	CHAPTER 4 - COMPUTATION
	Exercise 15
*/

#include "std_lib_facilities.h"

bool IsPrimeNumber(int num)
{
	if (num < 2) return false;
	if (num == 2) return true;

	for (int i = 2; i < num; ++i)
		if (num % i == 0) return false;

	return true;
}

int main()
{
	int n = 0;
	cout << "How many prime numbers do you want? ";
	cin >> n;

	int i = 0;
	for (int count = 0; count < n; ) {
		if (IsPrimeNumber(++i)) {
			cout << i << '\n';
			++count;
		}
	}

	return 0;
}
