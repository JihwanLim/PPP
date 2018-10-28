/*
	CHAPTER 5 - ERRORS
	Exercise 13
*/

#include "std_lib_facilities.h"

const int LENGTH = 4;

vector<int> vec(4);
int bull = 0;
int cow = 0;

void SetRandomNumber()
{
	int value = 0;
	bool is_storable = true;

	vec[0] = randint(10);
	for (int i = 1; i < LENGTH; ) {
		value = randint(10);
		is_storable = true;
		for (int j = 0; j <= i; ++j) {
			if (value == vec[j])
				is_storable = false;
		}
		if (is_storable == true) {
			vec[i] = value;
			++i;
		}
	}
}

void Score(int value)
{
	for (int i = 0; i < LENGTH; ++i) {
		if ((value / 1000) == vec[i]) {
			if (i == 0) ++bull;
			else ++cow;
		}
		else if ((value / 100 % 10) == vec[i]) {
			if (i == 1) ++bull;
			else ++cow;
		}
		else if ((value / 10 % 10) == vec[i]) {
			if (i == 2) ++bull;
			else ++cow;
		}
		else if ((value % 10) == vec[i]) {
			if (i == 3) ++bull;
			else ++cow;
		}
	}

	cout << bull << " bull";
	if (bull != 1)
		cout << 's';
	cout << " and " << cow << " cow";
	if (cow != 1)
		cout << 's';
	cout << '\n';
}

int main() try
{
	unsigned int seed = 0;
	int value;

	cout << "Set a seed: ";
	cin >> seed;
	srand(seed);

	/* Set random 4 integers */
	SetRandomNumber();

	/* Guessing */
	while (true) {
		bull = 0;
		cow = 0;
		cout << "Guess the number (0000 ~ 9999): ";
		cin >> value;

		if (value < 0 || value > 9999)
			error("A range of a number should be in 0 ~ 9999.");

		Score(value);		

		if (bull == LENGTH) {
			cout << "Great!\n";
			break;
		}
	}

	return 0;
}
catch (exception& e)
{
	cerr << "Error: " << e.what() << '\n';
}
catch (...)
{
	cerr << "Unknown exception.\n";
}