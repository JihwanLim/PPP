
#include "std_lib_facilities.h"

vector<int> get_num_of_chars(const vector<string>& v)
// takes a vector<string> argument and returns a vector<int>
// containing the number of characters in each string.
{
	vector<int> num_of_chars;
	
	for (int i = 0; i < v.size(); ++i)
		num_of_chars.push_back(v[i].size());

	return num_of_chars;
}

string get_longest_string(const vector<string>& v)
{
	string longest = v[0];

	for (int i = 1; i < v.size(); ++i)
		if (longest.size() < v[i].size())
			longest = v[i];

	return longest;
}

string get_shortest_string(const vector<string>& v)
{
	string shortest = v[0];

	for (int i = 1; i < v.size(); ++i)
		if (shortest.size() > v[i].size())
			shortest = v[i];

	return shortest;
}

string get_lexicographically_first_string(vector<string> v)
{
	sort(v.begin(), v.end());
	return v[0];
}

string get_lexicographically_last_string(vector<string> v)
{
	sort(v.begin(), v.end());
	return v[v.size() - 1];
}

int main()
{
	vector<string> v;
	v.push_back("grape");
	v.push_back("apple");
	v.push_back("carrot");
	v.push_back("watermelon");
	v.push_back("melon");
	v.push_back("pineapple");
	v.push_back("pear");

	cout << "The numbers of characters in each string are ";
	vector<int> num_of_chars = get_num_of_chars(v);
	for (int& n : num_of_chars)
		cout << n << ' ';
	cout << endl;

	cout << "The longest string is " << get_longest_string(v) << '\n';
	cout << "The shortest string is " << get_shortest_string(v) << '\n';
	cout << "The lexicographically first string is " << get_lexicographically_first_string(v) << '\n';
	cout << "The lexicographically last string is " << get_lexicographically_last_string(v) << '\n';

	return 0;
}

/*
	Q. How many separate functions would you use for these tasks? Why?

	There are 4 functions because the program we want is composed of
	four computations logically separate.
*/

