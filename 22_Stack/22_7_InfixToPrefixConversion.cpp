// Infix to prefix conversion
// Steps: First reverse the string, apply infix to postfix function by interchanging "(" and ")",   reverse result and return it.

#include<iostream>
#include<stack>
#include<algorithm>  // used for reverse() function
using namespace std;

int precedence(char op){
	if(op == '^'){
		return 3;
	}
	else if(op == '*' || op=='/'){
		return 2;
	}
	else if(op=='+' || op =='-'){
		return 1;
	}
	else{
		return -1;
	}
}

string infixToPrefix(string s){
	reverse(s.begin(),s.end());    // we have reversed s
	string res;
	stack<char> st;
	
	                                     // Here we can interchange '(' with ')' and implement infixToPostfix function.
	for(int i=0;i<s.length();i++){
		if((s[i]>='a'&&s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			res += s[i];
		}
		else if(s[i]==')'){                             // ')' in prefix where as '(' in postfix
			st.push(s[i]);
		}
		else if(s[i]=='('){                            // '(' in prefix where as ')' in postfix
			while(!st.empty() && st.top()!=')'){       // ')' in prefix where as '(' in postfix
				res += st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{
			while((!st.empty()) && (precedence(s[i])<precedence(st.top()) )){
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}		
	}
	
	while(!st.empty()){            // even after traversing whole string s , some operators might be left inside stack. We append those into our result
			res += st.top();
			st.pop();
		}
	reverse(res.begin(),res.end());   // reversing result res
	return res;                      // final output which is the prefix form
}

int main(){
	string s = "(a-b/c)*(a/k-l)" ;             //"(a^b)^c/d-e/f+g";
	cout << infixToPrefix(s)<<endl;
}
