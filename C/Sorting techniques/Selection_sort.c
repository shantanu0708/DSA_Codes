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
	
	for(i = 0; i < n-1; i++) {
		int min = i;
		for(j = i + 1; j < n; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		if(min != i) {
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
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
