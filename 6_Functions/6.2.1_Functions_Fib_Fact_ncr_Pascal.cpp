// Functions : Fibanacci series  and Factorial and nCr - 4-1-2021
#include<iostream>
using namespace std;
int fib(int);
int fact(int);
float ncr(int,int);
float pascal(int n,int r);

// Function for Fibanacci series
int fib(int len){
	if(len==0){
		return 0;
	}
	else if(len==1){
		return 1;
	}
	else return(fib(len-1)+fib(len-2));
}

//Function for factorial;
int fact(int i){
	if(i==1|| i==0){
		return 1;
	}
	else{
		return( i * fact(i-1));
	}
}

// Function for nCr
float ncr(int n, int r){
	if (n<r){
		cout << n << "C" << r << " doesn't exist "<< endl;
	}
	else{
	float result = fact(n)/(fact(n-r)*fact(r));
	return result;
	}
}

//Function for Pascal Triangle
float pascal(int rows){
	for(int i=0;i<rows;i++){
		for(int j=0; j<=i;j++){
			cout << ncr(i,j)<< " ";
		}
		cout << endl;
	}
}
