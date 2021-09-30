// Operators Example - 1-1-2021

/* Operators are  types
	Arithmetic [(binary +, -, /, *, % ),(unary ++, --)]
	Relational [==, !=, <, >, <=, >=, ]
	Logical    [&&, ||, !]
	Bitwise    [|, &, ^, ~, <<, >>]
	Assignment [=, +=, -=, *=, /=]
	Miscellnus [sizeof(), ?:, comma(,), typecast-int(3.14)]
*/

#include<iostream>
using namespace std;

int main()
{
int a = 5, b=4;
a = (1, 2, 3);  // finally a gets 3 
b = 1,2,3;      // b gets 1  [say (b=1),2,3]
cout <<a << "  " << b << endl;

int x = 2;
(x & 1) ? cout <<"True" : cout<<"False";

return 0;
}
