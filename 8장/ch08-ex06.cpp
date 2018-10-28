
#include "std_lib_facilities.h"

void print(vector<string>& v)
{
	for (string& x : v)
		cout << x << ' ';
	cout << "\n\n";
}

vector<string> reverse_v1(vector<string>& v)
{
	vector<string> vv;

	for (int i = v.size() - 1; i >= 0; --i) {
		vv.push_back(v[i]);
	}

	return vv;
}

void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

void reverse_v2(vector<string>& v)
{
	for (int i = 0; i < v.size() / 2; ++i) {
		swap(v[i], v[v.size() - 1 - i]);
	}
}

int main()
{
	vector<string> v;

	for (int i = 0; i < 5; ++i) {
		char str[2];
		str[0] = 'A' + i;
		str[1] = '\0';
		v.push_back(str);
	}

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

