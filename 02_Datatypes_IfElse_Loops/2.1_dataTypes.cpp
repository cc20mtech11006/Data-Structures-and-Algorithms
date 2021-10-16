// Data Types in C++ : 31-12-2020
#include<iostream>
using namespace std;

int main(){
// Fundamental datatypes
	int i;      // integer 4B (Range : -2^31 to 2^31-1)
	float f;	// floating point number 4B (Range : -2^31 to 2^31-1) with 7 decimal places.
	char c;     // characters like alphabets, special characters. Based on ASCII values, 1B storage.
	double d;   // Long floating point number. Upto 15 decimal digits. 8B memory storage.
	bool b;     // TRUE or FALSE. 1B memory storage.
	wchar_t wc; // wide character. 2B memory storage. To store unicode characters.
/*	void v;(Wrong)  A void pointer can point to a function, but not to a class member in C++. 
	You cannot declare a variable of type void */
	cout << "size of int = " << sizeof(i) << endl;
	cout << "size of float = " << sizeof(f) << endl;
	cout << "size of char = " << sizeof(c) << endl;
	cout << "size of double = " << sizeof(d) << endl;
	cout << "size of bool = " << sizeof(b) << endl;
	cout << "size of wide character = " << sizeof(wc) << endl<< endl;
// Type Modifiers
	signed int si;
	unsigned int ui;
	short s;
	long l;
	long long int lli;
	unsigned long long ull;
	long double ld;
	signed char sc;
	unsigned char uc;
	cout << "size of signed int = " << sizeof(si) << endl;
	cout << "size of unsigned int = " << sizeof(ui) << endl;
	cout << "size of short = " << sizeof(s) << endl;
	cout << "size of long = " << sizeof(l) << endl;
	cout << "size of long long int = " << sizeof(lli) << endl;
	cout << "size of unsigned long long = " << sizeof(ull) << endl;
	cout << "size of long double = " << sizeof(ld) << endl;
	cout << "size of signed char = " << sizeof(sc) << endl;
	cout << "size of unsigned char = " << sizeof(uc) << endl;
	return 0;
/* Derived data types
	 array
	 function
	 pointer
	 reference
	 
 User defined datatypes
	 class
	 structure
	 union
	 ennumeration */
}
