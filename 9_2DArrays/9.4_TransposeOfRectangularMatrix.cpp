// Transpose of rectangular matrix

#include <iostream>
using namespace std;

int main() {
   int row, column, i, j;

   cout << "Enter rows and columns of matrix: ";
   cin >> row >> column;
   int a[row][column], transpose[column][row];

   cout << "\nEnter elements of matrix: " << endl;

   // Storing matrix elements
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cin >> a[i][j];
      }
   }

   // Printing the Original matrix
   cout << "\nEntered Matrix: " << endl;
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cout << " " << a[i][j];
      }
      cout<<endl;
   }
   // Computing transpose of the matrix
   for (int i = 0; i < row; ++i){
      for (int j = 0; j < column; ++j) {
         transpose[j][i] = a[i][j];
      }
	}

   // Printing the transpose
   cout << "\nTranspose of Matrix: " << endl;
   for (int i = 0; i < column; ++i){
      for (int j = 0; j < row; ++j) {
         cout << " " << transpose[i][j];
      }
      cout<<endl;
  }

   return 0;
}
