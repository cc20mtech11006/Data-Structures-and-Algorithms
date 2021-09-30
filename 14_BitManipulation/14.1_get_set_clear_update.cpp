// Bit Manipulation - get bit, set bit, clear bit, update bit
#include<iostream>
#include<string>
using namespace std;

int getbit(int n, int pos){
	return ((n & (1<<pos))!=0);
}

int setbit(int n, int pos){
	return (n | (1<<pos));
}

int clearbit(int n, int pos){
	return (n & ~(1<<pos));
}

int updatebit(int n, int pos, int value){
	int mask = ~(1<<pos);
	n = n & mask;
	return (n | value<<pos);
}

int main(){
	cout << getbit(5,2)<<endl;   // getbit(Number, position)  we have to find what bit is present at that position
	cout << setbit(5,1)<<endl;  // setbit(Number, position)   we have to set the bit at position to 1.
	cout << clearbit(5,2)<<endl;  // clearbit(Number , position)  we have to clear the bit at position to 0.
	cout << updatebit(5,3,1)<<endl;  // updatebit(Number , position, value)  we have to update the bit at position to value.
}
