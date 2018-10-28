
#include "std_lib_facilities.h"

class Info {
public:
	double max;
	double min;
	double avg;
	double med;

	Info() : max(0), min(0), avg(0), med(0) {}
	void show() {
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
		cout << "avg: " << avg << endl;
		cout << "med: " << med << endl;
	}
};

void getInfo(vector<double>& v, double& max, double& min, double& avg, double& med)
{
	if (v.size() == 0) {
		cerr << "no contents\n";
		return;
	}

	double sum = 0;

	// get max and min
	max = v[0];
	min = v[0];
	for (double& x : v) {
		if (x > max) max = x;
		if (x < min) min = x;
		sum += x;
	}

	// get average
	avg = sum / v.size();

	// get median
	vector<double> vv = v;
	sort(vv.begin(), vv.end());
	med = vv[vv.size() / 2];
}

int main()
{
	vector<double> v;

	v.push_back(95.5);
	v.push_back(110.22);
	v.push_back(107.76);
	v.push_back(114.8);
	v.push_back(101.12);
	v.push_back(99.64);
	v.push_back(105.26);
	v.push_back(93.99);
	v.push_back(94.23);

	double max, min, avg, med;
	max = min = avg = med = 0;

	getInfo(v, max, min, avg, med);

	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
	cout << "avg: " << avg << endl;
	cout << "med: " << med << endl;

	return 0;
}

/*
	I prefer the way using struct instead of this
	because I think the first way seems more safe
	and clear to read. In this second way, getInfo()
	function can access directly the variables in main(),
	so it seems dangerous.
*/

