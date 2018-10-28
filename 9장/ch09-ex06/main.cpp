
#include "std_lib_facilities.h"
#include "book.h"

int main() try
{
	vector<Book> books;

	books.push_back(Book{ "0-321-99278-4", "Programming: Principles and Practice Using C++ 2nd Edition", "Bjarne Stroustrup", "2014" });
	books.push_back(Book{ "0-321-56384-0", "The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "2013" });
	books.push_back(Book{ "0-321-20434-3", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", "1988" });
	books.push_back(Book{ "0-321-56384-0", "The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "2013" });

	for (const Book& b : books)	cout << b << endl << endl;

	cout << (books[1] == books[3]) << endl;

	return 0;
}
catch (const Book::Invalid& e)
{
	cerr << e.message << endl;
	return 1;
}

