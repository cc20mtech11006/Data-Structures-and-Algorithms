// Break Continue Example - Prime numbers from 2 to n - 1-1-2021

#include<iostream>
using namespace std;

int main(){
	int n;
	int i,j;
	cout << "Enter n : ";
	cin >> n;
	for(i = 2; i <= n; i++){
		for(j = 2; j < i; j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			cout <<i<<" ";		
		}
	}					
	return 0;
}
