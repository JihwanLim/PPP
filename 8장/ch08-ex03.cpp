
#include "std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n)
{
	if (v.size() != 0) {
		cerr << "not empty" << endl;
		return;
	}

	v.push_back(x);
	v.push_back(y);

	for (int i = 0; i < n; ++i) {
		v.push_back(v[v.size() - 2] + v[v.size() - 1]);
	}
}

void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> v;

	fibonacci(1, 2, v, 3);
	print(v);

	return 0;
}

