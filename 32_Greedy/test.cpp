#include<bits/stdc++.h>
using namespace std;

int main(){
	string s = "cocubes";
	vector<string> v1;
	vector<string> v2;
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			string str;
			for(int k=i;k<=j;k++){
				str+= s[k];
			}
			if(str.size()>=1){
			
			v1.push_back(str);
			
			reverse(str.begin(), str.end());
			v2.push_back(str);
		}
		}
	}

	int count =0;
	for(int i=0; i < v1.size();i++){
		bool flag = false;
		for(int j=0; j<v2.size(); j++){
			if(v1[i]==v2[j]){
				cout << v1[i]<<"  "; 
				flag = true;
				break;
			}
		}
		if(flag == true){
			count++;
		}
	}
	cout << count<<endl;
}
