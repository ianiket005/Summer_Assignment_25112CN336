#include <stdio.h>

int main() {
    int arr[100], n, key, i, count = 0;

   
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter element to find frequency: ");
    scanf("%d", &key);

    
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            count++;
        }
    }

    
    if(count > 0)
        printf("Frequency of %d = %d\n", key, count);
    else
        printf("Element not found in array.\n");

    return 0;
}
