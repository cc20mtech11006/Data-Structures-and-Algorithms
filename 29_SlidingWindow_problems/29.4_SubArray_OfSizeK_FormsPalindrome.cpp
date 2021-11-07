// To ckeck if a subarray of size K forms a palindrome

#include <bits/stdc++.h>
using namespace std;
 
// Function to check if a number is Palindrome or not
bool palindrome(vector<int> a, int i, int j)
{
     while(i<j)            // here i - starting index and j - last index of the subarray
     {
         if(a[i] != a[j])
             return false;
         i++;
         j--;
     }
     return true;
}
 
// Function to find a subarray whose concatenation forms a palindrome and return its starting index
int findSubArray(vector<int> arr, int k)
{
    int n= sizeof(arr)/sizeof(arr[0]);
         
    for(int i=0; i<=n-k; i++){
         if(palindrome(arr, i, i+k-1))
             return i;
    }
    return -1;
}
 
// Driver Code
int main()
{
    vector<int> arr = { 2, 3, 5, 1, 1, 5 };         // Output: 5115
    int k = 4;
    int ans = findSubArray(arr, k);
  
    if (ans == -1)
        cout << -1 << "\n";
    else {
        for (int i = ans; i < ans + k; i++)
            cout << arr[i];
        cout << "\n";
    }
    return 0;
}

