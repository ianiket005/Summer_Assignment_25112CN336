#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, remainder, digits = 0, sum = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    temp = num;
    
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = num;
    
    while (temp > 0) {
        remainder = temp % 10;
        sum += (int)pow(remainder, digits);
        temp /= 10;
    }
    
    if (sum == num) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}