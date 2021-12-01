// Problem statement link:     https://www.spoj.com/problems/EXPEDI/
// The truck leaks one unit of fuel every unit of distance it travels. Given number of stops, distance of stops from town and fuel in each stop.
//the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. 
//The truck is currently L units away from the town and has P units of fuel
//Find minimum number of stops required to fill fuel to reach the town.
//   Input:
//   1   ------- No of test cases
//   4   ------ No of stops or filling stations
//   4 4     -- 1st stop distance from town ,fuel available
//   5 2     -- 2nd stop distance from town ,fuel available
//   11 5    -- 3rd stop distance from town ,fuel available
//   15 10   -- 4th stop distance from town ,fuel available
//   25 10   -- Total initial disatnce to town, initial fuel available in truck

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	int testcases;
	cin >> testcases;
	
	while(testcases--){
		int n;           // Total No of fuel stations
		cin >> n;
		
		vector<pair<int, int>> a(n);     // first: distance from fuel station to town,  second: fuel available in station
		
		for(int i=0; i<n;i++){
			cin >> a[i].first >> a[i].second;
		}
		
		int totalDist, initfuel;
		cin >> totalDist >> initfuel;      // Initial distance btwn truck and town, initial fuel in truck
		
		for(int i=0; i<n;i++){
			a[i].first = totalDist - a[i].first;      // Update first to distance between truck and station
		}
		
		sort(a.begin(), a.end());
		
		int ans = 0;           // Stores no of stops required. will be our final result
		int curr = initfuel;   // tells about current fuel in truck
		
		priority_queue<int, vector<int>> maxheap;      // Stores fuel available in stations which we have traversed
		int flag = 0;          // Checks feasibility
		
	//	---------------------------------------------------------------- main loops
		for(int i=0; i<n; i++){
			if(curr >= totalDist){          // if fuel > distance to town, break, no need to stop, directly go to town
				break;
			}
			while(curr < a[i].first){      // if fuel < next stop dist and maxheap is empty ====> fuel exhaust so break
				if(maxheap.empty()){
					flag = 1;
					break;
				}
				ans++;                   // if maxheap not empty, add fuel from top and increment ans
				curr += maxheap.top();
				maxheap.pop();
			}
			if(flag ==1){
				break;
			}
			maxheap.push(a[i].second);		// push fuel capacity of current traversed station into maxheap				
		}
		
		if(flag==1){
			cout << -1 << endl;
			continue;              // continue to next test case
		}
		
		while(!maxheap.empty() && curr < totalDist){    // Calculating From last stop to town
			curr += maxheap.top();
			maxheap.pop();
			ans++;
		}
		
		if(curr < totalDist){    //After adding all fuel from maxheap, even then current fuel less than distance, then cout -1
			cout << -1;
			continue;
		}
		
		cout << "No of stops required = "<< ans << endl;
	}
}
