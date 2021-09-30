// Find if a number is power of 2 using bit manipulation

#include<iostream>
using namespace std;

int powerOf2(int num){
	return (num & (num-1));       // if 8 is num    1000 & 0111 = 0000. For every power of 2, anding num and num-1 gives 0
}

int main(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	if(powerOf2(num) == 0){
		cout << num <<" is power of 2 "<<endl;
	}
	else{
		cout << " Not a power of 2"<<endl;
	}
}
