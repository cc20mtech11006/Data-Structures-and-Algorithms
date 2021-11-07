// Hashing STL functions
// Hash table is represented as map or unordered map in c++ stl'
// Both Map and Unordered_map use key value pairs as input
// Map - insertion- O(logn), searching - O(logn), It is implemented using Red balck trees
// Unordered Map - insertion - O(1), search- O(1), It is an array of buckets

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	map<int, int> hashmap;
	hashmap[2] = 35;
	cout << hashmap[2] << endl;
	cout << hashmap[1]<<endl;     // has 0 since we didn't assign any value
	
	map<string, int> hash;
	hash["sravani"] = 678;
	hash["bamu"] = 567;
	hash["lachi"]= 676;
	
	hash.insert({{"chandu", 1000},{"vijji",999}});
	map<string, int> ::iterator iter;
	for(iter = hash.begin(); iter!=hash.end(); iter++){
		cout << (*iter).first<<" "<< (*iter).second << endl;
	}
	
	cout << "Size = "<<hash.size()<<endl;
	cout << "Max Size = "<< hash.max_size()<<endl;
	cout <<"is empty or not " << hash.empty()<<endl;

	
}
