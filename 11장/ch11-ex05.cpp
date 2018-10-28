
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

void f()
{
	for (char ch; cin.get(ch); ) {
		if (isspace(ch) && ch != '\n') cout << "space\n";
		if (isdigit(ch)) cout << "digit\n";
		if (isalpha(ch)) cout << "alpha\n";
		if (!isspace(ch) && !isdigit(ch) && !isalpha(ch)) cout << "etc.\n";
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

