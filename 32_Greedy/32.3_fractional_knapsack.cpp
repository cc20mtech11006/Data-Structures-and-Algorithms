// Fractional Knapsack Problem.
// Given n items with corresponding weights and profits. We have to find the mximum value/profit for a fixed size of knapsack
// Let (profit, weights) of objs =   21 7,   24 4,  12 6,  40 5,   30 6 , M=20 ------------ Output : 109  (40+ 24+ 30 + 5/7 *21)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> obj1, pair<int,int> obj2){
	double profit1 = obj1.first/obj1.second;
	double profit2 = obj2.first/obj2.second;
	return profit1 > profit2;
}

int main(){
	int n;
	cout << "Enter no of items : ";
	cin >> n;
	vector<pair<int,int>> v(n);    // stores <profit, weight> of every item
	cout << "Enter value and weight of each item: " << endl;
	for(int i=0; i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	cout << "Enter maximum capacity of knapsack : ";
	int W;
	cin >> W;
	
	sort(v.begin(), v.end(), compare);    // sort objects based on profit = value/weight
	
	int max_profit=0;
	for(int i=0; i<n;i++){
		if(v[i].second < W){           // if weight of object < knapsack capacity, include whole object
			max_profit += v[i].first;
			W -= v[i].second;
			continue;
		}
		double frac_obj_profit = (double)v[i].first/v[i].second;  
		max_profit += W*frac_obj_profit;        // include fraction of the object 
		W=0;
		break;
	}
	cout << "Maximum profit of fractional knapsack = "<< max_profit;
}


