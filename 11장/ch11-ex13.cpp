
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

int main() try
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open input file ", iname);

	for (string word; ifs >> word; ) {
		for (int i = word.size() - 1; i >= 0; --i)
			cout << word[i];
		cout << ' ';
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

