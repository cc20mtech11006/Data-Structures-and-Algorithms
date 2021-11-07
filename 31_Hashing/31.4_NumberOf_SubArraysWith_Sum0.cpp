//Print number of subarrays with sum 0
// Ex: a[] = [1, -1, 1, -1] ---------- Output = 4 (Subarray swith sum 0 are [1,-1],  [-1, 1],  [1, -1],  [1,-1,1,-1])

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	cout << "Enter number of elements in array: ";
    int n;
    cin >> n;
    vector<int> a(n);

    cout << " Enter Array elements : ";
    for(int i=0; i<n; i++){
   	    cin >> a[i];
    }

   map<int, int> freq;
   int prefix_sum=0;
   
   for(int i=0; i<n; i++){
   		prefix_sum += a[i];    // Finding prefix sum until ith index
   	    freq[prefix_sum]++;    // Updating fequency of particular prefix_sum in corresponding index
   }
   map<int, int> :: iterator it;
   int result =0;
   for(it = freq.begin(); it!=freq.end(); it++){
   		int x = (*it).second;
   		result += x*(x-1)/2;             // In hashmap, the frequnecy implies number of times the particular prefix sum is repeated
   		                                //  A prefix sum frequency = x ====> their are xC2 subarrays whose sum is 0  (from 1 x to another x, midlle array sum is 0)
   		
   		if((*it).first == 0){           // if prefix sum = 0, then include the frequency in result
   			result += (*it).second;
	    }   	
   }
   cout << " Number of subarrays with sum zero = "<<result<<endl;
}
