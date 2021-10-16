// Patterns - 1-1-2021

#include<iostream>
using namespace std;

int main(){
	int row, col;
	cout << " Enter number of rows and columns: ";
	cin >> row >> col;
	
	// Solid Rectangle
/*          ******
	        ******
	        ******
	        ******            */	
	for(int i=0; i<row;i++){
		for(int j=0; j<col; j++){
			cout <<"* ";
		}
		cout << endl;
	}
	
	//Hollow Rectangle
/*          ******
            *    *
            *    *
            ******            */
	cout << endl << endl;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==0 || j==0 || i==row-1 || j== col-1){
				cout << "* ";
			}
			else{
				cout <<"  ";
			}
		}
		cout << endl;
	}
	
	//Top left Right Triangle
/*          ******
            *****
            ****
            ***
            **
            *                  */
	cout << endl <<"Enter number of rows:";
	cin >> row;
	cout << endl<< endl;
	for(int i=row; i>0;i--){
		for(int j=0; j<i;j++){
			cout << "* ";
		}
		cout<< endl;
	}
	
	//Bottom left Right Triangle
/*          *
            **
            ***
            ****
            *****                */
	cout << endl<< endl;
	for(int i=0; i<row;i++){
		for(int j=0; j<=i;j++){
			cout << "* ";             // add space for beauty
		}
		cout<< endl;
	}
	
	//Top right Right Triangle
/*          *****
             ****
              ***
               **
                *                 */
	cout << endl << endl;
	for(int i=0; i<row; i++){
		for(int j=0;j<row; j++){
			if(i<=j){
				cout << "* ";
			}
			else{
				cout << "  ";
			}
		}
		cout <<endl;
	}
	
	//Bottom right Right Triangle
/*               *
                **
               ***
              ****
             *****               */
	cout << endl << endl;
	for(int i=0; i<row; i++){
		for(int j=0;j<row; j++){
			if(j<row-1-i){
				cout << "  ";
			}
			else{
				cout << "* ";    // add space for beauty
			}
		}
		cout << endl;
	}
	
	//Bottom right number triangle
/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5  */
	cout << endl<< endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<=i;j++){
			cout << i+1 << " ";
		}
		cout << endl;
	}
	
	//Floyd's Triangle
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15  */
	cout << endl << endl;
	int count =0;
	for(int i=0; i<row; i++){
		for(int j=0;j<=i;j++){
			cout << ++count<< " ";
		}
		cout << endl;
	}
	
	// Number Right Triangle Top Left
/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
	 cout << endl << endl;
	 for(int i=row; i>=1; i--){
	 	for(int j=1; j<=i; j++){
	 		cout << j <<" ";
		 }
		 cout << endl;
	 }
	 
	 // 0-1 Bottom left right Triangle
/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/
	 cout << endl<< endl;
	 for(int i=1; i<=row;i++){
	 	for(int j=1;j<=i;j++){
	 		((i+j)%2==0)?cout << 1 <<" " : cout << 0 << " ";		 
		}
		cout << endl;
	 }
	 
	 
	 // Number Pyramid
/*
    1
   1 2
  1 2 3
 1 2 3 4
1 2 3 4 5
*/
	 cout << endl<< endl;
	 for(int i=row;i>=1;i--){
	 	int count =0;
	 	for(int j=1; j<=i-1; j++){
	 		cout << " ";
		 }
		 for(int j=i;j<=row;j++){
		 	cout << ++count<< " ";
		 }
		 cout << endl;
	 }
	 
	 // Palindrome Pyramid
/*
        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5
*/
	 cout << endl << endl;
	 for(int i=1;i<=row;i++) {
	 	for(int j=1; j<=row-i; j++){
	 		cout << "  ";
		 }	 
		 for(int num = i; num>=1; num--){
		 	cout << num << " ";		 	
		 }
		 for(int num=2; num <=i; num++){
		 	cout << num << " ";
		 }
		 cout << endl;
	 }
	 
	 // Pascal's Triangle
/*
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
*/
	 cout << endl << endl;
	 int coef =1;
	 for(int i=0; i<row; i++){
	 	for(int j=0; j<row-1-i; j++){
	 		cout << "  ";
		 }
		 for(int j=0; j<=i;j++){
		 	if(j==0){
		 		coef=1;
			 }
			 else {
			 	coef = coef* (i-j+1)/j;
			 }
			 cout<< coef << "   ";
		 }
		 cout <<endl;
	 }
	 
	 
	 // Rhombus Pattern
/*
        * * * * *
      * * * * *
    * * * * *
  * * * * *
* * * * *
*/
	 cout << endl << endl;
	 for(int i=1; i<=row; i++){
	 	int space = row-i;
	 	for(int j=space;j>=1;j--){
	 		cout << "  ";
		 }
		 for(int j=1;j<=row;j++){
		 	cout << "* ";
		 }
		 cout << endl;
	 }
	 
	 // Butterfly pattern
/*
*                 *
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*/
	cout << endl << endl;
	for(int i=1; i<=row; i++){
		for(int j=1; j<=i; j++){
			cout << "* ";
		}		
		int space = 2*row -2*i;
		for( int j=1; j<=space; j++){
			cout << "  ";
		}
		for(int j=1; j<=i;j++){
			cout << "* ";
		}
		cout << endl;
	}
	for(int i=row; i>=1; i--){
		for(int j=1; j<=i; j++){
			cout << "* ";
		}	
		int space = 2*row -2*i;
		for( int j=1; j<=space; j++){
			cout << "  ";
		}
		for(int j=1; j<=i;j++){
			cout << "* ";
		}
		cout << endl;
	}
	
	// Hollow Butterfly
/*
*                 *
* *             * *
*   *         *   *
*     *     *     *
*       * *       *
*       * *       *
*     *     *     *
*   *         *   *
* *             * *
*                 *
*/
	cout << endl<<endl;
	for(int i=1; i<=row; i++){
		for(int j=1; j<=i; j++){
			if(j==1 || j==i){
				cout <<"* ";
			}
			else{
				cout << "  ";
			}
		}
		for(int j=1; j<=2*row-2*i; j++){
			cout << "  ";
		}
		for(int j=1;j<=i;j++){
			if(j==1 || j==i){
				cout << "* ";
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for(int i=row; i>=1; i--){
		for(int j=1; j<=i; j++){
			if(j==1 || j==i){
				cout <<"* ";
			}
			else{
				cout << "  ";
			}
		}
		for(int j=1; j<=2*row-2*i; j++){
			cout << "  ";
		}
		for(int j=1;j<=i;j++){
			if(j==1 || j==i){
				cout << "* ";
			}
			else{
				cout << "  ";
			}
		}
		cout << endl;
	}
	 
	 // Diamond pattern
/*
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/
	 cout << endl<< endl;
	 for(int i=1; i<=row; i++){
	 	for(int j=1; j<=row-i; j++){
	 		cout << "  ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	cout << "* ";
		 }
		 cout << endl;
	 }
	 for(int i=row; i>=1; i--){
	 	for(int j=1; j<=row-i; j++){
	 		cout << "  ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	cout << "* ";
		 }
		 cout << endl;
	 }
	 
	 // Hollow Diamond Pattern
/*
        *
      *   *
    *       *
  *           *
*               *
*               *
  *           *
    *       *
      *   *
        *
*/
	 cout << endl<< endl;
	 for(int i=1; i<=row; i++){
	 	for(int j=1; j<=row-i; j++){
		 	cout << "  ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	if(j==1 || j==2*i-1){
		 		cout << "* ";
			 }
			else { 
			 	cout << "  ";
			 }
		 }
		 cout << endl;
	 }
	 for(int i=row; i>=1; i--){
	 	for(int j=1; j<=row-i; j++){
		 	cout << "  ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	if(j==1 || j==2*i-1){
		 		cout << "* ";
			 }
			else { 
			 	cout << "  ";
			 }
		 }
		 cout << endl;
	 }
	 
	 // Hollow Diamong inscribed in retangle
/*
* * * * * * * * *
* * * *   * * * *
* * *       * * *
* *           * *
*               *
*               *
* *           * *
* * *       * * *
* * * *   * * * *
* * * * * * * * *
*/
	 cout << endl<< endl;
	 for(int i=1; i<=row; i++){
	 	for(int j=1; j<=row-i; j++){
		 	cout << "* ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	if(j==1 || j==2*i-1){
		 		cout << "* ";
			 }
			else { 
			 	cout << "  ";
			 }
		 }
		 for(int j=1; j<=row-i; j++){
		    cout << "* ";	
		 }	 
		 cout << endl;
	 }
	 for(int i=row; i>=1; i--){
	 	for(int j=1; j<=row-i; j++){
		 	cout << "* ";
		 }
		 for(int j=1; j<=2*i-1; j++){
		 	if(j==1 || j==2*i-1){
		 		cout << "* ";
			 }
			else { 
			 	cout << "  ";
			 }
		 }
		 for(int j=1; j<=row-i; j++){
		    cout << "* ";	
		 }	 
		 cout << endl;
	 }
	 
	 // Zig Zag pattern for n=9 ====> 3 rows
/*
  *   *
 * * * *
*   *   *
*/
	 cout << endl << endl;
	 for(int i=1;i<=3;i++){
	 	for(int j=1;j<=row;j++){
	 		if((i+j)%4==0 || (i==2 && j%2==0)){
	 			cout << "*";
			 }
			 else {
			 cout << " ";
			}
		 }
		 cout << endl;
	 } 
}
