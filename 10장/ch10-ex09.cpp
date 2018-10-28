
#include "std_lib_facilities.h"

int main() try
{
	cout << "Please enter first input file name: ";
	string iname1;
	cin >> iname1;
	ifstream ifs1{ iname1 };
	if (!ifs1) error("can't open file name ", iname1);

	cout << "Please enter second input file name: ";
	string iname2;
	cin >> iname2;
	ifstream ifs2{ iname2 };
	if (!ifs2) error("can't open file name ", iname2);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open file name ", oname);

	vector<string> words;
	for (string s; !ifs1.eof(); ) {
		ifs1 >> s;
		words.push_back(s);
	}
	for (string s; !ifs2.eof(); ) {
		ifs2 >> s;
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	for (const string& s : words)
		ofs << s << '\n';

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

