// Tower of hanoi. 
//Given n rings big to small on one source rod. We have to move all ring from source rod to destination rod with the help of a 3rd helper rod.
// Condition: Large ring must always be placed below small rings.

#include<iostream>
using namespace std;

void toi(int n, string src, string dest, string helper){
	if(n==0){
		return;
	} 
	toi(n-1, src, helper, dest);                         // Moving n-1 small rings from source to helper
	cout << " Move ring from " << src << " to "<< dest << endl;   // Moving largest ring from source rod to destination rod
	toi(n-1, helper, dest, src);
}
int main(){
	int n;
	cout << "Enter number of rings : ";
	cin >> n;
	string src = "A", dest = "C", helper = "B";
	toi(n, src, dest, helper);
}
