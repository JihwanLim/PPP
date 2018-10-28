/*
	CHAPTER 4 - COMPUTATION
	Exercise 11
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
	vector<int> primes;

	for (int i = 1; i <= 100; ++i)
		if (IsPrimeNumber(i))
			primes.push_back(i);

	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << '\n';

	return 0;
}
