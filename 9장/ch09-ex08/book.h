
#ifndef __BOOK_H
#define __BOOK_H

#include "std_lib_facilities.h"

class Book {
public:
	enum class Genre {
		fiction, nonfiction, periodical, biography, children
	};

	string getIsbn() const { return isbn; }
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	string getCopyrightDate() const { return copyright_date; }
	bool isCheckedOut() const { return is_checked_out; }
	Genre getGenre() const { return genre; }

private:
	string isbn;
	string title;
	string author;
	string copyright_date;
	bool is_checked_out;
	Genre genre;

private:
	bool is_valid_isbn();

public:

	Book(string isbn, string title, string author, string copyright_date, Genre genre);

	class Invalid {
	public:
		string message;
		Invalid(string msg = "");
	};
};

bool operator==(const Book& a, const Book& b);

bool operator!=(const Book& a, const Book& b);

ostream& operator<<(ostream& os, const Book& book);

#endif

