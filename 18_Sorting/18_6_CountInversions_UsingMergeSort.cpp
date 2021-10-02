// Count the number of inversions in an array using merge Sort -------------- O(n) = nlogn
// Given array is split into half recursively and then it is sorted and merged to get final sorted array.
// We count the number of inversions in merge step when we compare two sorted arrays. Add up all the inversions from every step and print the answer.
//Ex : a[] = {3, 5, 6, 9, 1, 2, 7, 8}----------- Output : 10. (The inversions are (3,1), (3,2), (5,1), (5,2), (6,1), (6,2), (9,1), (9,2), (9,7), (9,8))


#include<iostream>
using namespace std;

// --------- BruteForce ------------
//  int count_inversions = 0;
//  for(int i = 0; i < n; i++){
//      for(int j = i + 1; j < n; j++){
//           if(a[i] > a[j])
//                count_inversions++;
//       }
//  }
//  cout << count_inversions;

long long Merge(int a[],int l, int mid, int r){
	long long count_inversions = 0;
	int n1 = mid-l+1;    // No of elements in left sorted array   
	int n2 = r-mid;      // No of elemts in right sorted array  
	int temp1[n1];
	int temp2[n2];
	
	for(int i=0; i<n1;i++){      // Filling temp1[] with elements of left sorted array
		temp1[i]=a[l+i];
	}
	for(int i=0; i<n2;i++){      // Filling temp2[] with elements of right sorted array
		temp2[i]=a[mid+1+i];
	}
	
	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(temp1[i]<temp2[j]){
			a[k]= temp1[i];
			k++;i++;
		}
		else{
			a[k]=temp2[j];
			count_inversions += n1-i;          // Since temp1[i] > temp2[j], their are inversions in a[]. Therefore number of inversions = n1-i (include all elements in temp1 from i to n1-1
			k++;j++;
		}
	}
	while(i<n1){
		a[k]=temp1[i];
		k++; i++;
	}
	while(j<n2){
		a[k]= temp2[j];
		k++;j++;
	}
	return count_inversions;
}

long long MergeSort(int a[],int l, int r){
	long long count_inversions=0;
	if(l<r){
		int mid = (l+r)/2;
		count_inversions += MergeSort(a, l, mid);
		count_inversions += MergeSort(a, mid+1, r);	
		count_inversions += Merge(a,l,mid,r);
	}	
	return count_inversions;
}
int main(){
	cout << "Enter no of elements in array : ";
	int n;
	cin >> n;
	int a[n];
	cout << "Enter array elements:  ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	long long count_inversions; 
	count_inversions= MergeSort(a,0, n-1);
	cout << count_inversions;
	return 0;
}

