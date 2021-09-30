// Sum of n natural numbers using recursion
#include<iostream>
using namespace std;
int sum_of_n_naturals(int n){
	if(n == 1){
		return 1;
	}
	return n + sum_of_n_naturals(n-1);
}
int main(){
	int n;
	cout << "Enter max range : ";
	cin >> n;
	cout << sum_of_n_naturals(n);
}
