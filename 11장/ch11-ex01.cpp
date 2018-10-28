
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

void f() throw (exception)
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open input file ", iname);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open output file ", oname);

	for (char ch; ifs.get(ch); ) {
		if ('A' <= ch && ch <= 'Z') ch = tolower(ch);
		ofs << ch;
	}

	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	if (ifs.eof()) return;
	if (ifs.fail()) error("unexpected character");
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

