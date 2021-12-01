#include<bits/stdc++.h>
using namespace std;
string dealofday(vector<string> &v){
	int maxcount =0;
	vector<string> tie;
	
	for(int i=0; i<v.size();i++){
		int count =0;
		for(int j=i; i<v.size();j++){   // {"ys","bs", "gs", "bs", "gs", "ys", "ws", "ps", "ys", "gs"}
			cout << count << " ";
			if(v[i]==v[j]){
				count++;
			}
		}
		if(count > maxcount){
		//	cout << count << " ";
			tie.clear();
			maxcount = count;
			tie.push_back(v[i]);
			cout << v[i]<< " ";
		}
		else if(count == maxcount){
			tie.push_back(v[i]);
		}
	}
	
	sort(tie.begin(), tie.end(),greater<string>());
	return tie[0];
}

int main(){
	vector<string> v = {"ys","bs", "gs", "bs", "gs", "ys", "ws", "ps", "ys", "gs"};
	cout << dealofday(v);
}

