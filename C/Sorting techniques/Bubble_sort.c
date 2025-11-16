#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, i, j;
	printf("Enter size of array:");
	if(scanf("\n%d", &n) != 1 || n < 0 ) return 1;
	
	int *arr = malloc(sizeof(int) * (size_t)n);
	if(!arr) return 1;
	
	printf("Enter elements: \n");
	for(i = 0; i < n; i++) {
		if(scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 1;
		}
	}
	
	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	
	printf("Sorted array is :");
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	free(arr);
	return 0;
}
