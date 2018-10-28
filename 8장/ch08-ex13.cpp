
/*
	There are no reasons you have to use it. const is for preventing it from being changed.
	And, reference arguments enable you to access directly to original of arguments.
	If you use a non-reference function with const arguments, its purpose is probably
	preventing the copied const arguments from being changed. I can never find well-use
	cases of it because generally copied arguments don't have risks about being changed.
*/

#include "std_lib_facilities.h"

void f1(const int n)
{
//	++n;	// compile error due to const
	printf("%p in f1()\n", &n);		// shows n's address
}

void f2(const int& n)
{
//	++n;	// compile error as well
			// but it's more fast because this is run by using pass-by-reference
	printf("%p in f2()\n", &n);		// shows n's address
}

int main()
{
	int n = 10;
	printf("%p in main()\n", &n);	// shows n's address

	f1(n);
	f2(n);

	return 0;
}

