// Move all x to end in a string
//Ex : axftrxxghtxut ------------ output : aftrghtutxxxx
#include<bits/stdc++.h>
using namespace std;

string moveAllx(string s){
	if(s.length()==0){
		return "";
	}
	char ch = s[0];
	string ans = moveAllx(s.substr(1));
	if(ch == 'x'){
		return ans+ch;            // if ch = x, then print x at last
	}
	else{
		return ch+ans;            // if ch!= x, then print whatever element it is and continue recursion with substring
	}
}
int main(){
	string s;
	cout << "Enter string : ";
	cin >> s;
	cout << moveAllx(s);
	return 0;
}
