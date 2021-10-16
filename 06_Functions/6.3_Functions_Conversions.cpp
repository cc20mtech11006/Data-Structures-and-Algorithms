# include<bits/stdc++.h>
using namespace std;

// Function for sum of first n natural numbers
int sum(int n){
	int ans =0;
	for(int i=1;i<=n;i++){
		ans = ans+i;
	}
	return ans;
}

// Function to check a triplet is pythagorean triplet
bool pytho(int x, int y, int z){
	int a = max(x, max(y,z));
	int b, c;
	if(a==x){
		b=y; c=z;
	}
	else if(a==y){
		b = x; c= z;
	}
	else{
		b=x;c=y;
	}
	if(a*a == b*b + c*c){
		return true;
	}
	else{
		return false;
	}
}

// Binary to Decimal conversion
int binaryToDecimal(int n){
	int ans =0;
	int x=1;
	while(n>0){
		int y = n%10;
		ans = ans + y*x;
		x = x*2;
		n /= 10;
	}
	return ans;
}

// Octal to Decimal conversion
int octalToDecimal(int n){
	int ans =0;
	int x=1;
	while(n>0){
		int y = n%10;
		ans = ans + y*x;
		x = x*8;
		n /= 10;
	}
	return ans;
}

// Hexadecimal to Decimal conversion
int hexadecimalToDecimal(string n){
	int ans =0;
	int x=1; 
	int s = n.size();
	
	for(int i=s-1; i>=0; i--){
		if(n[i]> '0' && n[i]<'9'){
			ans += x*(n[i]-'0');
		}
		else if(n[i]>= 'A'&& n[i]<= 'F'){
			ans += x*(n[i]-'A'+10);
		}
		x *= 16;
	}
	return ans;
}

// Decimal to Binary conversion
int decimalToBinary(int n){
	int x =1;
	int ans =0;
	
	while(x <= n){
		x= x*2;
	}
	x = x/2;
	
	while(x>0){
		int lastDigit = n/x;
		n = n - lastDigit*x;
		x /= 2;
		ans = ans*10 + lastDigit;
	}
	return ans;
}

// Decimal to Octal conversion
int decimalToOctal(int n){
	int x =1;
	int ans =0;
	
	while(x <= n){
		x= x*8;
	}
	x = x/8;
	
	while(x>0){
		int lastDigit = n/x;
		n = n - lastDigit*x;
		x /= 8;
		ans = ans*10 + lastDigit;
	}
	return ans;
}

// Decimal to Hexadecimal Conversion
string decimalToHexadecimal(int n){
	int x =1;
	string ans = "";
	
	while(x<=n){
		x *= 16;
	}
	x = x/16;
	
	while(x>0){
		int lastDigit = n/x;
		n = n - lastDigit*x;
		x /= 16;
		
		if(lastDigit <= 9){
			ans = ans + to_string(lastDigit);
		}
		else{
			char c = 'A' + lastDigit -10;
			ans.push_back(c);
		}
	}
	return ans;
}


// --------------------------------------------------------------------------------------------

int main(){
	// sum of n naturals
	int s,n;
	cout<<"Enter a natural number: ";
	cin >> n;
	s = sum(n);
	cout<< "Sum of first "<<n << " natural numbers = "<< s<<endl<<endl;
	
	// Pythogorean triplet
	int x, y, z;
	cout<< "Enter a triplet to check if it is pythagorean ";
	cin>>x>>y>>z;
	if(pytho(x,y,z)){
		cout << " Pythagorean Triplet "<< endl<< endl;
	}
	else{
		cout<< " Not a pythagorean triplet" << endl<< endl;
	}
	
	// Binary to decimal conversion
	int b;
	cout << "Enter a binary number to convert it into decimal ";
	cin >> b;
	cout << binaryToDecimal(b)<< endl << endl;
	
	// Octal to decimal conversion
	int o;
	cout << "Enter a octal number to convert it into decimal ";
	cin >> o;
	cout << octalToDecimal(o)<< endl << endl;
	
	// Hexadecimal to decimal conversion
	string h;
	cout << "Enter a hexadecimal number to convert it into decimal ";
	cin >> h;
	cout << hexadecimalToDecimal(h)<< endl << endl;
	
	// Decimal to binary conversion
	int d;
	cout <<"Enter a decimal number to convert it to binary ";
	cin >> d;
	cout << decimalToBinary(d)<<endl<<endl;
	
	// Decimal to octal conversion
	int d1;
	cout <<"Enter a decimal number to convert it to octal ";
	cin >> d1;
	cout << decimalToOctal(d1)<<endl<<endl;
	
	// Decimal to hexadecimal conversion
	int d2;
	cout <<"Enter a decimal number to convert it to hexadecimal ";
	cin >> d2;
	cout << decimalToHexadecimal(d2)<<endl<<endl;
	
}
