/*
	CHAPTER 5 - ERRORS
	Exercise 14
*/

#include "std_lib_facilities.h"

int main() try
{
	vector<int> mon;
	vector<int> tue;
	vector<int> wed;
	vector<int> thu;
	vector<int> fri;
	vector<int> sat;
	vector<int> sun;

	string dow = "";	// day of week
	int rejection_count = 0;

	cout << "Enter pairs of weekday and integer value. (Press \"| |\" to quit and show result)\n";

	for (int value = 0; cin >> dow >> value;) {
		if (dow == "Mon" ||
			dow == "mon" ||
			dow == "MON" ||
			dow == "Monday" ||
			dow == "monday" ||
			dow == "MONDAY"
			)
			mon.push_back(value);
		else if (
			dow == "Tue" ||
			dow == "tue" ||
			dow == "TUE" ||
			dow == "Tuesday" ||
			dow == "tuesday" ||
			dow == "TUESDAY"
			)
			tue.push_back(value);
		else if (
			dow == "Wed" ||
			dow == "wed" ||
			dow == "WED" ||
			dow == "Wednesday" ||
			dow == "wednesday" ||
			dow == "WEDNESDAY"
			)
			wed.push_back(value);
		else if (
			dow == "Thu" ||
			dow == "thu" ||
			dow == "THU" ||
			dow == "Thursday" ||
			dow == "thursday" ||
			dow == "THURSDAY"
			)
			thu.push_back(value);
		else if (
			dow == "Fri" ||
			dow == "fri" ||
			dow == "FRI" ||
			dow == "Friday" ||
			dow == "friday" ||
			dow == "FRIDAY"
			)
			fri.push_back(value);
		else if (
			dow == "Sat" ||
			dow == "sat" ||
			dow == "SAT" ||
			dow == "Saturday" ||
			dow == "saturday" ||
			dow == "SATURDAY"
			)
			sat.push_back(value);
		else if (
			dow == "Sun" ||
			dow == "sun" ||
			dow == "SUN" ||
			dow == "Sunday" ||
			dow == "sunday" ||
			dow == "SUNDAY"
			)
			sun.push_back(value);
		else {
			++rejection_count;
		}
	}

	cout << "MON: ";
	for (int i = 0; i < mon.size(); ++i)
		cout << mon[i] << ' ';
	cout << '\n';

	cout << "TUE: ";
	for (int i = 0; i < tue.size(); ++i)
		cout << tue[i] << ' ';
	cout << '\n';

	cout << "WED: ";
	for (int i = 0; i < wed.size(); ++i)
		cout << wed[i] << ' ';
	cout << '\n';

	cout << "THU: ";
	for (int i = 0; i < thu.size(); ++i)
		cout << thu[i] << ' ';
	cout << '\n';

	cout << "FRI: ";
	for (int i = 0; i < fri.size(); ++i)
		cout << fri[i] << ' ';
	cout << '\n';

	cout << "SAT: ";
	for (int i = 0; i < sat.size(); ++i)
		cout << sat[i] << ' ';
	cout << '\n';

	cout << "SUN: ";
	for (int i = 0; i < sun.size(); ++i)
		cout << sun[i] << ' ';
	cout << '\n';

	cout << "Rejection count: " << rejection_count << '\n';

	return 0;
}
catch (exception& e)
{
	cerr << "Error: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "Unknown exception\n";
	return 2;
}