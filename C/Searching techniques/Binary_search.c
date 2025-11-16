#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int n, int target) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == target) return mid + 1;
        if (arr[mid] < target) l = mid + 1;
        else h = mid - 1;
    }
    return -1;
}

int main(void) {
    int n, i, target;
    if (scanf("%d", &n) != 1 || n < 0) return 1; // checking n size is greater than 1 for array size

    int *arr = malloc(sizeof(int) * (size_t)n); // malloc is used for dynamic allocation of data with variable.
    if (!arr) return 1;

    for ( i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    if (scanf("%d", &target) != 1) {
        free(arr);
        return 1;
    }

    int index = binary_search(arr, n, target);
    printf("%d\n", index);

    free(arr);
    return 0;
}
