#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int>  v;   // we are initializing a vector named v with int datatype
	v.push_back(1);   // we are entering number 1 into vector
	v.push_back(2);   // we are entering number 2 into vector
	v.push_back(3);   // we are entering number 3 into vector   
	v.insert(v.begin(),4);
	for(auto i: v){
		cout<<i<<" ";
	}
	vector<int> vec = {10, 20, 30 ,40};

}
