#include <stdio.h>
#include <string.h>

int isEvenString(char *s) {
    int len = strlen(s);
    int halfLen = len / 2;
    char a[halfLen + 1];
    char b[halfLen + 1];
    
    strncpy(a, s, halfLen);
    a[halfLen] = '\0';
    strncpy(b, s + halfLen, halfLen);
    b[halfLen] = '\0';
    
    return strcmp(a, b) == 0;
}

int main() {
    char S[1000];
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0; // Remove newline character
    
    int len = strlen(S);
    if (len % 2 == 1) {
        S[len - 1] = '\0';
    } else {
        S[len - 2] = '\0';
    }
    
    while (strlen(S) > 0) {
        if (isEvenString(S)) {
            break;
        }
        S[strlen(S) - 2] = '\0';
    }
    
    printf("%ld\n", strlen(S));
    
    return 0;
}
// End of Code
