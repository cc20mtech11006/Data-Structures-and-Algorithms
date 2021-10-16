#include<iostream>
#include<climits>
using namespace std;

int main(){
	int size;
	cout<<"Enter size of array: ";
	cin>>size;
	
	int a[size];
	for(int i=0; i<size; i++){
		cin >>a[i];	
	}
	
	int maxNo = INT_MIN;
	int minNo = INT_MAX;
	for(int i=0; i<size;i++){
		maxNo = max(a[i],maxNo);
		minNo = min(a[i],minNo);
	}
	cout<<"Maximum = "<<maxNo<<endl<<"Minimum = "<<minNo;
	return 0;
}
