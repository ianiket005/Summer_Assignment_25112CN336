#include <stdio.h>
#include <math.h>


int isArmstrong(int num) {
    int temp = num, remainder, digits = 0, sum = 0;
    
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
    
    return (sum == num);
}
    




int main() {
    int lower, upper;
    
    printf("Enter lower bound: ");
    scanf("%d", &lower);
    printf("Enter upper bound: ");
    scanf("%d", &upper);
    
    printf("Armstrong numbers between %d and %d are:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}