// Finding maximum and minimum in array
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter number of array elements : ";
	cin >>n;
	int arr[n];
	// input array elements
	cout<<"Enter "<<n<<" elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
		
	int maxNo = arr[0];
	int minNo = arr[0];
	for(int i=0;i<n;i++){
		cout<<arr[i]<<'\t';
	}
	for(int i =0; i<n; i++){
		if(arr[i]>maxNo){            // or max = max(max, arr[i]);
			maxNo = arr[i];
		}
		else if(arr[i]<minNo){
			minNo = arr[i];
		}
	}
	cout<<endl<<"Maximum no : "<< maxNo <<endl<<"Minimum no : "<< minNo;
	return 0;
	}

