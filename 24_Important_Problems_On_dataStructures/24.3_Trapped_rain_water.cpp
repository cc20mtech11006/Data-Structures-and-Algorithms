// Calculate Trapped rain water in an elevation map
// https://www.youtube.com/watch?v=C8UjlJZsHBw
//Time complexity- O(n), Space complexity - O(1)

#include<iostream>
#include<vector>
using namespace std;

int total_trappedWater(vector<int> height){
	int n = height.size();
	if(n<=2){
		return 0;    // if only 2 blocks, then no trapped water is present
	}
	int trappedWater =0;
	
	int left = 1;       // Left pointer to point to certain block. stores index
	int right = n-2;    // Right pointer to point to right side block stores index
	
	int max_left_height = height[0];       // stores maximum height of left side blocks
	int max_right_height = height[n-1];    // stores maximum height of right side blocks
	
	while(left<=right){
		if(max_left_height <= max_right_height){
			if(height[left]>=max_left_height){
				max_left_height = height[left];
				left++;
			}
			else{
				trappedWater += max_left_height - height[left];
				left++;
			}
		}
		else{
			if(max_right_height <= height[right]){
				max_right_height = height[right];
				right--;
			}
			else{
				trappedWater += max_right_height - height[right];
				right--;
			}
		}
	}
	return trappedWater;
}

int main(){
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << "Total Trapped water = "<< total_trappedWater(height);
	return 0;
}

