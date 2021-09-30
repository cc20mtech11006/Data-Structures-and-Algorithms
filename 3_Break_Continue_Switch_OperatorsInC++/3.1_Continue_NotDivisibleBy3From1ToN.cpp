// Break Continue Example - Print numbers not divisible by 3 from 1 to n - 1-1-2021
#include<iostream>
using namespace std;

int main(){
	int num;
	cout << "Enter the maximum number : " << endl;
	cin >> num;
	for(int i=1;i<=num;i++){
		if(i%3==0){
			continue;
		}
		if(i>num){
			break;
		}
		cout << i<< " ";
	}
	return 0;
}
