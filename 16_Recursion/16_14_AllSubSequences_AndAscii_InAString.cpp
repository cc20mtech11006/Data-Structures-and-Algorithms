// Generate all subsequences of a given string including ascii code as a subsequence
// Ex : s ="AB" ---------- Output : B  66  A  AB  A66  65  65B  6566
#include<bits/stdc++.h>
using namespace std;
void allSubStrings(string s, string ans){
	if(s.length()==0){
		cout << ans<<endl;
		return;
	}
	char ch = s[0];
	int asc_code = ch;
	string rest_of_string = s.substr(1);
	
	allSubStrings(rest_of_string, ans);
	allSubStrings(rest_of_string, ans+ch);
	allSubStrings(rest_of_string, ans+to_string(asc_code));
	
}

int main(){
	string s;
	cout << "Enter string : ";
	cin >> s;
	allSubStrings(s, "");
	return 0;
}
