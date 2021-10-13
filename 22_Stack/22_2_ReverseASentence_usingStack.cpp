// Reverse words in a sentence
// Ex: Climate Change MTECH IIT Hyderabad -------------Output: Hyderabad IIT MTECH Change Climate

#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reverse(string s){
	cout << s<<endl;
	stack<string> st;
	for(int i=0;i<s.length();i++){        
		string word = "";
		while(s[i]!=' ' && i<s.length()){    
			word += s[i];
			i++;
		}
		st.push(word);
	}
	while(!st.empty()){
		cout << st.top()<< " ";
		st.pop();
	}cout << endl;
}


int main(){
	string s = "Climate Change MTECH IIT Hyderabad sravani";
	reverse(s);
}
