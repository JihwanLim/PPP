
#include "std_lib_facilities.h"

int main() try
{
	cout << "Please enter first input file name: ";
	string iname1;
	cin >> iname1;
	ifstream ifs1{ iname1 };
	if (!ifs1) error("can't open file ", iname1);

	cout << "Please enter second input file name: ";
	string iname2;
	cin >> iname2;
	ifstream ifs2{ iname2 };
	if (!ifs2) error("can't open file ", iname2);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open file ", oname);

	char ch;
	while (ifs1.get(ch)) ofs << ch;
	while (ifs2.get(ch)) ofs << ch;

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

