
#ifndef __PATRON_H
#define __PATRON_H

#include "std_lib_facilities.h"

class Patron {
public:
	string getName() const { return name; }
	string getId() const { return id; }
	int getLateFee() const { return late_fee; }
	void setLateFee(int late_fee) { this->late_fee = late_fee; };

	Patron(string name);

private:
	string name;
	string id;
	int late_fee;
};

bool hasLateFee(const Patron& p);

#endif

