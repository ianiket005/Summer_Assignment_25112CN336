#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the size of array (n-1): ");
    scanf("%d", &n);

    int arr[n];
    int sum = 0;

    printf("Enter %d elements (from 1 to n with one missing):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

   
    int total = (n + 1) * (n + 2) / 2;

    int missing = total - sum;
    printf("Missing number is: %d\n", missing);

    return 0;
}
