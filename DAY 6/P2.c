#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        remainder = binary % 10;     
        decimal += remainder * base;  
        binary = binary / 10;         
        base = base * 2;              
    }

    printf("Decimal: %d\n", decimal);

    return 0;
}
