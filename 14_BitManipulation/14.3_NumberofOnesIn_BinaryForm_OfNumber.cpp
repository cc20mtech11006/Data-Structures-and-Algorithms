// Finds number of 1's in binary representation of a number
//Ex: 12: 1011   --------- Output =3
#include<iostream>
using namespace std;
int numOfOnes(int n){
	int count;
	while(n){                 // Each iteration reduces a bit from num  Ex : num = 19 (010011)
		n = (n & (n-1));      // iterstion1 n becomes : 010010, iteration 2 : 010000, iteration 3 : 000000
		count++;               
	}
	return count;
}
int main(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	cout << "Number of 1's in binary form of "<<num<< " = "<<numOfOnes(num)<<endl;
}

