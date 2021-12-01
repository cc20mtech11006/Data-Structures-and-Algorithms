// Given an array A, divide half elements in in A and insert in another array in B
// Find the maximum and minimum values of differences between two arrays
// Difference is defined as abs(A[i]-B[i])

// Approarch:
// We don't need to create another array B to find max and min differences
// Max difference is obtained by dividing sorted array A in the middle and calculating a[n/2+i]-a[i] for each element. sum all max differences
//Min difference is obtained by taking all odd elements in array A and all even elements in B . Calculate a[2*i+1]-a[2*i] and sum up to get min difference

// Ex: a[] = {12, -3, 10, 0} ---------- Output : max = 25, min = 5

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cout << "Enter size of array : ";
	int n;
	cin >> n;
	vector<int> a(n);
	cout << "Enter array elements : ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	long long max =0;
	long long min =0;
	for(int i=0; i<n/2; i++){
		max += a[n/2+i]-a[i];
		min += a[2*i+1]-a[2*i];
	}
	
	cout << "Max = "<< max<<endl;
	cout << "Min = "<<min << endl;		
}
