// Prefix evaluation using stack
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prefixEvaluation(string s){
	stack<int> st;
	int op1, op2;
	for( int i=s.length()-1; i>=0;i--){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			op1 = st.top();
			st.pop();
			op2 = st.top();
			st.pop();
			switch(s[i]){
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1, op2));
					break;
			}
		}
		
	}
	return st.top();
}

int main(){
	string s = "-+/99^24*44";     
	cout << prefixEvaluation(s)<<endl;
}


//  9/9 +2^4 -4*4
//   /99   +     ^24      - *44
// -+/99^24*44
