#ifndef __BOOK_H
#define __BOOK_H

#include "std_lib_facilities.h"

class Book {
public:
	string getIsbn() const { return isbn; }
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	string getCopyrightDate() const { return copyright_date; }
	bool isCheckedOut() const { return is_checked_out; }

private:
	string isbn;
	string title;
	string author;
	string copyright_date;
	bool is_checked_out;

private:
	bool is_valid_isbn();

public:
	Book(string isbn, string title, string author, string copyright_date);

	class Invalid {
	public:
		string message;
		Invalid(string msg = "");
	};
};

#endif

