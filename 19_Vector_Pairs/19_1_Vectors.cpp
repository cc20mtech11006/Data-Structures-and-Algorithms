// Vectors

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int>  v;   // we are initializing a vector named v with int datatype
	v.push_back(1);   // we are entering number 1 into vector
	v.push_back(2);   // we are entering number 2 into vector
	v.push_back(3);   // we are entering number 3 into vector   
	
	vector<int> vec = {10, 20, 30 ,40};
	
	// 3 types of printing vector elements
	for(int i=0;i<v.size();i++){    // traversing vector same as in array
		cout << v[i] << " ";
	}
	cout << endl;
	
	vector<int> :: iterator it;     // traversing vector by taking a iterator pointer
	for(it = vec.begin(); it!=vec.end(); it++){
		cout << *it<< " ";
	}
	cout << endl;
	
	for(auto element:v){           // traversing vector by using auto keyword
		cout << element << " ";
	}
	
	// Poping from vector
	v.pop_back();   // it pops last element 3 same like stack
	
	// Creating vector and repeating elements without using pushback
	vector<int> v1 (3,50);	 // 50 50 50   // 3 implies no of elemts, since second argument  50 is given, it will repeat 3 times
	cout << endl<< "v1 = ";
	for(auto element:v1){        
		cout << element << " ";
	} cout << endl;
	
	// Swapping elements of 2 vector
	swap(v, v1);   // function to swap vector elements
	cout << endl<< "swapping : "<< endl;
	for(auto element:v){        
		cout << element << " ";
	}cout << endl;
	for(auto element:v1){        
		cout << element << " ";
	}
	
	// Sorting in a vector
	vector<int> v3 = { 1,6, 5, 7, 3, 2, 4};
	sort(v3.begin(), v3.end());
	cout << endl<< "Sorting : ";
	for(auto element:v3){        
		cout << element << " ";
	}
}
