// Phone Keypad word combinations. Print all possible combination of words that can be formed by using by pressing digits in keypad
// Ex: Input : 23 ------------------  Output: ad ae af bd be bf cd ce cf   (since 1="abc", 2= "def")

#include<iostream>
#include<string>
using namespace std;

string keyPadArr[]= {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

//Recursive function to print combinations of strings using entered digits.
void keypad(string s, string ans){       // s indicate entered digits string Ex: "23", ans indicate combination result. At first its initialized to empty ""

	if(s.length()==0){
		cout << ans << endl;       // Termination condition
		return;
	}
	
	char ch = s[0];
	string code = keyPadArr[ch -'0'];    // code for entered number
	string rest_of_string = s.substr(1);
	
	for(int i=0;i<code.length();i++){
		keypad(rest_of_string, ans+code[i]);
	}
}
int main(){
	keypad("23","");
}
