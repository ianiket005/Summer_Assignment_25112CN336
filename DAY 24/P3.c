#include <stdio.h>
#include <string.h>

void findLongestWord(char str[]) {
    int maxLen = 0, currLen = 0;
    char longest[100], word[100];
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            word[j++] = str[i];
            currLen++;
        } else {
            word[j] = '\0';
            if (currLen > maxLen) {
                maxLen = currLen;
                strcpy(longest, word);
            }
            j = 0;
            currLen = 0;
        }
        i++;
    }

    
    word[j] = '\0';
    if (currLen > maxLen) {
        maxLen = currLen;
        strcpy(longest, word);
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLen);
}

int main() {
    char str[200];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    
    str[strcspn(str, "\n")] = '\0';

    findLongestWord(str);

    return 0;
}
