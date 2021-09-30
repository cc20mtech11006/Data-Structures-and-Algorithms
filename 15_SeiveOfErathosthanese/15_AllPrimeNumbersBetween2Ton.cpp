// Print all prime numbers from 2 to n using seive of Erathosthanese
 
 #include<iostream>
 using namespace std;
 
 void seive(int n){
 	int a[100];
 	for(int i=2;i<=n;i++){
 		a[i]=0;
	 }
	 for(int i=2;i<=n;i++){
	 	if(a[i]==0){          // 0 implies prime
	 		for(int j=i*i;j<=n;j+=i){  // Marking multiples of i as 1 (non prime)
	 			a[j]=1;
			 }
		 }
	 }
	 
	 for(int i =2;i<=n;i++){
	 	if(a[i]==0){
	 		cout << i<< " ";
		 }
	 }
 }
 
 int main(){
 	int n;
 	cout << "Enter highest range : ";
 	cin >> n;
 	seive(n);
 	return 0;
 }
