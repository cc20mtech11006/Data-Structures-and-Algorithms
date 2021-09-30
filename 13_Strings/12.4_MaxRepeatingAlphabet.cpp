//  Find the alphabet in the string which is repeating most number of times. Assume lower case string is given

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cout <<"Enter a lowercase string : " ;
	cin >>s;
	
	int freq[26]; //count array from a to z
	for(int i=0;i<26;i++){
		freq[i]=0;
	}
	
	for(int i=0;i<s.length();i++){
		freq[s[i]-'a']++;
	}
	
	int max_freq= INT_MIN; 
	char ans_alphabet;
	for(int i=0; i<25;i++){
		if(freq[i]> max_freq){
			max_freq = freq[i];
			ans_alphabet = i+'a';
		}
	}
	
	cout << "Max repeated alphabet = "<< ans_alphabet << "  Frequency = "<<max_freq;
}
