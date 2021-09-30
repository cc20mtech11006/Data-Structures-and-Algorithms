// Binary Seach in array - 19/9/2021 ----------------
// Time Complexity : O(n) = logn
#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size, int key){
	int s=0; 
	int e=size;
	int mid;
	while(s<=e){
		mid = (s+e)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if (arr[mid]<key){
			s = mid+1;
		}
		else{
			e = mid -1;
		}
	}
	return -1;
}

int main()
{
	int size;
	cout<<"Enter size of array: ";
	cin >> size;
	
	int arr[size];
	for(int i=0;i<size; i++){
		cin>>arr[i];
	}
	int key;
	cout<<"Enter key to find in array ";
	cin >> key;
	
	int index = BinarySearch(arr, size, key);
	 if(index !=-1)
	 cout << "Index of key in array = "<< index;
	 else
	 cout<<"Ket not found in array";
	 return 0;
}
