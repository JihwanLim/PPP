#include <iostream>
#include <string>
using namespace std;

int main() try
{
	string num;
	cout << "> ";
	cin >> num;

	int res = 0;

	for (int i = 0; i < num.size(); ++i) {
		int exp = num.size() - (i + 1);
		int mul = 10;

		if (exp == 0) mul = 1;
		else if (exp == 1) mul = 10;
		else {
			for (int j = 0; j < exp - 1; ++j)
				mul *= 10;
		}
		res += (num[i] - '0') * mul;
	}

	cout << res << endl;
	return 0;
}
catch (exception& e)
{
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "unknown exception!\n";
	return 2;
}

