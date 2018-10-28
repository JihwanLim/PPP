
#include "std_lib_facilities.h"

void print_until_s(const vector<string>& v, const string& quit)
{
	for (const string& s : v) {
		if (s == quit) return;
		cout << s << '\n';
	}
}

/*
	Q. What makes a good set of test cases?

	A number of inputs to find errors as much as possible.
*/

void print_until_ss(const vector<string>& v, const string& quit)
{
	int count = 0;

	for (const string& s : v) {
		if (s == quit) ++count;
		if (count == 2) return;
		cout << s << '\n';
	}
}

int main()
{
	vector<string> v;
	v.push_back("Hello");
	v.push_back("World");
	v.push_back("And");
	v.push_back("I am");
	v.push_back("Lim");
	v.push_back("q");
	v.push_back("haha");
	v.push_back("q");
	v.push_back("wow");
	
	const string quit = "q";

	print_until_ss(v, quit);

	return 0;
}

