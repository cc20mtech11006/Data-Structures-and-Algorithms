// If Else - Maximun of 3 numbers : 31-12-2020
#include<iostream>
using namespace std;

int main(){
	int a, b, c;
	cout << "Enter 3 numbers to find maximum" << endl;
	cin >> a >> b >> c;
	if (a>b){
		if (a>c){
			cout << " Maximum = " << a << endl;   // a>b, a>c
			}
		else
			cout << " Maximum = " << c << endl;   // a>b, c>a
	}
	else{
		if (b>c){
			cout << " Maximum = " << b << endl;  // b>a, b>c
			}
		else
			cout << " Maximum = " << c << endl;  // b>a, c>b
	}
	return 0;
}
