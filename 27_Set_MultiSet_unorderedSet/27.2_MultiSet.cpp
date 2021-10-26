// MultiSet
// Can contain duplicates
// Implemented using balanced BST
// Elements are in sorted order
// Random access is not possible. We have to iterate through bst to find element O(logn)
//It is present in #include<set>

// Time complexity : O(logn) for insertion, deletion, lower_bound, upper_bound

#include<iostream>
#include<set>
using namespace std;

int main(){
	multiset<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(3);
	
	//Printing elements Method -1
	for(auto i : s){ 
		cout << i<<" ";         // Output : 1 2 3 3 3 (With repetitions, elements sorted)
	}
	cout << endl;
	
	cout << "size = "<< s.size()<< endl;
	
	// Erase an element -------- All instances will be erased
	s.erase(3);
	
	for(auto i : s){ 
		cout << i<<" ";         // Output : 1 2  (all instances of 3 are erased)
	}
	cout << endl;
	cout << "size = "<< s.size()<< endl;
	
	// Method to erase only 1 instance of an element
	s.insert(3);
	s.insert(3);
	s.insert(3);
	
	s.erase(s.find(3));     // only deleted first occurence of 3
	
	for(auto i : s){ 
		cout << i<<" ";         // Output : 1 2 3 3 (only 1 instance of 3 is erased)
	}
	cout << endl;
	cout << "size = "<< s.size()<< endl;
	
}
