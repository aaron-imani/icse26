#include <stdio.h>
#include <string.h>

int isEvenString(char *s) {
    int len = strlen(s);
    int half = len / 2;
    char a[half + 1];
    char b[half + 1];
    
    strncpy(a, s, half);
    a[half] = '\0';
    strncpy(b, s + half, half);
    b[half] = '\0';
    
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
