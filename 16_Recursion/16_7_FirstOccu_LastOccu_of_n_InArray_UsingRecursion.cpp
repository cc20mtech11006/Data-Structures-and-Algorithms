// Print first occurence and last occurence of a given number in an array
//Ex a[] = { 4 2 1 2 5 2 7}  key =2; ----------- Output : first occurrence = 1, last occurence = 5

#include<iostream>
using namespace std;
int firstOcc(int a[], int n, int key, int i){
	if(i==n){
		return -1;
	}
	if(a[i]==key){
		return i;
	}
	else{
		return firstOcc(a, n, key, i+1);
	}
}
int lastOcc(int a[],int n, int key){
	if(n<=0)   return -1;

    if(a[n-1] == key)
        return n-1;
    else
        return lastOcc(a, n-1, key);
}

int main(){
	int n,  key;
	cout << "Enter size of array : ";
	cin >> n;
	int a[n];
	for(int i=0; i<n;i++){
		cin >> a[i];
	}
	cout << "Enter target number to find first and last occurences : ";
	cin >> key;
	cout << "First Occurance = "<< firstOcc(a,n, key,0)<<endl;
    cout << "Last Occurance = "<< lastOcc(a,n,key)<<endl;
}
