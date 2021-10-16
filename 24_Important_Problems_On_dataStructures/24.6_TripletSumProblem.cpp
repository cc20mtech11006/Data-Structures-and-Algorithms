// Triplet sum Problem ----To find whether a triplet existsin array such that their sum = target
// Ex: a[] = { 6, 9, 8 1, 7 ,12, 3} , target = 24 ------- Output : True;   since (6,12,3) sum is 24
// Time complexity : O(nlogn + n^2) = O(n^2)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;         // no of elements in vector
	int target;    // Target sum
	bool found = false;
	cout << "Enter number of elements in array : ";
	cin >> n;
	vector<int> arr(n);
	for(auto &num: arr){            // Inputting vector elements
		cin >> num;
	}

	cout << "Enter Target : ";    // Inputting target sum
	cin >>target;
	
	cout << "target = "<< target;
	 
	sort(arr.begin(),arr.end());   // Sorting vector elements  O(nlogn)
	
	for(int i=0;i<n;i++){
		int low_pointer = i+1;   
		int high_pointer = n-1;
		
		while(low_pointer < high_pointer){
			int current = arr[i]+arr[low_pointer]+arr[high_pointer];
			
			if(current == target){
				found = true;
			}
			
			if(current < target){
				low_pointer++;
			}
			else{
				high_pointer--;
			}
		}
	}
	if(found == true){
		cout <<"Triplet exist"<<endl;
	}
	else{
		cout << "Triplet doesnot exist"<<endl;
	}
	return 0;
}
