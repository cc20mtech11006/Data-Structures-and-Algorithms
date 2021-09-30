// Pointer declaration

#include<iostream>
using namespace std;
int main(){
	int a= 10;
	int *aptr = &a;     // creating pointer for a
	cout << *aptr << endl;
	cout << ++*aptr << " "<<a<< endl;  // updating a using pointer
	

}
