#include <stdio.h>
#include <string.h>

int is_even_string(char *s) {
    int len = strlen(s);
    char *a = (char *)malloc((len / 2 + 1) * sizeof(char));
    char *b = (char *)malloc((len / 2 + 1) * sizeof(char));
    
    strncpy(a, s, len / 2);
    a[len / 2] = '\0';
    strncpy(b, s + len / 2, len / 2);
    b[len / 2] = '\0';
    
    if (strcmp(a, b) == 0) {
        free(a);
        free(b);
        return 1;
    }
    free(a);
    free(b);
    return 0;
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
        if (is_even_string(S)) {
            break;
        }
        S[strlen(S) - 2] = '\0';
    }
    
    printf("%ld\n", strlen(S));
    return 0;
}
// End of Code
