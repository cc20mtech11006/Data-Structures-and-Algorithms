// Printing Array elements using pointer

#include<iostream>
using namespace std;
int main(){
	int a[]= { 10, 20 ,30};
	int *ptr = a;  //No & because a is already address of a[0]
	for(int i=0;i<3;i++){
		cout << *ptr <<endl;
		ptr++;     // Going to next index &a[i] + 4 (since next index is 4B later)
	}
	cout << "---------------------------"<<endl;
	// One more way. Using a as pointer itself
	for(int i=0;i<3;i++){
		cout << *(a+i) <<endl;
	}
	
}
