// Basic String STL inbuilt functions

#include<iostream>
#include<algorithm> //for sort() function
#include<string> // Necessary STL library for string functions
using namespace std;

int main(){
	// string variable creation
	string s = "Sravani";
	cout << s << endl;
	
	// Taking input from user
	string str;
	cout << "Enter a string : ";
	cin >> str;
	cout << str << endl<<endl;
	
	// Initializing string with same character repeated several times
	string s1(5, 'n');   // n repeated 5  times
	cout << s1<< endl<<endl;          // nnnnn
	
	// getline() Function to take a sentence as input. Since space in cin is considered as send of string
	cout << "enter a sentance: ";
	cin.ignore();   // Ignores previous inputs from previous cin s
	string s2;
	getline(cin, s2);
	cout << s2 << endl << endl;
	
	//append two strings into one
	string s4 = "fam", s5 = "ily";
	s4.append(s5);                   // value of s4 changes  to family in append
	cout << s4 << endl<< endl;
	
	//Concatenate two strings
	string s6 = "sra", s7 = "vani";
	cout << "Concatenating "<< s6 << " and " << s7 <<"  - "<< s6+s7 << endl << endl;
	
	// Accessing string elements
	string s8 = "unknown";
	cout << s8[0]<< endl<< endl;   // Just like character array give index to access element
	
	// Clear function
	string s9 = " My name is xyz";
	s9.clear();
	cout << "Cleared string : "<< s9 << endl<< endl;   // clear gives empty string
	
	// Compare Function
	string s10 = "abc", s11 = "dac";
	cout << s11.compare(s10)<< endl<<endl;     // based on dictionary order gives 1(if s11 > s10) , 0(if s11 = s10), -1(if s11 < s10).
	
	// Empty function
	string s12 = "sjhcjs";
	s12.clear();
	if(s12.empty()){          // to check emptiness of string
		cout << "String is empty"<< endl<< endl;
	}
	else{
		cout << "String is not empty"<< endl<< endl;
	}
	
	// Erase Function 
	string s13 = "LakshmiSravani";
	s13.erase(3,2); // strarting from index 3 erase 2 elements
	cout << s13 << endl<< endl;
	
	//Find function
	string s14 = "sravani";
	cout << s14.find("ava") << endl <<endl; // give index number of r
	
	// Insert function
	string s15 = "kwn";
	s15.insert(1,"no");  //insert at index 1
	cout << s15 << endl<<endl;
	
	//size() or length() function
	string s16 = "this is a string";
	cout <<"size = "<< s16.size()<<" Length = "<< s16.length()<<endl<<endl;
	
	for(int i=0;i<s16.length();i++){
		cout <<" "<< s16[i];
	} cout << endl<< endl;
	
	// substr() function
	string s17 = "jimjam";
	cout << s17.substr(3,3)<<endl<<endl;   // substr(index, no of elemnts)
	
	// stoi() function - string to int function
	string s18 = "123";
	int num = stoi(s18);
	cout << " Number*4 = "<< num*4 << endl<<endl; 
	
	// to_string() function  int to string
	int y = 789;
	cout << to_string(y)+ "2"<<endl<<endl;
	
	// sort() function to sort elements in string
	string s19 = "eydyucywcshbxsajnxzjdhcd";
	sort(s19.begin(),s19.end());    // have to include algorithm header file
	cout << s19 <<endl<<endl; 
}
