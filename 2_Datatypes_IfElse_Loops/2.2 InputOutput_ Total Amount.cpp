// Input Output : 31-12-2020
#include <iostream>   // iostream is the header file containing input output libraries
using namespace std;  // namespace is the standard which contain cout, cin

int main(){
	int my_amount;     //variable declaration
	int mother_amount; // declaration
	int father_amount; // declaration
	my_amount = 1000;  // initialization
	
	cout <<" Enter Mother amount and Father amount" << endl;
	cin >> mother_amount >>father_amount;  // taking input; >> is Insertion Operator
	int sum = my_amount + mother_amount + father_amount;
	cout << "Total Amount = " << sum << endl; // Getting or printing output;  << is Extraction Operator
	
	return 0;
}
