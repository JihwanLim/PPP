
#include "std_lib_facilities.h"
#include "book.h"

int main() try
{
	vector<Book> books;

	books.push_back(Book{ "0-321-99278-4", "Programming: Principles and Practice Using C++ 2nd Edition", "Bjarne Stroustrup", "2014", Book::Genre::nonfiction });
	books.push_back(Book{ "0-321-56384-0", "The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "2013", Book::Genre::nonfiction });
	books.push_back(Book{ "0-321-20434-3", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", "1988", Book::Genre::nonfiction });
	books.push_back(Book{ "0-340-91939-6", "Alex Ferguson: My Autobiography", "Alex Ferguson", "2013", Book::Genre::biography });
	books.push_back(Book{ "1-588-99194-6", "Crayon Shinchan, Vol. 1", "Yoshito Usui", "2005", Book::Genre::children });
	books.push_back(books[1]);

	for (const Book& b : books)	cout << b << endl << endl;

	cout << (books[1] == books[3]) << endl;

	return 0;
}
catch (const Book::Invalid& e)
{
	cerr << e.message << endl;
	return 1;
}

