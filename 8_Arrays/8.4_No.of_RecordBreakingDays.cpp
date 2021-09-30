// Number of record breaking days. ---------- 20/9/2021
// Conditions: More no of visitors than all other previous days and more number of visitors than the following day.Then the day is record breaking.
//Ex : 1 2 0 7 2 0 2 2      : Ans = 2 (a[1] = 2, a[3]= 7 are record breaking days)

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin >> n;	
	
	int a[n+1];
	a[n] = -1;   // just assigning following day of last day as -1.
	
	for(int i=0;i<n; i++){
		cin>>a[i];
	} 
	
	if(n==1){
		cout<< "1"<<endl;   // if their is only 1 day in test case
	}
	
	int no_of_rec_brk_days = 0;
	int maxVisitors= -1;
	
	for(int i=0;i<=n;i++){
		if(a[i]>maxVisitors && a[i]>a[i+1]){
			no_of_rec_brk_days++;
		}
		maxVisitors = max(maxVisitors, a[i]);
	}
	
	cout << "Total number of record breaking days = "<<no_of_rec_brk_days;
	return 0;
}
	
	
