
#include "std_lib_facilities.h"

int main() try
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open file name ", iname);

	int sum = 0;
	while (!ifs.eof()) {
		char ch;
		ifs >> ch;
		if (isdigit(ch)) {
			ifs.putback(ch);
			int n;
			ifs >> n;
			sum += n;
		}
	}

	cout << "Sum: " << sum << '\n';
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

