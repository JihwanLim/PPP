/*
	CHAPTER 6 - WRITING A PROGRAM
	Exercise 4
*/

#include "std_lib_facilities.h"

class Name_value {
private:
	string name;
	int value;
public:
	Name_value(string name, int value) : name(name), value(value) {}
	void print() {
		cout << name << ", " << value << '\n';
	}
};

int main()
{
	vector<Name_value> vec;
	
	vec.push_back(Name_value{ "Jihwan Lim", 100 });
	for (int i = 0; i < vec.size(); ++i)
		vec[i].print();

	return 0;
}