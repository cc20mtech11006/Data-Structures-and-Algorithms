// Finding 2 unique numbers in a set of all duplicates excluding 2- number.
//EX : a[] = {1 2 3 2 3 5 1 7} --------------- output : 5, 7

#include<iostream>
using namespace std;
int findSetBit(int n, int pos){
	return ((n & (1<<pos))!=0);
}
void unique(int a[],int n){
	int xorsum=0;
	for(int i=0;i<n;i++){
		xorsum = xorsum^a[i];
	}
	int tempxor = xorsum ;    // storing xorsum of all elements for future finding 2nd unique number
	
	int findFirstsetbit = 0, pos =0;
	while(findFirstsetbit!=1){         // Finding the position of first set bit in xorsum
		findFirstsetbit = xorsum & 1; //since 1&1 =0 ====> it is a set bit
		pos++;
		xorsum = xorsum>>1;	          // remove last bit from xorsum
	}
	
	int newxor =0;
	for(int i=0;i<n;i++){                 //xoring all elements in array which have set bit in pos-1
		if(findSetBit(a[i], pos-1) ){
			newxor = newxor^a[i];
		}
	}
	int second = tempxor^newxor;
	cout << "First Unique Number = "<< newxor << endl;
	cout << "Second Unique Number = "<< second << endl;
}


int main(){
	int a[]= {1,2,3,5,3,2,1,9};
	unique(a,8);
	return 0;
}
