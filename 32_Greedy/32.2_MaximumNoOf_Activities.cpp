// We are given n activities along with their start and end times. Select maximum number of activities that can be performed by a single person
//Ex-1: 10 20,  12 15,   20 30  ---------- Output : 2 (we can do activity 1  - 10 20   and activiy 3 - 20 30)
// Ex-2 Enter number of activities : 4
//  1 2
//  2 5
//  3 4
//  4 5     ----------- Output = 3 (we can do 1 2,  3 4,  4,5)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cout << "Enter number of activities : ";
	int n;
	cin >> n;
	vector<vector<int>> v;        // Stores starting and ending times of each activity
	int start, end;
	for(int i=0; i<n; i++){
		cin >> start >> end;
		v.push_back({start, end});
	}
	// Sorting vector v based on end times of activities
	sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){ return a[1] < b[1]; });     // It is a Custom comparator function(Using lambda function. We are using end times of job a and b to sort
	
	end = v[0][1];     // Taking first job and doing it
	int count = 1;     // Represents number of jobs done
	
	for(int i=1; i<n; i++){
		if(v[i][0] >= end){   // v[i][0], which is start time of next job must be greater than end time of previous job
			count++;
			end = v[i][1];    // update end time to next job's end time
		}
	}
	cout << "Maximum no of activities that can be performed : " << count;
}
