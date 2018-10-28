
#include "book.h"

//--------------------------------------------------------------------------------------------------------------

Book::Book(string isbn, string title, string author, string copyright_date, Genre genre)
	: isbn{ isbn }, title{ title }, author{ author }, copyright_date{ copyright_date }, genre{ genre }, is_checked_out { false }
{
	if (!is_valid_isbn()) throw Invalid{ "Invalid ISBN" };
}

//--------------------------------------------------------------------------------------------------------------

bool Book::is_valid_isbn()
{
	vector<string> isbn_parts;
	string part;

	for (unsigned int i = 0; i <= isbn.size(); ++i) {
		if (isbn[i] == '-' || isbn[i] == '\0') {
			isbn_parts.push_back(part);
			part = "";
			continue;
		}
		part += isbn[i];
	}

	if (isbn_parts.size() != 4) return false;

	for (unsigned int i = 0; i < isbn_parts.size(); ++i) {
		for (unsigned int j = 0; j < isbn_parts[i].size(); ++j) {
			char ch = isbn_parts[i][j];
			if ('0' <= ch && ch <= '9');
			else if (i == 3 && (('a' <= ch && ch <= 'z') || 'A' <= ch && ch <= 'Z'));
			else return false;
		}
	}

	return true;
}

//--------------------------------------------------------------------------------------------------------------

Book::Invalid::Invalid(string msg)
	: message{ msg } {}

//--------------------------------------------------------------------------------------------------------------

bool operator==(const Book& a, const Book& b)
{
	return a.getIsbn() == b.getIsbn();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, const Book& book)
{
	string genre;
	if (book.getGenre() == Book::Genre::biography) genre = "Biography";
	else if (book.getGenre() == Book::Genre::children) genre = "children";
	else if (book.getGenre() == Book::Genre::fiction) genre = "fiction";
	else if (book.getGenre() == Book::Genre::nonfiction) genre = "nonfiction";
	else if (book.getGenre() == Book::Genre::periodical) genre = "periodical";

	string status;
	if (book.isCheckedOut()) status = "Checked out";
	else status = "Not checked out";

	return os << book.getTitle() << '\n'
		<< book.getAuthor() << '\n'
		<< book.getIsbn() << '\n'
		<< book.getCopyrightDate() << '\n'
		<< genre << '\n'
		<< status;
}

//--------------------------------------------------------------------------------------------------------------

