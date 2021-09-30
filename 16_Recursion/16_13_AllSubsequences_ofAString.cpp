// Generate all subsequences of a given string
#include<bits/stdc++.h>
using namespace std;
void allSubStrings(string s, string ans){
	if(s.length()==0){
		cout << ans<<endl;
		return;
	}
	char ch = s[0];
	string rest_of_string = s.substr(1);
	
	allSubStrings(rest_of_string, ans);
	allSubStrings(rest_of_string, ans+ch);
}

int main(){
	string s;
	cout << "Enter string : ";
	cin >> s;
	allSubStrings(s, "");
	return 0;
}
