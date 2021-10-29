//Given an array with n elements that represents n positions along a straight line.
// Find K elements such that the minimum distance between any two elements is the maximum value possible

// Ex : [11, 2, 7, 5 , 1 12] , k = 3 =======> we have to choose 3 elemets from array such that pair diffrence is maximum
// Output : Maximum distance = 5  (The three elemets are 1, 7, 12)

#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
	int pos = arr[0], elements = 1;
	
	for(int i=1; i<n; i++){
		if(arr[i]- pos >= mid){
			pos = arr[i];
			elements++;
			if(elements == k){
				return true;
			}
		}
	}
	return false;
}
int largestMinDistance(int arr[], int n, int k){  // n number of elements in array, k is number of elements we want to pick
	sort(arr, arr+n);
	int result =  -1; // Final maximum dist is stored in this
	int left = 1, right = arr[n-1];
	
	while(left < right){
		int mid = (left + right)/2;
		if(isFeasible(mid,arr,n,k)){
			result = max(result, mid);
			left = mid+1;
		}
		else{
			right = mid;
		}
	}
	return result;
}


int main(){
	int arr[]= {1,2,8,4,9};
	int n = 5;
	int k = 3;
	cout << "largest min distance is: "<<largestMinDistance(arr, n, k)<<endl;
}
