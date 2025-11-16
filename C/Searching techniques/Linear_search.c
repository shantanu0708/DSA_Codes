#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int target) {
	int i;
	for(i = 0; i < n; i++) {
		if(arr[i] == target) {
			return i + 1;
		}
	}
	return -1;
}

int main(void) {
	int n, i, target;
	
	if(scanf("%d", &n) != 1 || n < 0 ) return 1;
	
	int *arr = malloc(sizeof(int) * (size_t)n);
	if(!arr) return 1;
	
	for(i = 0; i < n; i++) {
		if(scanf("%d", &arr[i]) != 1) {
			free(arr);
			return 1;
		}
	}
	
	if(scanf("%d", &target) != 1) {
		free(arr);
		return 1;
	}
	
	int index = linear_search(arr, n, target);
	printf("The %d is found at %d", target, index);
}
