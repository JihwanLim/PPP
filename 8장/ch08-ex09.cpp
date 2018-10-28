
#include "std_lib_facilities.h"

int maxv(vector<int> v)
{
	int max = v[0];

	for (int& x : v)
		if (x > max) max = x;

	return max;
}

int main()
{
	vector<int> v;

	v.push_back(110);
	v.push_back(111);
	v.push_back(125);
	v.push_back(123);
	v.push_back(122);
	v.push_back(142);
	v.push_back(112);
	v.push_back(109);

	cout << maxv(v) << endl;

	return 0;
}

