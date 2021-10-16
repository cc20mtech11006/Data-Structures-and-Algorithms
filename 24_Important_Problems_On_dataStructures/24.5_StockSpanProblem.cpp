// Stock Span Problem ------- O(n)
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day. 
// Example: if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6} 

#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<int> stockSpan(vector<int> prices){
	vector<int> ans;              // a vector 'ans' that stores the span result of all days . Maximum number of 'consecutive days' for which the current stock price is greater than previous days
	stack<pair<int,int>> st;     // we are taking a stack of pairs
	for(auto price : prices){
		int days = 1;
		while(!st.empty() && st.top().first <= price){
			days = days + st.top().second;
			st.pop();
		}
		st.push({price, days});
		ans.push_back(days);
	}
	return ans;
}

int main(){
	vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
	vector<int> span = stockSpan(prices);
	for(auto i:span){
		cout << i<< " ";
	}
	return 0;
}
