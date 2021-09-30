// Switch Case Example : Simple Calculator - 1-1-2021
#include<iostream>
using namespace std;

int main(){
	int num1, num2;
	cout << "Enter 2 numbers: ";
	cin >> num1 >> num2;
	char op;
	cout << "Enter operator: ";
	cin >> op;
	switch(op){
		case '+': cout << num1+num2 << endl; break;
		case '-': cout << num1-num2 << endl; break;
		case '/': cout << num1/num2 << endl; break;
		case '*': cout << num1*num2 << endl; break;
		default : cout << "Invalid operator" << endl; break;
	}
	return 0;
}
