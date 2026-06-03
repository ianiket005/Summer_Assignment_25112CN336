#include <stdio.h>

int main() {
    int num1, num2, n1, n2, temp, gcd, lcm;

    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    
    n1 = num1;
    n2 = num2;

    
    while (n2 != 0) {
        temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    
    gcd = n1; 

    
    lcm = (num1 * num2) / gcd;

    
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("The LCM of %d and %d is: %d\n", num1, num2, lcm);

    return 0;
}