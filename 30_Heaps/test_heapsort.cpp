#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(8);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(6);
	sort(v1.begin(), v1.end(), greater<int>());
	for(auto i : v1){
		cout << i<< " ";
	}

}
