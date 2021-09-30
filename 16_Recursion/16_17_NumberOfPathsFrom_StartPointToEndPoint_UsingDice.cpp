// Count number of paths from start point to end point in a board game using dice.
//Ex : Let 0  1  2  3  be the 1 dimensional board, we have to find no of ways of going from 0 to 3. We have to take jumps based on dice roll.
// ------ Output = 4 ( 0-3, 0-1 1-2 2-3, 0-2 2-3, 0-1 1-3 )

#include<bits/stdc++.h>
#include<string>
using namespace std;
int countPath(int s,int e){
	if(s==e){
		return 1;
	}
	if(s>e){
		return 0;
	}
	int count =0;
	for(int i=1; i<=6;i++){   // since dice has only 6 numbers. Our jump is based on dice roll
		count += countPath(s+i,e);
	}
	return count;
}

int main(){
	int startPoint, endPoint;
	cout << "Enter board game start point and end point: ";
	cin >> startPoint>>endPoint;
	cout << countPath(startPoint, endPoint)<<endl;
	return 0;
}
