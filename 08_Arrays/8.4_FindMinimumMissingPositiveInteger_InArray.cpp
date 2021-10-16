// Find the minimum positive number from a given array of numbers including 0.
// Ex: a[] = {0 -9 1 3 -4 5} ---------- Output = 2 ( since 0 1 3 are present, 2 is the minimum +ve number missing)

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	int a[n];	
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	
	const int N = 1e3+2;
	bool check[N];         // just like bucket we create an boolean array of positive indices 
	for(int i=0;i<N;i++){
		check[i]=0;
	}
	
	for(int i=0;i<n;i++){
		if(a[i]>=0){
			check[a[i]]=1;
		}
		i++;
	}
	
	int min_int=-1;
	for(int i=1;i<N;i++){
		if(check[i] != 1){
			min_int = i;
			break;
		}	
	}
	cout<< min_int<<endl;
}
