
#include "std_lib_facilities.h"
#include "book.h"
#include "patron.h"

int main() try
{
	vector<Book> books;
	vector<Patron> patrons;

	books.push_back(Book{ "0-321-99278-4", "Programming: Principles and Practice Using C++ 2nd Edition", "Bjarne Stroustrup", "2014", Book::Genre::nonfiction });
	books.push_back(Book{ "0-321-56384-0", "The C++ Programming Language, 4th Edition", "Bjarne Stroustrup", "2013", Book::Genre::nonfiction });
	books.push_back(Book{ "0-321-20434-3", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", "1988", Book::Genre::nonfiction });
	books.push_back(Book{ "0-340-91939-6", "Alex Ferguson: My Autobiography", "Alex Ferguson", "2013", Book::Genre::biography });
	books.push_back(Book{ "1-588-99194-6", "Crayon Shinchan, Vol. 1", "Yoshito Usui", "2005", Book::Genre::children });
	books.push_back(books[1]);

	patrons.push_back(Patron{ "Jihwan Lim" });
	cout << hasLateFee(patrons[0]) << '\n';

	patrons[0].setLateFee(1000);
	cout << hasLateFee(patrons[0]) << '\n';

	return 0;
}
catch (const Book::Invalid& e)
{
	cerr << e.message << endl;
	return 1;
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

