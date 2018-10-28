
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

bool find(const string& s, const string& word)
{
	istringstream is{ s };

	for (string s; is >> s; )
		if (s == word) return true;
	return false;
}

//--------------------------------------------------------------------------------------

int main() try
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open file ", iname);

	cout << "Please enter a word: ";
	string word;
	cin >> word;
	if (!cin) error("not a word");

	int nu = 0;
	for (string s; getline(ifs, s); ) {
		if (find(s, word)) {
			++nu;
			cout << nu << '\t' << s << '\n';
		}
	}

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

