
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"
#include <tchar.h>

//--------------------------------------------------------------------------------------

#ifdef _UNICODE
#define _tcout		wcout
#define _tcin		wcin
#define _tstring	wstring
#else
#define _tcout		cout
#define _tcin		cin
#define _tstring	string
#endif

//--------------------------------------------------------------------------------------

int _tmain(int argc, TCHAR* argv[]) try
{
	_tcout << _T("Please enter input file name: ");
	_tstring iname;
	_tcin >> iname;
	wifstream ifs{ iname };

	int spaces = 0;
	int alphas = 0;
	int digits = 0;
	int etc = 0;

	for (TCHAR ch; ifs.get(ch); ) {
		if (isspace(ch)) ++spaces;
		if (isalpha(ch)) ++alphas;
		if (isdigit(ch)) ++digits;
		if (!isspace(ch) && !isalpha(ch) && !isdigit(ch)) ++etc;
	}

	_tcout << _T("The num of spaces: ") << spaces << '\n'
		<< _T("The num of alphabets: ") << alphas << '\n'
		<< _T("The num of digits: ") << digits << '\n'
		<< _T("The num of etc.: ") << etc << '\n';

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

