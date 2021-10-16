//Functions - Pascal Triangle 
#include<iostream>
#include"6.2.1_Functions_Fibanacci_Factorial_ncr.cpp"
using namespace std;

int main(){
	int len;
	cout << "Enter a number to print fibanacci and factorial: ";
	cin >> len;
	cout << "Fibanacci series: ";
	for(int i=0; i<len; i++){
		cout << fib(i)<< " ";
	}
	cout << endl << "Factorial = " << fact(len)<< endl;
	int n,r;
	cout << "Enter n,r for finding ncr : ";
	cin >> n >> r;
	cout << "Value of " << n << "C" << r << " = " << ncr(n,r) << endl;
	int rows;
	cout << "Enter number of rows to print pascal triangle: ";
	cin >> rows;
	pascal(rows);
	return 0;
}

