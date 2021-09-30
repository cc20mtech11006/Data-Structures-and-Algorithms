//Character Array. Print every letter of string

#include<iostream>
using namespace std;

int main(){
	// direct initialization hard code
    char b[100]="Character array can be given directly this way";
    cout << b<<endl<<endl;
    
    //Taking input from user and printing character array letter by letter
	char a[100] ;
	cout<<"Enter character array: ";
	cin >> a;
	int i=0;
	while(a[i]!='\0'){
		cout<<a[i]<<" ";
		i++;
	}
}
