
#include "std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();

private:
	vector<string> name;
	vector<double> age;
};

int main()
{
	Name_pairs np;

	for (int i = 0; i < 5; ++i) {
		np.read_names();
		np.read_ages();
	}

	np.print();

	np.sort();
	cout << "\nsorted\n\n";

	np.print();

	return 0;
}


// implementations:

void Name_pairs::read_names()
{
	cout << "enter a name: ";
	string s;
	cin >> s;
	name.push_back(s);
}

void Name_pairs::read_ages()
{
	cout << "enter an age: ";
	double d;
	cin >> d;
	age.push_back(d);
}

void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << ", " << age[i] << endl;
}

void Name_pairs::sort()
{
	while (1) {
		int swap_count = 0;
		for (int i = 0; i < name.size() - 1; ++i) {
			if (name[i] > name[i + 1]) {
				swap(name[i], name[i + 1]);
				swap(age[i], age[i + 1]);
				swap_count += 1;
			}
		}
		if (swap_count == 0)
			break;
	}
}