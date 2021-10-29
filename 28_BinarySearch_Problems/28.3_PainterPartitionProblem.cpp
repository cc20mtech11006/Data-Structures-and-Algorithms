// Painters Partition Problem
// Given n boards of different sizes and m painters. A painter paints only consecutive boards where he can paint 1 unit of board in 1 unit time.
// We have to partition the boards to find the minimum time required to paint all the boards
// This problem is similar to Page allocation problem

#include<bits/stdc++.h>
using namespace std;
 
// Utility function to check if current minimum value is feasible or not.
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int painter = 1;
    int curr_sum = 0;
 
    for (int i = 0; i < n; i++)        // iterate over all boards
    { 
        if (arr[i] > curr_min)         // if current board size greater than curr_min, then that solution is not possible
            return false;

        if (curr_sum + arr[i] > curr_min)     // If curr_sum + current board size exceed curr_min, stop allocating board to current painter
        {
            painter++;                 // increment painter count. Start giving boards to next painter
            curr_sum = arr[i];         // curr_sum for next painter is equal to current board size
 
            if (painter > m)           // if painters required becomes greater than given no. of painters,return false
                return false;
        }
        else
            curr_sum += arr[i];        // If curr_sum + current board size < curr_min, continue given boards to current painter
    }
    return true;
}
 
// function to find minimum time
int findMinTime(int arr[], int n, int m)
{
    long long sum = 0;            // Variable that store total length of all boards
 	
 	int k = 0;
    for (int i = 0; i < n; i++){    // Count total sum of board lengths
        k = max(k, arr[i]);        // k stores the maximum board size
        sum += arr[i];
	}
    int start = k, end = sum;
 
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))     // check if it is possible to distribute boards by using mid as current minimum
        {
            end = mid - 1;                  // Our feasible solution can be even smaller, so update end to mid-1 and try
        }
 
        else{
            start = mid + 1;  // A feasible solution is not obtained by current mid since it is small. so update start to mid+1 and try for greater mid in next iteration
        }
    }
    return start;
}
 
// Drivers code
int main()
{
    int arr[] = {10, 20, 30, 40};               //Board sizes
    int n = sizeof arr / sizeof arr[0];         // No of boards
    int m = 2;                                  // No. of painters
 
    cout << "Minimum time for painting = " << findMinTime(arr, n, m) << endl;
    return 0;
}
