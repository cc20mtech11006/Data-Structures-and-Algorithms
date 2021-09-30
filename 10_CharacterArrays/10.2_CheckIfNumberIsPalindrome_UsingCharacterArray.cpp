//Check if a number is palindrome using character array

#include<iostream>
using namespace std;

int main(){
	cout<< "Enter size of palindrome: ";
	int n;
	cin>> n;
	
	char a[n+1];
	cout<<"enter palindrome: ";
	cin>>a;
	bool check= true;
	for(int i=0; i<n;i++){
		if(a[i]!=a[n-i-1]){
			check = false;
		}
	}
	if(check==true){
		cout<< "Number is palindrome";
	}
	else{
		cout<< "Number is not a palindrome";
	}
}
