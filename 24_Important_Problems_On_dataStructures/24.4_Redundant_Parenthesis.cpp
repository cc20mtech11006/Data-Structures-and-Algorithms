// Redundant parenthesis
// Ex: ((a+b)) has redundant paranthesis.  (a+(a+b)) doesn't have redundant paranthesis

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool redundant_parenthesis(string s){
	stack<int> st;
	bool ans = false;
	for(int i=0;i<s.length();i++){
		if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){    //push operators into stack
			st.push(s[i]);
		}
		else if(s[i]=='('){       // push all open brackets into stack
			st.push(s[i]);
		}
		else if(s[i]==')'){       // when we see a closing bracket ')', if we immediately see a  '(' in stack top then redundant parenthesis exist
			if(st.top()=='('){
				ans = true;            
			}
			while(st.top()=='+' || st.top()=='-' || st.top()=='/' || st.top()=='*'){    //pop all stack top operators until we see a '('
				st.pop();          
			}
			st.pop();	 // pop '('
		}
	}
	return ans;
}

int main(){
	string s = "(a+(a+b))";
	cout << redundant_parenthesis(s);
}

// (a+((a+b))) ---- st : ( + ( ( +   {next seen ')'} {pop stack top operstors and ( }
//            ------st: ( + (       { next seen ')'}  {stack top = '('}  ==>  ans = true       ---- pop '('
//            ------ st : ( +       { next seen ')'}  { pop stack top operators and ')'} 
// end of for loop ------- return ans = true

