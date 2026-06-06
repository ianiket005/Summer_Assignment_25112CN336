#include <stdio.h>

int main() {
    int x, n;
    long long result = 1;  

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    
    if (n < 0) {
        printf("Negative exponents not supported in integer calculation.\n");
        return 0;
    }

    
    for (int i = 0; i < n; i++) {
        result *= x;
    }

    printf("%d^%d = %lld\n", x, n, result);

    return 0;
}
