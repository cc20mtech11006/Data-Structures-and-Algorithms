// Functions - Printing prime numbers between two numbers - 4-1-2021
#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int);

int main(){
	int a, b, k;
	cout << " Enter two numbers: "<< endl;
	cin >> a >> b;
	if(a>b){
		k = a;
		a = b;
		b = k;		
	}
	for(int i=a; i<=b; i++){
		if(isPrime(i)){
			cout << i << " ";
		}
	}
	return 0;
}

bool isPrime(int num){
	if(num==1){
		return false;
	}
	for(int i=2; i<=sqrt(num);i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
