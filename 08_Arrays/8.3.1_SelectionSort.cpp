// Selection Sort in array - 19/9/2021
// Time complexity O(n) = n^2 ----------------------------- (n-1 + n-2 + n-3 + ----- + 1) = n(n+1)/2
#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter size of array: ";
	cin >> size;
	
	int arr[size];
	for(int i=0;i<size; i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[i]){
				int temp = arr[i];
				arr[i]= arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"Sorted Array :  ";
	for(int i=0;i<size;i++){
		cout << arr[i]<<" ";
	}
	return 0;
}
