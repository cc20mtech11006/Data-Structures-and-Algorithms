// Finding 1 unique number in a set of all duplicates excluding 1 number.
//EX : a[] = {1 2 3 2 3 5 1} --------------- output : 5

#include<iostream>
using namespace std;

int unique(int arr[], int n){
	int xorsum=0;
	for(int i=0;i<n;i++){
		xorsum = xorsum^arr[i];
	}
	return xorsum;
}
int main(){
	int a[]= { 1, 2 , 3, 2, 5, 5, 1};
	cout << "Unique Number = "<< unique(a,7);
}
