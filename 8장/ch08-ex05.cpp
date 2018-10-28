
#include "std_lib_facilities.h"

void print(vector<int>& v)
{
	for (int& x : v)
		cout << x << ' ';
	cout << "\n\n";
}

vector<int> reverse_v1(vector<int>& v)
{
	vector<int> vv;

	for (int i = v.size() - 1; i >= 0; --i) {
		vv.push_back(v[i]);
	}

	return vv;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse_v2(vector<int>& v)
{
	for (int i = 0; i < v.size() / 2; ++i) {
		swap(v[i], v[v.size() - 1 - i]);
	}
}

int main()
{
	vector<int> v;

	for (int i = 0; i < 5; ++i)
		v.push_back(i + 1);

	cout << "not reversed\n";
	print(v);
	
	cout << "reverse_v1()\n";
	v = reverse_v1(v);
	print(v);

	cout << "reverse_v2()\n";
	reverse_v2(v);
	print(v);

	return 0;
}

