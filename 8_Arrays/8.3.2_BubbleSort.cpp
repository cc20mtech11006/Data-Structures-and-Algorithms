// Bubble sort - 19-9-2021   ----------  O(n) = n^2
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int arr[n];
	for(int i=0;i<n; i++){
		cin>>arr[i];
	}

int i, j; 
    for (i = 0; i < n-1; i++) {     
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j]= arr[j+1];
            arr[j+1]=temp;
        }
    }
cout << "Sorted Array : ";
for (i = 0; i < n; i++) {
	cout << arr[i]<<" ";
}
return 0;
}
