
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

Info getInfo(vector<double>& v)
{
	if (v.size() == 0) {
		cerr << "no contents\n";
		return Info{};
	}

	Info info;
	double sum = 0;

	// get max and min
	info.max = v[0];
	info.min = v[0];
	for (double& x : v) {
		if (x > info.max) info.max = x;
		if (x < info.min) info.min = x;
		sum += x;
	}

	// get average
	info.avg = sum / v.size();

	// get median
	vector<double> vv = v;
	sort(vv.begin(), vv.end());
	info.med = vv[vv.size() / 2];

	return info;
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

	Info info = getInfo(v);
	info.show();

	return 0;
}

