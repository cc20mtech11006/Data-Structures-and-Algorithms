//Convert String into Uppercase and lower case
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s = "sgygciuecei";
	
	//Bruteforce approach
	//Converting to Upper Case
	for(int i =0; i<s.length(); i++){      
		if(s[i]>='a'&& s[i]<='z'){
			s[i] -= 32;                  // 32 since a-A in ascii = 32
		}
	}
	cout << s<<endl;
	//Converting to Lower Case
	for(int i =0; i<s.length(); i++){      
		if(s[i]>='A'&& s[i]<='Z'){
			s[i] += 32;                  // 32 since a-A in ascii = 32
		}
	}
	cout << s<<endl;
	
	// 2nd Method using string function transform
	// Convert to upper case
	transform(s.begin(),s.end(),s.begin(),::toupper);   //transform(string start, string end, index from where to capitalize, ::toupper)
	cout << s<<endl;
	// Convert to lower case
	transform(s.begin(),s.end(),s.begin(),::tolower);   //transform(string start, string end, index from where to capitalize, ::tolower)
	cout << s<<endl;
}
