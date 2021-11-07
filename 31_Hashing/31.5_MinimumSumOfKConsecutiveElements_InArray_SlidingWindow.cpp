// Find the Minimum sum of k consecutive elements in an array-------Sliding window technique
// Ex: a[] = {-2, 10, 1, 3, 2,-1, 4, 5} , Given k = 3 ---------- Output: 4 (since sum{3, 2, -1} = 4 is the least of all 3 element sub arrays)

#include<iostream>
#include<vector>
using namespace std;

int main(){
	cout << " Enter number of elements in array: ";         //8
    int n;
    cin >> n;
    vector<int> a(n);

    cout << " Enter Array elements : ";   // -2 10 1 3 2 -1 4 5
    for(int i=0; i<n; i++){
   	    cin >> a[i];
    }
    int k;
    cout << " Enter K : ";              // 3
    cin >> k;
    
    int curr_sum =0;
    for(int i=0; i<k; i++){          // First window sum
    	curr_sum = curr_sum + a[i]; 
	}
	
	int min_sum = curr_sum;
	for(int i=0; i<=n-1-k; i++){
		curr_sum = curr_sum + a[k+i] - a[i];        // Add next element remove previous first element - Slide the window by 1 element
		min_sum = min(curr_sum, min_sum);
	}
	cout << " Minimum sum of K Consecutive elements = "<< min_sum;
}
