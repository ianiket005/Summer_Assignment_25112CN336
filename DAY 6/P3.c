#include <stdio.h>

int main() {
    unsigned int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%u", &num);

    while (num > 0) {
        count += num & 1;   
        num >>= 1;          
    }

    printf("Number of set bits: %d\n", count);

    return 0;
}
