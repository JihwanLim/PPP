/*
	CHAPTER 4 - COMPUTATION
	Exercise 10
*/

#include "std_lib_facilities.h"

int main()
{
	char your_move = ' ';	// must be 'r(rock)', 'p(paper)', or 's(scissors)'

	vector<char> next_moves;
	cout << "Set next ten moves of the computer (Only use 'r(rock)', 'p(paper)', or 's(scissors)\n";
	for (int i = 0; i < 10; ) {
		cin >> your_move;
		if (your_move == 'r' || your_move == 'p' || your_move == 's') {
			next_moves.push_back(your_move);
			++i;
		}
		else
			cout << "That was wrong input. Please try again!\n";
	}

	for (int i = 0; i < 10; ) {
		cout << "\"ROCK, PAPER, SCISSORS!\" (Only use 'r(rock)', 'p(paper)', or 's(scissors)')\n";
		cin >> your_move;
		switch (your_move) {
		case 'r':
		case 'R':
			switch (next_moves[i]) {
			case 'r':
			case 'R':
				cout << "Draw\n";
				break;

			case 'p':
			case 'P':
				cout << "You lose\n";
				break;

			case 's':
			case 'S':
				cout << "You win\n";
				break;
			}
			++i;
			break;
		case 'p':
		case 'P':
			switch (next_moves[i]) {
			case 'r':
			case 'R':
				cout << "You win\n";
				break;

			case 'p':
			case 'P':
				cout << "Draw\n";
				break;

			case 's':
			case 'S':
				cout << "You lose\n";
				break;
			}
			++i;
			break;

		case 's':
		case 'S':
			switch (next_moves[i]) {
			case 'r':
			case 'R':
				cout << "You lose\n";
				break;

			case 'p':
			case 'P':
				cout << "You win\n";
				break;

			case 's':
			case 'S':
				cout << "Draw\n";
				break;
			}
			++i;
			break;

		default:
			cout << "That was wrong input. Please try again!\n";
			break;
		}
	}
	return 0;
}
