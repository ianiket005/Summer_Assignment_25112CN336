#include <stdio.h>
#include <stdbool.h>

int main() {
    int num;
    bool isPrime = true;

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &num);
34
    // 0 and 1 are not prime numbers
    if (num <= 1) {
        isPrime = false;
    } else {
        // Check for factors from 2 up to num / 2 (or sqrt(num))
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false; 
                break;           
            }
        }
    }

    
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
