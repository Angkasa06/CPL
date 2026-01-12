#include <stdio.h>

void Sorting(int n, int arr[]) {
	int Temp, minIndex;
	for(int i = 0; i < n-1; i++) {
		minIndex = i;
		for(int j = i+1; j < n; j++) {
			if(arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		
		Temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = Temp;
	}
	
	printf("> ");
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int Searching(int x, int arr[], int Min, int Max) {
	if(Min > Max) {
		return -1;
	}
	
	int Mid = (Min + Max) / 2;
	
	if(arr[Mid] == x) {
		return Mid;
	} else if(arr[Mid] > x) {
		return Searching(x, arr, Min, Mid-1);
	} else {
		return Searching(x, arr, Mid+1, Max);
	}
}

int main() {
	int x;
	printf("> ");
	scanf("%d", &x);
	
	int num;
	printf("> ");
	scanf("%d", &num);
	
	int ar[num];
	printf("> ");
	for(int i = 0; i < num; i++) {
		scanf("%d", &ar[i]);
	}
	
	// Selection Sort
	Sorting(num, ar);
	
	// Binary Search
	int idx = Searching(x, ar, 0, num-1);
	if(idx != -1) {
		printf("\nThe number you are looking for is at index %d", idx);
	} else printf("\nNumber not found.");
	
	return 0;
}
