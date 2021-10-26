// Implementing a Set or Ordered Set
// Contains unique elements
// Set is implemented using balanced BST
// Elements are in sorted order
// Random access is not possible. We have to iterate through bst to find element O(logn)
// It is present in #include<set>

// Time complexity : O(logn) for insertion, deletion, lower_bound, upper_bound

#include<iostream>
#include<set>
using namespace std;

int main(){
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(3);
	
	//Printing elements Method -1
	for(auto i : s){ 
		cout << i<<" ";         // Output : 1 2 3  (No repetitions, elements sorted)
	}
	
	cout << endl;
	
	// printing elements Method-2 
	for(auto i = s.begin();  i != s.end(); i++){        // Output : 1 2 3 (No repetitions, elements sorted)
		cout << *i << " ";
	}
	
	cout << endl;
	
	// Printing elements in reverse order
	for(auto i = s.rbegin();  i != s.rend(); i++){        // Output : 3 2 1 (No repetitions rbegin: reverse begin, rend: reverse end)
		cout << *i << " ";
	}
	
	// Size of set
	cout << endl<< "size = "<<s.size()<<endl;
	
	// Erase an element in set
	s.erase(3);                  
	
	for(auto i = s.begin();  i != s.end(); i++){        // Output : 1 2 3 (No repetitions, elements sorted)
		cout << *i << " ";
	}
	cout << endl;
	
	// --------------------------------------------------------------------------
	
	// To form a set in descending order 
	set<int, greater<int>> s1;          // Used to store elements in descending order
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(6);
	for(auto i = s1.begin();  i != s1.end(); i++){        // Output : 6 4 3 2 1 (No repetitions, elements sorted in descending order)
		cout << *i << " ";
	}
	cout << endl<<endl;
	
	set<int> s2;
	s2.insert(1);
	s2.insert(2);
	s2.insert(3);
	s2.insert(4);
	s2.insert(6);
	for(auto i = s2.begin();  i != s2.end(); i++){        // Output : 6 4 3 2 1 (No repetitions, elements sorted in descending order)
		cout << *i << " ";
	}
	cout << endl<<endl;
	
	// Printing lower and upperbound of elements
	
	// lower_bound() returns address of element if found. Otherwise returns next element address
	// upper_bound() always returns next element address
	
	cout << *s2.upper_bound(1)<< endl;       //2
	cout << *s2.lower_bound(1)<<endl<<endl;  //1
	
	cout << *s2.upper_bound(2)<<endl;         //3
	cout << *s2.lower_bound(2)<< endl<<endl;  //2
	
	cout << *s2.upper_bound(3)<< endl;        // 4
	cout << *s2.lower_bound(3)<< endl<<endl;  //3
	
	cout << *s2.upper_bound(4)<< endl;        // 6
	cout << *s2.lower_bound(4)<< endl<<endl;  // 4
	
	cout << *s2.upper_bound(5)<< endl;        // 6
	cout << *s2.lower_bound(5)<< endl<<endl;  // 6
	
	cout << (s2.upper_bound(6)== s2.end())<< endl;  // prints 1 since 6 is the last element. it returns address od end of set
	cout << *s2.lower_bound(6)<< endl<<endl;
	
	cout << (s2.lower_bound(7)==s2.end())<<endl;  // 1  ( 7 not present in set. lower bound of 7 returns next element address which is end of set)
}
