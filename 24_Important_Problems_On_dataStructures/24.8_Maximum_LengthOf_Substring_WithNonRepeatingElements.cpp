// Given a string s. We have to find maximum length of substring which has non repeating chracters
// Ex : s= abcbdeac    ------ output = 5 (cbdea)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	string s;
	cout << "Enter string: ";
	cin >> s;
	vector<int> dummy(256, -1) ;  // dummy vector to store index of alpahbet in string in ascii alphabet position. All the positions are initialized to -1
	int maxLen = 0, start_ptr = -1;
	
	for(int i=0;i<s.size();i++){
		if(dummy[s[i]] > start_ptr){     
			start_ptr = dummy[s[i]];      // start_ptr updates to index where we have seen a repeated character previously. Uppdating window of string using start_ptr
		}
		dummy[s[i]] = i;      // update dummy[character] = index of character in string. We are storing the index where we have seen an alphabet lastly.
		maxLen = max(maxLen, i-start_ptr);
	}
	cout << "Maximum length of substring with no repeating elements = "<< maxLen;
	return 0;
}
