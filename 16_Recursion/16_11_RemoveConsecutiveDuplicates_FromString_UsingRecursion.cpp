// Remove consecutive duplicates in a given string using recursion
// Ex : aaabbccccedddee ----------- output : abcede
#include<bits/stdc++.h>
#include<string>
using namespace std;
string remConsecDup(string s){
	if(s.length()==0){
		return "";
	}
	char ch = s[0];       
	string ans = remConsecDup(s.substr(1));
	if(ch!=ans[0]){                        // if previous character not equal to 1st character of substring. print previous character + substring     
		return (ch + remConsecDup(s.substr(1)));
	}
	else{
		return remConsecDup(s.substr(1));
	}
}

int main(){
	string s;
	cout << "Enter string : ";
	cin >> s;
	cout << remConsecDup(s);
	return 0;
}
