#include <stdio.h>
#include <string.h>

void removeDuplicates(char str[]) {
    int len = strlen(str);
    int index = 0; 
    int seen[256] = {0};

    for (int i = 0; i < len; i++) {
        if (seen[(unsigned char)str[i]] == 0) {
            str[index++] = str[i];   
            seen[(unsigned char)str[i]] = 1;
        }
    }
    str[index] = '\0'; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}
