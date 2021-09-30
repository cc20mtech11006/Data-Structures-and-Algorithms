// Printing 3.14 in every place of pi in a given string
//Ex : piiipigytpupiy    ---------- Output : 3.14ii3.14gytpu3.14y
#include<bits/stdc++.h>
#include<string>
using namespace std;
void replace(string str, string target){
	if(str.length()==0){
	return;
	}
	if(str[0]=='p' && str[1]=='i'){
		cout << target;
		return replace(str.substr(2),target);  //if we see pi, print 3.14 and return string after pi, that is after 2 positions.
	}
	else{
		cout << str[0];
		return replace(str.substr(1),target);
	}
}
int main(){
	string str;
	cout<<"Enter string: ";
	cin>>str;
	replace(str, "3.14");
}
