// Print 1 to n numbers in increasing and decreasing order using recursion
#include<iostream>
using namespace std;
void dec(int n){
	if(n==1){
		cout << " 1 "<<endl;
		return;
	}
	cout << " "<<n;   // prints n in order of function call
	dec(n-1);         // tail recursion.
}
void inc(int n){
	if(n==1){
		cout << " 1";
		return;
	}
	inc(n-1);
	cout << " "<< n;	// head recursion. cout statements will be in order of popping activation functions in call stacks. Hence reverse order of function call.
}
int main(){
	cout << "enter a number : ";
	int n;
	cin >> n;
	dec(n);
	inc(n);
}
