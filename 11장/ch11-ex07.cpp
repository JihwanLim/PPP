
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

void f()
{
	string buffer;

	for (char ch; cin.get(ch); ) {		
		if (buffer.size() >= 5 &&
			buffer[buffer.size() - 1] == 't' &&
			buffer[buffer.size() - 2] == '\'' &&
			buffer[buffer.size() - 3] == 'n' &&
			buffer[buffer.size() - 4] == 'o' &&
			buffer[buffer.size() - 5] == 'd')
		{
			for (int i = 0; i < 5; ++i) buffer.pop_back();
			buffer += "do not";
		}
		else if (buffer.size() >= 5 &&
			buffer[buffer.size() - 1] == 't' &&
			buffer[buffer.size() - 2] == '\'' &&
			buffer[buffer.size() - 3] == 'n' &&
			buffer[buffer.size() - 4] == 'a' &&
			buffer[buffer.size() - 5] == 'c')
		{
			for (int i = 0; i < 5; ++i) buffer.pop_back();
			buffer += "cannot";
		}
		
		if (ch != '\n') {
			buffer.push_back(ch);
		}
		else {
			for (char& c : buffer)
				cout << c;
			cout << '\n';
			buffer.clear();
		}
	}
}

//--------------------------------------------------------------------------------------

int main() try
{
	f();

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

