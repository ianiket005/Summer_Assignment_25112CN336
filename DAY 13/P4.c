#include <stdio.h>
int main() {
    int arr[100], n, i;
    int evenCount = 0, oddCount = 0;

    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

       
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    
    printf("Total Even elements = %d\n", evenCount);
    printf("Total Odd elements = %d\n", oddCount);

    return 0;
}
