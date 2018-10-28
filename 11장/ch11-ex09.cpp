
//--------------------------------------------------------------------------------------

#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------------

vector<int> binary_input()
{
	// open an istream for binary input from a file:
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname, ios_base::binary };	// note: stream mode
		// binary tells the stream not to try anything clever with the bytes
	if (!ifs) error("can't open input file ", iname);

	vector<int> v;

	// read from binary file:
	for (int x; ifs.read(as_bytes(x), sizeof(int)); )	// note: reading bytes
		v.push_back(x);

	return v;
}

//--------------------------------------------------------------------------------------

void binary_output(vector<int>& v)
{
	// open an ostream for binary output to a file:
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname, ios_base::binary };	// note: stream mode
		// binary tells the stream not to try anything clever with the bytes
	if (!ofs) error("can't open output file ", oname);

	// write to binary file:
	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));			// note: writing bytes
}

//--------------------------------------------------------------------------------------

int main() try
{
	vector<int> v = binary_input();
	binary_output(v);

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

