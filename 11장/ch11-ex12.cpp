
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

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open output file ", oname);

	vector<string> lines;
	for (string line; getline(ifs, line); ) {
		lines.push_back(line);
	}

	for (int i = lines.size() - 1; i >= 0; --i) {
		for (int j = lines[i].size() - 1; j >= 0; --j) {
			ofs << lines[i][j];
		}
		ofs << '\n';
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

