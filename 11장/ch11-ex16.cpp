
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
	if (!ifs) error("can't open output file ", oname);

	vector<double> v;
	for (double num; ifs >> num; ) {
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int duplicated = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (i == 0)
			ofs << v[i];
		else {
			if (v[i - 1] == v[i])
				++duplicated;
			else {
				if (duplicated == 0)
					ofs << '\n';
				else {
					ofs << '\t' << duplicated + 1 << '\n';
					duplicated = 0;
				}
				ofs << v[i];
			}
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

