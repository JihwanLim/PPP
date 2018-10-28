
#include "std_lib_facilities.h"

void printInfo(vector<string>&, vector<double>&);
void sortInfo(vector<string>&, vector<double>&);

int main()
{
	vector<string> name;
	
	cout << "Enter person names (press Ctrl+Z to quit)\n";
	for (string input = ""; cin >> input; ) {
		name.push_back(input);
	}

	cin.ignore(256, '\n');
	cin.clear();

	vector<double> age;
	for (string& n : name) {
		double a;
		cout << "How old is " << n << "? ";
		cin >> a;
		age.push_back(a);
	}

	cout << "--------------------------------------------\n";
	printInfo(name, age);
	cout << "--------------------------------------------\n";
	sortInfo(name, age);
	printInfo(name, age);
	cout << "--------------------------------------------\n";

	return 0;
}

void printInfo(vector<string>& name, vector<double>& age)
{
	if (name.size() != age.size()) {
		cerr << "sizes of name and age don't equal\n";
		return;
	}

	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << '\t' << age[i] << '\n';
}

void sortInfo(vector<string>& name, vector<double>& age)
{
	vector<string> name_cp = name;
	vector<double> age_cp;

	sort(name_cp.begin(), name_cp.end());

	for (int i = 0; i < name_cp.size(); ++i) {
		for (int j = 0; j < name.size(); ++j) {
			if (name_cp[i] == name[j]) {
				age_cp.push_back(age[j]);
			}
		}
	}

	name = name_cp;
	age = age_cp;
}

