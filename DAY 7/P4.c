#include <stdio.h>


int reverseNumber(int num, int rev) {
    if (num == 0) {
        return rev;   
    } else {
        return reverseNumber(num / 10, rev * 10 + (num % 10));  
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Reverse of %d = -%d\n", num, reverseNumber(-num, 0)); 
    } else {
        printf("Reverse of %d = %d\n", num, reverseNumber(num, 0));
    }

    return 0;
}
