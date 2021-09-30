// Using bit manupilation print all subset of elements in an array
#include<iostream>
using namespace std;
void subsetOfElements(int a[],int n){
	for(int i = 0;i< (1<<n) ;i++){
		for(int j =0;j<n;j++){
			if(i & (1<<j)){
				cout << a[j];
			}
		}
		cout << endl;
	}
}
int main(){
	int a[] = {1,2,3,4};
	subsetOfElements(a,4);
	return 0;
}
