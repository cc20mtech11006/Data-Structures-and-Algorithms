// Finding nth fibanacci element
#include<iostream>
using namespace std;
int fib(int n){
	if(n==0 || n==1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}
int main(){
	int n;
	cout << "Enter number : ";
	cin >> n;
	cout << fib(n)<<endl;   // nth fibanacci element
	// To print fibanacci series
	for(int i=0;i<=n;i++){
		cout << fib(i)<<" ";
	}
}
