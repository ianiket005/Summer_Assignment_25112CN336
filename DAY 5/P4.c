#include <stdio.h>


int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    long long num;
    int largestPrime = -1;

    printf("Enter a number: ");
    scanf("%lld", &num);

    
    for (long long i = 2; i <= num; i++) {
        if (num % i == 0 && isPrime(i)) {
            largestPrime = i;
        }
    }

    if (largestPrime != -1) {
        printf("Largest Prime Factor of %lld is %d\n", num, largestPrime);
    } else {
        printf("%lld has no prime factors.\n", num);
    }

    return 0;
}