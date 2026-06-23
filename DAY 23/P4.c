#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};  
    int i, maxFreq = 0;
    char maxChar;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n') {  
            freq[(unsigned char)str[i]]++;
            if(freq[(unsigned char)str[i]] > maxFreq) {
                maxFreq = freq[(unsigned char)str[i]];
                maxChar = str[i];
            }
        }
    }

    printf("Maximum occurring character: '%c'\n", maxChar);
    printf("Frequency: %d\n", maxFreq);

    return 0;
}
