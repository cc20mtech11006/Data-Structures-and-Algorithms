// Finding largest word in a sentence
#include<iostream>
using namespace std;

int main(){
	cout<< "Enter size of sentence: ";
	int n;
	cin>> n;
	cin.ignore();  // ignores input n for the sake of getline function. since it tends to take input from previous cin s.
	char a[n+1];
	cin.getline(a, n);
	
	int maxLen = 0, currLen = 0, st=0, maxst=0 ,i=0;
	while(1){
		if(a[i]== ' ' || a[i]=='\0'){
			if(currLen>maxLen){
				maxLen = currLen;
				maxst = st;
			}
			currLen =0;
			st = i+1;			
		}
		else{
			currLen++;
		}
		if(a[i]=='\0'){
			break;
		}
		i++;
	}
	cout<<"maxLen = "<< maxLen<<endl;
	//Printing largest word
	for(int i=0; i<maxLen;i++){
		cout<<a[i+maxst];
	}	
}
