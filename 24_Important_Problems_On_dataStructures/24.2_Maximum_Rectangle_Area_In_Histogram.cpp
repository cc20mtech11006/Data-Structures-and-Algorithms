// Maximun rectangle area in histogram
// Explanation : https://www.youtube.com/watch?v=vcv3REtIvEo  ------ O(n)

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largestRectangleArea(vector<int> heights){
	int n= heights.size();  // no of bars in histogram
	vector<int> left(n), right(n);
	
	stack<int> st;
	
	// Fill left limits of bars in left vector
	for(int i=0; i<n;i++){
		if(st.empty()){
			left[i]=0;
			st.push(i);
		}
		else{
			while(!st.empty() && heights[st.top()]>=heights[i]){
				st.pop();
			}
			left[i] = st.empty()? 0 : st.top()+1;
			st.push(i);
		}		
	}
	
	// Clear stack to reuse for right limits
	while(!st.empty()){
		st.pop();
	}
	
	// Fill Right limits of bars that can form rectangle in right vector
	for(int i = n-1;i>=0;i--){
		if(st.empty()){
			right[i]=n-1;
			st.push(i);
		}
		else{
			while(!st.empty() && heights[st.top()]>=heights[i]){
				st.pop();
			}
			right[i] = st.empty()? n-1 : st.top()-1;
			st.push(i);
		}
	}
	
	// Finding area of largest rectangle.  
	int max_rectArea = 0;
	for(int i=0;i<n;i++){
		max_rectArea = max(max_rectArea, heights[i]*(right[i]-left[i]+1));
	}
	return max_rectArea;
}


int main(){
	vector<int> heights=  {2,4,5,6,3};   //{2,1,5,6,2,3};    //{2,4,5,6,9,3,2,5,1};  // Heights of bars in histogram
	cout << "Largest rectangle area that can be formed = "<< largestRectangleArea(heights);
}
