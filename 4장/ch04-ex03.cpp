/*
	CHAPTER 4 - COMPUTATION
	Exercise 3
*/

#include "std_lib_facilities.h"

int main()
{
	vector<double> distances;
	double total_distances = 0.;

	for (double dist; cin >> dist; ) {
		distances.push_back(dist);
		total_distances += dist;
	}

	sort(distances.begin(), distances.end());

	cout << "The smallest distance: " << distances[0] << '\n';
	cout << "The greatest distance: " << distances[distances.size() - 1] << '\n';
	cout << "The mean distance: " << total_distances / distances.size() << '\n';

	return 0;
}
