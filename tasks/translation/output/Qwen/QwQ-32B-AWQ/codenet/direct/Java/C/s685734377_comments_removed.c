#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    FILE *stream;
    char *current_line;
    size_t current_line_length;
    char *token_ptr;
} FastScanner;

void FastScanner_Init(FastScanner *scanner, FILE *stream) {
    scanner->stream = stream;
    scanner->current_line = NULL;
    scanner->current_line_length = 0;
    scanner->token_ptr = NULL;
}

char *FastScanner_Next(FastScanner *scanner) {
    while (1) {
        if (scanner->token_ptr == NULL || *scanner->token_ptr == '\0') {
            if (scanner->current_line != NULL) {
                free(scanner->current_line);
                scanner->current_line = NULL;
                scanner->token_ptr = NULL;
            }
            char *line = NULL;
            size_t len = 0;
            ssize_t bytes = getline(&line, &len, scanner->stream);
            if (bytes == -1) return NULL;
            scanner->current_line = line;
            scanner->token_ptr = line;
        }
        char *token = scanner->token_ptr;
        char *end = token;
        while (*end != '\0' && !isspace((unsigned char)*end)) end++;
        if (*end == '\0') {
            scanner->token_ptr = end;
        } else {
            *end = '\0';
            scanner->token_ptr = end + 1;
        }
        return token;
    }
}

int main() {
    FastScanner scanner;
    FastScanner_Init(&scanner, stdin);
    
    int n = atoi(FastScanner_Next(&scanner));
    
    char **a = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc((n + 1) * sizeof(char));
    }
    
    for (int i = 0; i < n; i++) {
        char *line = FastScanner_Next(&scanner);
        strcpy(a[i], line);
    }
    
    long long powP[n+1];
    long long powQ[n+1];
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i-1] * 37;
        powQ[i] = powQ[i-1] * 47;
    }
    
    long long hashRow[n][n];
    long long hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod_jk = (j - k + n) % n;
                int mod_ik = (i - k + n) % n;
                hashRow[i][k] += a[i][j] * powP[mod_jk];
                hashCol[j][k] += a[i][j] * powP[mod_ik];
            }
        }
    }
    
    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row_idx = (i + A) % n;
                int col_idx = (i + B) % n;
                if (hashRow[row_idx][B] != hashCol[col_idx][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    
    printf("%d\n", ans);
    
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    
    return 0;
}

// End of Code
