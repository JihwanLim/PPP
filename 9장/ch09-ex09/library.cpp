
#include "library.h"

Library::Transaction::Transaction(Patron patron, Book book, Date date)
	: patron{ patron }, book{ book }, date{ date }
{
}

void Library::addBook()
{
	string title;
	string author;
	string isbn;
	string copyright_date;
	Book::Genre genre;

	cout << "Title: ";
	cin >> title;
	cin.ignore(256, '\n');
	cin.clear();

	cout << "Author: ";
	cin >> author;

	cout << "ISBN: ";
	cin >> isbn;

	cout << "Copyright date: ";
	cin >> copyright_date;

	cout << "1. Fiction, 2. Nonfiction, 3. Periodical\n";
	cout << "4. Biography, 5. Children\n";
	cout << "Genre(enter a number): ";
	int n;
	cin >> n;
	if (n == (int)(genre = Book::Genre::fiction));
	else if (n == (int)(genre = Book::Genre::nonfiction));
	else if (n == (int)(genre = Book::Genre::periodical));
	else if (n == (int)(genre = Book::Genre::biography));
	else if (n == (int)(genre = Book::Genre::children));
	else throw LibraryException{ "Invalid genre" };

	books.push_back(Book{ isbn, title, author, copyright_date, genre });
}


void Library::addPatron()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;

	patrons.push_back(Patron{ name });
	cout << name << "(ID: " << patrons[patrons.size() - 1].getId() << ") created\n";
}

void Library::addPatron(const Patron& patron)
{
	patrons.push_back(patron);
}

void Library::checkOut()
{
	cout << "Enter your ID: ";
	string id;
	cin >> id;
	cin.ignore(256, '\n');
	cin.clear();

	cout << "Enter the title of the book you want to check out: ";
	string title;
	cin >> title;

	const Patron* patron_ptr = nullptr;
	const Book* book_ptr = nullptr;

	for (const Patron& patron : patrons) {
		if (patron.getId() == id) {
			if (patron.getLateFee() > 0)
				throw LibraryException{ "This patron has late fee" };
			patron_ptr = &patron;
		}
	}

	for (const Book& book : books) {
		if (book.getTitle() == title)
			book_ptr = &book;
	}

	if (patron_ptr == nullptr || book_ptr == nullptr)
		throw LibraryException{ "Invalid patron or book" };

	transactions.push_back(Transaction{ *patron_ptr, *book_ptr, Date{} });
}


vector<string> Library::whoHasLateFee() const
{
	vector<string> list;

	for (const Patron& patron : patrons) {
		if (patron.getLateFee() > 0)
			list.push_back(patron.getName());
	}

	return list;
}

