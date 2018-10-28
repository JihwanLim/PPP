
#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "std_lib_facilities.h"
#include "book.h"
#include "patron.h"
#include "Chrono.h"

using Chrono::Date;

class Library {
private:
	class Transaction {
	public:
		Transaction(Patron patron, Book book, Date date);

	private:
		Patron patron;
		Book book;
		Date date;
	};

public:
	void addBook();
	void addPatron();
	void addPatron(const Patron& patron);
	void checkOut();
	vector<string> whoHasLateFee() const;

	// error class ----
	class LibraryException {
	public:
		string message;

		LibraryException(string message = "")
			: message{ message } {}
	};

private:
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transactions;
};

#endif

