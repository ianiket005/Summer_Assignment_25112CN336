#include <stdio.h>

int main() {
    int num1, num2, n1, n2, temp;

    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    
    n1 = num1;
    n2 = num2;

    
    while (n2 != 0) {
        temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }

   
    printf("The GCD of %d and %d is: %d\n", num1, num2, n1);

    return 0;
}