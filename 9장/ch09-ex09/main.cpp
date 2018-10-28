
#include "std_lib_facilities.h"
#include "library.h"

int main() try
{
	Library lib;

	cout << "Add book\n";
	lib.addBook();

	cout << "\n\nAdd Patron\n";
	lib.addPatron();

	cout << "\n\nAdd Patron\n";
	lib.addPatron();

	cout << "\n\nCheck out\n";
	lib.checkOut();

	Patron jihwan{ "Jihwan Lim" };
	jihwan.setLateFee(100);
	lib.addPatron(jihwan);

	cout << "\n\nWho has late fee?\n";
	vector<string> list = lib.whoHasLateFee();
	for (const string& name : list)
		cout << name << endl;

	return 0;
}
catch (const Library::LibraryException& e)
{
	cerr << e.message << endl;
}
catch (exception& e)
{
	cerr << e.what() << endl;
	return 2;
}
catch (...)
{
	cerr << "unknown exception!\n";
	return 3;
}

