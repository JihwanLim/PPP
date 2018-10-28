
#include "std_lib_facilities.h"

double get_total_price(vector<double> price, vector<double> weight)
{
	if (price.size() != weight.size()) {
		cerr << "the sizes of price and weight don't equal\n";
		return -1;
	}

	double sum = 0;
	for (int i = 0; i < price.size(); ++i) {
		sum += price[i] * weight[i];
	}

	return sum;
}

int main()
{
	vector<double> price, weight;

	price.push_back(10000);
	price.push_back(11500);
	price.push_back(9900);
	price.push_back(8000);
	price.push_back(12000);

	weight.push_back(1.2);
	weight.push_back(0.8);
	weight.push_back(0.4);
	weight.push_back(0.75);
	weight.push_back(0.98);

	cout << get_total_price(price, weight) << '\n';

	return 0;
}