// Unordered Set

// Contains unique elements
// Implemented using hashing
// Elements are not in sorted order
// Random access is not possible
// Present in   #include<unordered_Set>    header file

// Time complexities
// Insertion : O(1) in avg case, O(n) in worst case
// Deletion : O(1) in avg case, O(n) in worst case
// Lower bound, upper bound concept is not present in this unordered set

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
	unordered_set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(3);
	
	//Printing elements Method -1
	for(auto i : s){ 
		cout << i<<" ";         // Output : 2 3 1  (No repetitions, elements unordered)
	}
	
	cout << endl;
	
	// Erasing an element
	s.erase(3);     // deletes the element since only unique elements are present in this
	
	for(auto i : s){ 
		cout << i<<" ";         // Output : 2 1 
	}
	cout << endl;
	cout << "size = "<< s.size()<< endl;
	
}
