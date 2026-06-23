#include <stdio.h>
#include <string.h>

#define CHAR_SIZE 256 

int main() {
    char str[100];
    int freq[CHAR_SIZE] = {0};  
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First repeating character: %c\n", str[i]);
            return 0;
        }
        freq[(unsigned char)str[i]]++;
    }

    printf("No repeating character found.\n");
    return 0;
}
