
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

bool is_oct(string s)
{
	if (s[0] != '0') return false;

	for (int i = 1; i < s.size(); ++i) {
		if ('0' <= s[i] && s[i] <= '7');
		else return false;
	}
	return true;
}

//--------------------------------------------------------------------------------------

bool is_dec(string s)
{
	for (char& ch : s)
		if ('0' <= ch && ch <= '9');
		else return false;
	return true;
}

//--------------------------------------------------------------------------------------

bool is_hex(string s)
{
	if (s[0] != '0' || tolower(s[1]) != 'x') return false;

	for (int i = 2; i < s.size(); ++i) {
		if ('0' <= s[i] && s[i] <= '9');
		else if ('a' <= tolower(s[i]) && tolower(s[i]) <= 'f');
		else return false;
	}
	return true;
}

//--------------------------------------------------------------------------------------

void f()
{
	cout << "Please enter several integers in any combination of octal, decimal, or hex"
		<< "adecimal, using the 0 and 0x base suffixes\n\n";

	cin.unsetf(ios::oct);
	cin.unsetf(ios::dec);
	cin.unsetf(ios::hex);

	while (cin) {
		string s;
		cin >> s;
		istringstream is{ s };
		int n = 0;

		cout << s << '\t';
		if (is_oct(s)) {
			cout << setw(12) << "octal";
			is >> oct >> n;
		}
		else if (is_dec(s)) {
			cout << setw(12) << "decimal";
			is >> dec >> n;
		}
		else if (is_hex(s)) {
			cout << setw(12) << "hexadecimal";
			is >> hex >> n;
		}
		cout << "\tconverts to " << n << " decimal\n";
	}
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

