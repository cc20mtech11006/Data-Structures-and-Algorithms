// To Check if a number is Prime, Amstrong and reverse the number- 2-1-2021
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int num,reverse,flag=0;
	cout << " Enter the number: "<< endl;
	cin >> num;
	//Checking the number is Prime or not
	for(int i=2; i<=sqrt(num);i++){
		if(num%i==0){
			cout << "Number is non prime" << endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout << "Number is prime"<< endl;
	}
	
	//Checking the number is amstrong or not 153 = 1^3+5^3+3^3 . 
	//If Sum of cubes of digits is equal to the original number, then the number is Amstrong.
	int sum=0;
	flag = num;
	while(flag>=1){
		sum = sum + pow((flag%10),3);
		flag = flag/10;
	}		
	if(sum==num){
		cout << "The number is Amstrong"<< endl;
	}
	else{
		cout << "The number is Not Amstrong" << endl;
	}
	
	//Reversing the number
	reverse =0;
	flag=num;
	while(flag>=1){
		reverse = reverse*10 +flag%10;
		flag = flag/10;
	}
	cout << "Reverse of number is : "<< reverse;
	
}
