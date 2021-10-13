#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverse(string s){
	cout << s << endl;
	stack<char> st;
	for(int i=0;i<s.length();i++){ 
	 char c = s[i];       
		st.push(c);
	}
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}cout << endl;
}


int main(){
	string s = "Climate Change MTECH IIT Hyderabad sravani";
	reverse(s);
}
