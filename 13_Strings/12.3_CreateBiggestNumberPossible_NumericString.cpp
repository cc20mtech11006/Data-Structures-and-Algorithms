// Find biggest possible number from a numeric string
//Ex = "426749" ==========> output = 976442
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cout <<"Enter a numeric string : " ;
	cin >>s;
	sort(s.begin(),s.end(),greater<int>()); //greater<int>() forsorting in decreasing order
	cout << s<<endl;
}
