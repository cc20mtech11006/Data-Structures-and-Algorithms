// Stack implementation using array

#include<iostream>
using namespace std;

#define n 100

 class stack{
 	int *arr;
 	int Top;
 	
 	public:
 	stack(){     // Constructor
 		arr = new int[n];
 		Top = -1;
	 }
	 
	 void push(int x){
	 	if(Top == n){
	 		cout << " Stack Overflow "<< endl;
	 		return;
		 }
		 Top++;
		 arr[Top]=x;
		 cout << " Pushed "<< arr[Top]<<" into stack"<< endl;
	 }
	 
	 void pop(){
	 	if(Top==-1){
	 		cout << " No elements to pop "<< endl;
	 		return;
		 }
		 Top--;
		 cout << " Popped "<< arr[Top+1]<<endl;
	 }
	 
	 int top(){
	 	if(Top==-1){
	 		cout << " No elements at Top "<< endl;
	 		return -1;
	 	}
	 	return arr[Top];
	}
	 
	 int empty(){
	 	return Top==-1;
	 	
	 }
 		
 	void display(){
 		cout << " Stack elements are : ";
 		for(int i=0;i<=Top; i++){   
 			cout << arr[i]<< " ";
		 } cout << endl;
	 }
 };
 
 int main(){
 	stack st;
 	st.push(2);
 	st.push(3);
	st.push(4);
	st.display();
	cout << " Element at top currently = "<< st.top()<<endl;
	
	st.pop();
	cout << " Element at top currently = "<< st.top()<<endl;
	st.pop();
	st.pop();
	cout << " Stack empty = "<<st.empty()<< endl;
 }
