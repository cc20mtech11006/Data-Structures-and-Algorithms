// Loops Example - Multiplication table - 31-12-2020
#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter a number to print table: ";
 cin >> n;
  for (int i=0; i<=10; i++){
  	cout << n << " x " << i << " = " << n*i << endl;
  }
  return 0;
}
