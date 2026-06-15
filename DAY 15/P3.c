#include <stdio.h>


void rotateRight(int arr[], int n) {
    int temp = arr[n - 1]; 
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[0] = temp; 
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    
    for (int i = 0; i < k; i++) {
        rotateRight(arr, n);
    }

    printf("Array after %d right rotations:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
