// C++ program to merge k sorted arrays of size n each.
#include <bits/stdc++.h>
using namespace std;

// A pair of pairs, first element - value, second element- array number, third element- index of value in array.
typedef pair<int, pair<int, int> > ppi;

// Function to merge k sorted arrays and return final sorted output.
vector<int> mergeKArrays(vector<vector<int> > arr)
{
	vector<int> output;

	// Create a min heap with k heap nodes. Every heap node has first element of an array
	priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

	for (int i = 0; i < arr.size(); i++)
		pq.push({ arr[i][0], { i, 0 } });

	// Now one by one get the minimum element from min heap and replace it with next element of its array
	while (pq.empty() == false) {
		ppi curr = pq.top();
		pq.pop();
		
		int i = curr.second.first;    // i ==> Array Number
		int j = curr.second.second;   // j ==> Index in the array number

		output.push_back(curr.first);

		// push next element of same array into min heap
		if (j + 1 < arr[i].size())
			pq.push({ arr[i][j + 1], { i, j + 1 } });
	}

	return output;
}

int main()
{

	vector<vector<int> > arr{ { 2, 6, 12 },
							{ 1, 9 },
							{ 23, 34, 90, 2000 } };
	// Taking input for 2D vectors
/*	int k;
	cout << "Enter Number of arrays : ";
	cin >> k;
	
	vector<vector<int>> a(k);
	
	for(int i=0; i<k; i++){
		cout << "Enter " <<i+1 <<" th Array size : ";
		int n;
		cin >> n;
		a[i] = vector<int>(n);
		
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}  */
	vector<int> output = mergeKArrays(arr);

	cout << "Merged array is " << endl;
	for (auto x : output)
		cout << x << " ";

	return 0;
}

