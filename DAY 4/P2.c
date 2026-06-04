#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else if (n == 1) {
        printf("The 1st Fibonacci term is: 0\n");
    } else if (n == 2) {
        printf("The 2nd Fibonacci term is: 1\n");
    } else {
        int a = 0, b = 1, nextTerm = 0;
        for (int i = 3; i <= n; i++) {
            nextTerm = a + b;
            a = b;
            b = nextTerm;
        }
        printf("The %dth Fibonacci term is: %d\n", n, b);
    }
    return 0;
}