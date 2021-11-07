// Selection sort

for(int i=0; i<n-1; i++){
	for(j=i+1; j<n; j++){
		if(a[j] < a[i]){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}

// Bubble sort

for(int i=0; i<n-1; i++){
	for(int j=0; j<n-1-i; j++){
		if(a[j] > a[j+1]){
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
	}
}

// Insertion sort

for(int i=1; i<n; i++){
	int curr = a[i];
	int j= i-1;
	while(j>=0 && a[j]>curr){
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = curr;
}
