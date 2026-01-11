#include <stdio.h>

void SelectionSort(int n, int arr[]) {
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

int BinarySearch(int x, int arr[], int Min, int Max) {
	if(Min > Max) {
		return 0;
	}
	
	int Mid = (Min + Max) / 2;
	
	if(arr[Mid] == x) {
		return 1;
	} else if(arr[Mid] > x) {
		return BinarySearch(x, arr, Min, Mid-1);
	} else return BinarySearch(x, arr, Mid+1, Max);
	
	return 0;
}

int main() {
	int x;	
	printf("Angka yang dicari? ");
	scanf("%d", &x);
	
	int num;
	printf("Banyak data?       ");
	scanf("%d", &num);
	
	// Input Data
	int ar[num];
	printf("> ");
	for(int i = 0; i < num; i++) {
		scanf("%d", &ar[i]);
	}
	
	// Syarat Binary Sort: Data harus diurut dari terkecil ke terbesar
	SelectionSort(num, ar);
	
	// Mencari nilai yang kita inginkan
	if(BinarySearch(x, ar, 0, num-1)) {
		printf("\nAda");
	} else printf("\nTidak ada");
	
	return 0;
}