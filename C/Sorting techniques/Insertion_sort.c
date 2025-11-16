#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, i, j;
	
	if(scanf("%d", &n) != 1 || n < 0 ) return 1;
	
	int *arr = malloc(sizeof(int) * (size_t)n);
	if(!arr) return 1;
	
	for(i = 0; i < n; i++) {
		if(scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 1;
		}
	}
	
	for(i = 1; i < n; i++) {
		int key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	
	printf("Sorted array is :");
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	free(arr);
	return 0;
}
