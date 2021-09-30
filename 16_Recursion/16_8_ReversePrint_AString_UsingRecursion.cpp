// Reverse print a string using recursion
// Ex: sravani  ------ Output: inavars
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void reverse(string str){
	if(str.length()==0){
		return;
	}
	reverse(str.substr(1));   // sending substring from index 1.
	cout << str[0];           // Printing first elemnet from every activation cell str. Since it is head recursion order will be reversed.
}

int main(){
	string str;
	cout<<"Enter string: ";
	cin>>str;
	reverse(str);
}
