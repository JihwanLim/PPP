
#include "std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v)
{
	if (v.size() != 0) {
		cerr << "not empty" << endl;
		return;
	}

	v.push_back(x);
	v.push_back(y);

	while (v[v.size() - 1] > 0) {
		v.push_back(v[v.size() - 2] + v[v.size() - 1]);
	}
}

void print(vector<int>& v)
{
	// v[v.size() - 1] is wrong value because maximum size of int is restricted
	// so v[v.size() - 2] is the last correct value of int
	cout << v[v.size() - 2] << endl;
}

int main()
{
	vector<int> v;

	fibonacci(1, 2, v);
	print(v);

	return 0;
}

