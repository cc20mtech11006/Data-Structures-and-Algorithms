//Find no of numbers between 1 and 1000 that are divisible by 5 or 7
//(A union B)-(A intersection B)

#include<iostream>
using namespace std;

int gcd(int a, int b){
	int rem;
	int temp = max(a,b);
	if(temp !=a){
		b =a;
		a = temp;
	}
	while(b!=0){
		rem = a%b;
		a = b;
		b = rem;
	}
	return a;
}

int divisible(int n, int a, int b){
	int c1 = n/a;                 // Divisible by a or 5
	int c2 = n/b;                 //Divisible by b or 7
	int c3 = n/(a*b/gcd(a,b));        // divisible by a*b or 35 (repetitions)    n/lcm(a,b)
	return c1+c2-c3;
}
int main(){
	int n,a,b;
	cout << "Enter max range: ";
	cin >> n;
	cout << "Enter two  numers to find no of divisors: ";
	cin >> a>>b;
	cout << "No of integers divisible by "<< a <<" or " << b <<" : "<< divisible(n,a,b);
	return 0;
}
