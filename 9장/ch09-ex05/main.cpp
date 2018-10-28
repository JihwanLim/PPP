
#include "std_lib_facilities.h"
#include "book.h"

int main()
{
	try {
		Book book1{ "0-321-99278-4", "Programming: Principles and Practice Using C++ 2nd Edition", "Bjarne Stroustrup", "2014" };
		Book book2{ "0-321-56384-0", "The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "2013" };
		Book book3{ "0-321-A0484-3", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", "1988" };
	}
	catch (Book::Invalid& e) {
		cerr << "New book can't be created (" << e.message << ')' << endl;
	}

	return 0;
}

