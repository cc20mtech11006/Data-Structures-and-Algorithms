// C++ program for optimal allocation of pages. Maximum number of pages given to a student must be minimum compared to all other allocations.

#include<bits/stdc++.h>
using namespace std;
 
// Utility function to check if current minimum value is feasible or not.
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
 
    for (int i = 0; i < n; i++)        // iterate over all books
    { 
        if (arr[i] > curr_min)         // if current book pages are greater than curr_min, then that solution is not possible
            return false;

        if (curr_sum + arr[i] > curr_min)     // If curr_sum + current book pages exceed curr_min, stop given books to current student
        {
            studentsRequired++;        // increment student count. Start giving books to next student
            curr_sum = arr[i];         // curr_sum for next student is equal to current book
 
            if (studentsRequired > m)  // if students required becomes greater than given no. of students,return false
                return false;
        }
        else
            curr_sum += arr[i];        // If curr_sum + current book pages < curr_min, continue given books to current student
    }
    return true;
}
 
// function to find minimum pages
int findPages(int arr[], int n, int m)
{
    long long sum = 0;
 
    if (n < m)           // return -1 if no. of books is less than no. of students
        return -1;
 
    for (int i = 0; i < n; i++)    // Count total number of pages
        sum += arr[i];

    int start = 0, end = sum;
    int result = INT_MAX;
 
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))     // check if it is possible to distribute books by using mid as current minimum
        {
            result = min(result, mid);      // Update result
            end = mid - 1;                  // Our feasible solution can be even smaller, so update end to mid-1 and try
        }
 
        else{
            start = mid + 1;  // A feasible solution is not obtained by current mid since it is small. so update start to mid+1 and try for greater mid in next iteration
        }
    }
    return result;
}
 
// Drivers code
int main()
{
    int arr[] = {12, 34, 67, 90};               //Number of pages in each books
    int n = sizeof arr / sizeof arr[0];         // Number of books
    int m = 2;                                  // No. of students
 
    cout << "Minimum number of pages = " << findPages(arr, n, m) << endl;
    return 0;
}
