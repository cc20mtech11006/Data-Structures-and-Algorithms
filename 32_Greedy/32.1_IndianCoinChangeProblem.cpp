// Indian coin change problem. Given a Value x and array of coin denominations, we have to find minimum number of coins required to make value x
//Ex: a[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1} ,  x = 350 ------ Output : 3 (since 200+100+50     gives 350)

#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> a = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	cout << "Enter x: ";
	int x;
	cin >> x;
	
	int count = 0;
	for(int i=0; i<10; i++){
		count += x/a[i];
		x -= x/a[i] * a[i];
	}
	cout <<" Minimum coins required = "<<count;
}
