// Linear search in array - 19/09/2021

#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			return i;	}   //returns index of key if condition satisfies
	}
	return -1;  //if key not found in array
}

int main(){
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
	
	int index = linearSearch(arr, size, key);
	 if(index !=-1)
	 cout << "Index of key in array = "<< index;
	 else
	 cout<<"Ket not found in array";
}
