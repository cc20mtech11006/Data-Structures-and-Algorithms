// Finding prime factors of a number. Ex: 21 : 3*7   =======> output : 3 7
#include<iostream>
#include<climits>
using namespace std;

void primefactors(int n){
	int a[1000];
	for(int i=0;i<=n;i++){
		a[i]=i;
	}
	for(int i=2;i<n;i++){           // Updates a[i] with i's smallest factor
		if(a[i]==i){
			for(int j=i*i;j<=n;j+=i){
				if(a[j]==j){
					a[j]=i;
				}
			}
		}
	}
	
	while(n!=1){
		cout << a[n]<< " ";
		n = n/a[n];
	}
	
}

int main(){
int n;
cout << "enter a number to print prime factors: ";
cin >>n;
primefactors(n);
return 0;	
}

