
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

vector<string> split(const string& s)
{
	vector<string> subs;
	istringstream is{ s };

	for (string sub; is >> sub; )
		subs.push_back(sub);

	return subs;
}

//--------------------------------------------------------------------------------------

int main() try
{
	cout << "Please enter a string\n";
	string s;
	getline(cin, s);
	vector<string> subs = split(s);

	for (string& sub : subs)
		cout << sub << '\n';

	return 0;
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}

//--------------------------------------------------------------------------------------

