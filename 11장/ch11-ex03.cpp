
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

bool is_vowel(char ch)
{
	if ('a' <= ch && ch <= 'z');
	else if ('A' <= ch && ch <= 'Z') ch = tolower(ch);
	else return false;

	string vowels = "aeiou";
	for (char& v : vowels)
		if (ch == v) return true;
	return false;
}

//--------------------------------------------------------------------------------------

void f()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open file ", iname);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open file ", oname);

	for (char ch; ifs.get(ch); )
		if (!is_vowel(ch)) ofs << ch;
}

//--------------------------------------------------------------------------------------

int main() try
{
	f();

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

