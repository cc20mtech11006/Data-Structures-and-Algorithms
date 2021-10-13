// Infix to Postfix conversion
#include<iostream>
#include<stack>
using namespace std;

int precedence(char opertr){
 	if(opertr =='^'){
 		return 3;
	 }
	else if(opertr == '*'|| opertr == '/'){
	 	return 2;
	 }
	else if(opertr == '+' || opertr == '-'){
		return 1;
	}
	else{
		return -1;
	}
 }

string infixToPostfixConversion(string s){
	string res;
	stack<char> st;
	for(int i=0; i<s.length(); i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			res += s[i];
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty() && st.top()!='('){
				res = res+st.top();
				st.pop();
			}
			if(!st.empty()){       // we pop just once -- to pop open brace from stack
				st.pop();
			}
		}
		else{
			while(!st.empty() && ( precedence(s[i]) < precedence(st.top()) )){
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){    // even after traversing whole string s , some operators might be left inside stack. We append those into our result
		res+= st.top();
		st.pop();
	}
	return res;
}

int main(){
	string s =  "(a^b)^c/d-e/f+g";     //(a*b)+c-(d^e)-f-g+h"; //"(a-b/c)*(a/k-l)";
	cout << infixToPostfixConversion(s);
}


