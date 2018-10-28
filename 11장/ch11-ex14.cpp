
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

int main() try
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname, ios::binary };
	if (!ifs) error("can't open input file ", iname);

	int spaces;
	int alphas;
	int digits;
	int etc;

	spaces = alphas = digits = etc = 0;

	for (char ch; ifs.get(ch); ) {
		if (isspace(ch)) ++spaces;
		if (isalpha(ch)) ++alphas;
		if (isdigit(ch)) ++digits;
		if (!isspace(ch) && !isalpha(ch) && !isdigit(ch)) ++etc;
	}

	cout << "The num of spaces: " << spaces << '\n';
	cout << "The num of alphabets: " << alphas << '\n';
	cout << "The num of digits: " << digits << '\n';
	cout << "The num of etc.: " << etc << '\n';

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

