// Input and output elements in array
#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of array elements : ";
	cin >>n;
	int arr[n];
	// input array elements
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// output array contents
	for(int i=0;i<n;i++){
		cout<<arr[i]<<'\t';
	}
	return 0;
}
