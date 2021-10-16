// Given an array of 0's and 1's. We have to find length of largest possible consecutive one's in array. We can change upto K 0's to 1's.
// Ex: a[] = { 1 1 1 0 0 1 1 1 1 0] , k = 2 ------- Output = 9 (we can replace middle 2 0's to 1's. we get 9 consecutive 1's)

#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cout <<"Enter number of elements in vector: ";
	cin >> n;
	cout << "Enter array elements. Must be 1's or 0's : ";
	vector<int> v(n);
	for(int &i : v){
		cin >> i;
	}	
	cout << "Enter k. Number of replacable 0's : ";
	cin >> k;
	
	int zero_count = 0, ptr = 0, max_len = 0; 
	
	for(int i = 0; i < n; i++){
		if(v[i]==0){
			zero_count++;
		}
		while(zero_count > k){  // if zero count exceeds k in our window then move the window right using pointer ptr
			if(v[ptr]==0){
				zero_count--;
			}
			ptr++;
		}
		max_len = max(max_len, i-ptr+1);
	}
	cout << "Max consecutive 1's = "<< max_len;
}

