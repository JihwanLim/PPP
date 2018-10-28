
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

class PunctStream {
public:
	PunctStream(istream& is)
		: source{ is }, sensitive{ true } {}

	void whitespace(const string& s) { white = s; }
	void add_white(char c) { white += c; }
	bool is_whitespace(char c);
	void case_sensitive(bool b) { sensitive = b; }
	bool is_case_sensitive() { return sensitive; }

	PunctStream& operator>>(string& s);
	operator bool();

private:
	istream& source;		// character source
	istringstream buffer;	// we let buffer do our formatting
	string white;			// characters considered "whitespace"
	bool sensitive;			// is the stream case-sensitive?
};

//--------------------------------------------------------------------------------------

PunctStream& PunctStream::operator>>(string& s)
{
	while (!(buffer >> s)) {		// try to read from buffer
		if (buffer.bad() || !source.good()) return *this;
		buffer.clear();

		string line;
		getline(source, line);		// get a line from source

		// do character replacement as needed:
		for (char& ch : line)
			if (is_whitespace(ch))
				ch = ' ';			// to space
			else if (!sensitive)
				ch = tolower(ch);	// to lower case

		buffer.str(line);			// put string into stream
	}

	return *this;
}

//--------------------------------------------------------------------------------------

bool PunctStream::is_whitespace(char c)
{
	for (char w : white)
		if (c == w) return true;
	return false;
}

//--------------------------------------------------------------------------------------

PunctStream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}

//--------------------------------------------------------------------------------------

int main() try
	// given text input, produce a sorted list of all words in that text
	// ignore punctuation and case differences
	// eliminate duplicates from the output
{
	ifstream input{ "input.txt" };
	if (!input) error("can't open input file");

	PunctStream ps{ input };
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");	// note \" means " in string
	ps.case_sensitive(false);

	vector<string> vs;
	for (string word; ps >> word; )
		vs.push_back(word);				// read words

	sort(vs.begin(), vs.end());			// sort in lexicographical order
	for (int i = 0; i < vs.size(); ++i)	// write dictionary
		if (i == 0 || vs[i] != vs[i - 1])
			cout << vs[i] << '\n';

	return 0;
}
catch (exception& e)
{
	cerr << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}

//--------------------------------------------------------------------------------------

