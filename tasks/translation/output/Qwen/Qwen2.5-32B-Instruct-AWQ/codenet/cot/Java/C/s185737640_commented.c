#include <stdio.h>
#include <string.h>

int isEvenString(char *s) {
    int len = strlen(s);
    char *a = (char *)malloc((len / 2 + 1) * sizeof(char));
    char *b = (char *)malloc((len / 2 + 1) * sizeof(char));
    strncpy(a, s, len / 2);
    a[len / 2] = '\0';
    strncpy(b, s + len / 2, len / 2);
    b[len / 2] = '\0';
    int result = strcmp(a, b) == 0;
    free(a);
    free(b);
    return result;
}

int main() {
    char S[1000];
    fgets(S, 1000, stdin);
    S[strcspn(S, "\n")] = 0;

    if(strlen(S) % 2 == 1) {
        S[strlen(S) - 1] = '\0';
    } else {
        S[strlen(S) - 2] = '\0';
    }

    while(strlen(S) > 0) {
        if(isEvenString(S)) {
            break;
        }
        S[strlen(S) - 2] = '\0';
    }

    printf("%ld\n", strlen(S));
    return 0;
}
// End of Code
