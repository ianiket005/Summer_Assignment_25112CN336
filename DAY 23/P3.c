#include <stdio.h>
#include <string.h>

#define CHAR_SIZE 256 

int main() {
    char str1[100], str2[100];
    int freq[CHAR_SIZE] = {0};
    int i;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

   
    if (strlen(str1) != strlen(str2)) {
        printf("Strings are NOT anagrams.\n");
        return 0;
    }

   
    for (i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)str1[i]]++;
    }

   
    for (i = 0; str2[i] != '\0'; i++) {
        freq[(unsigned char)str2[i]]--;
    }

   
    for (i = 0; i < CHAR_SIZE; i++) {
        if (freq[i] != 0) {
            printf("Strings are NOT anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams!\n");
    return 0;
}
