/*
	CHAPTER 4 - COMPUTATION
	Exercise 12
*/

#include "std_lib_facilities.h"

bool IsPrimeNumber(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;

	for (int i = 2; i < n; ++i)
		if (n % i == 0) return false;

	return true;
}

int main()
{
	vector<int> primes;
	int max = 0;

	cout << "Set max value: ";
	cin >> max;

	for (int i = 1; i <= max; ++i)
		if (IsPrimeNumber(i))
			primes.push_back(i);

	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << '\n';

	return 0;
}
