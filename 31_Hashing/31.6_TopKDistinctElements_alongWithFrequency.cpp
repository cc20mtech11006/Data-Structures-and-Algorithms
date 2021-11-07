// Find the k top most distinct elements in an array and print them along with their frequency
// Ex: a[] = {1,2,2,2,3,4} , k = 3 -------------Output: 2, 3    1, 1    (Element 2 frq 3, element 1 freq 1)

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cout << "Enter number of elements in array : ";
	cin >> n;
	
	vector<int> a(n);
	cout << "Enter array elements : ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int k;
	cout << "Enter k : ";
	cin >> k;
	
	map<int, int> freq;
	for(int i=0; i<n; i++){           // In hash map update frequencies of elements until number of elements in hashmap becomes k
		int presentSize = freq.size();
		if(freq[a[i]]==0 && presentSize==k){
			break;
		}
		freq[a[i]]++;
	}
	
	vector<pair<int, int>> ans;    
	map<int, int> :: iterator it;
	for(it = freq.begin(); it!= freq.end(); it++) {  // Shifting contents of hashmap into vector<pair> ans
		if((*it).second!=0){
			pair<int, int> p;
			p.first = (*it).second;
			p.second = (*it).first;
			ans.push_back(p);
		}
	}
	
	sort(ans.begin(), ans.end(), greater<pair<int,int>>());  // Sorting vecot<pair> ans
	
	for(int i=0; i<ans.size(); i++){          // Printing contents of ans
		cout << ans[i].second <<" "<<ans[i].first;
		cout << endl;
	}
}
