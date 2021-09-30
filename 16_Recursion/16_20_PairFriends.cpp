// Find the no of ways we can pair n friends.
// We can either pair a friend with any other friend or we can leave a friend single.

#include<bits/stdc++.h>
using namespace std;
int pairFriends(int n){
	if(n==0||n==1||n==2){
		return n;
	}
	return pairFriends(n-1) + (pairFriends(n-2))*(n-1);    // pf(n-1) when we choose to leave nth friend single.   (pf(n-2))*(n-1)  when we choose to pair nth friend with anyone of n-1 friends
}
int main(){
	int n;
	cout << " Enter number of friends :";
	cin >> n;
	cout << "No of ways we can pair friends = "<<pairFriends(n)<<endl;
	return 0;
}
