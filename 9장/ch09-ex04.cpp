
#include "std_lib_facilities.h"

/*

Example code 8.4:

// dangerously ugly code
struct X {
	void f(int x) {
		struct Y {
			int f() { return 1; } int m; };
		int m;
		m=x; Y m2;
		return f(m2.f()); }
	int m; void g(int m) {
		if (m) f(m+2); else {
			g(m+2); }}
X() { } void m3() {
}

void main() {
	X a; a.f(2);}
};

*/


struct X {							// struct X with member functions f(), g(), m3() and main(), member variable m
	void f(int x)					// function f() within X
	{
		struct Y {					// struct Y within f()
			int f() { return 1; }	// member function of Y
			
			int m;					// data member of Y
		};

		int m;						// variable with f()
		m = x;						// set m to argument of f()
		Y m2;						// declare variable of type Y
		
		return f(m2.f());			// f returns the result of f called with m2.f(), which is 1. Endless recursion?
	}

	int m;							// data member of X
	
	void g(int m)					// function g() within X
	{
		if (m) {					// if argument of g() is not zero
			f(m + 2);				// call X.f() with argument m+2
		}
		else {						// if argument of g() is zero
			g(m + 2);				// call g() with argument m+2
		}
	}

	X()								// default constructor for struct X
	{

	}
	
	void m3()						// member function m3() of struct X, does nothing, returns nothing
	{

	}

	void main()						// member function main() of struct X
	{
		X a;						// declare variable of type X, uses default constructor, int m not initialized
		a.f(2);						// call X.f() with argument 2
	}
};

