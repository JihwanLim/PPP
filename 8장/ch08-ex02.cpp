
#include "std_lib_facilities.h"

void print(vector<int>& v, string& message)
{
	cout << message << endl;
	
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(45);
	string msg = "hello, world";
	print(v, msg);

	return 0;
}

