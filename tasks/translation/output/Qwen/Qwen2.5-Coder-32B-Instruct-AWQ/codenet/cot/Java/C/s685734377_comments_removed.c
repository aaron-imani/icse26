#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *in;
    char *buffer;
    char *next_token;
} FastScanner;

FastScanner* createFastScanner(FILE *in) {
    FastScanner *fs = (FastScanner*)malloc(sizeof(FastScanner));
    fs->in = in;
    fs->buffer = NULL;
    fs->next_token = NULL;
    return fs;
}

int nextInt(FastScanner *fs) {
    return atoi(next(fs));
}

char* next(FastScanner *fs) {
    if (fs->next_token == NULL || *fs->next_token == '\0') {
        if (getline(&fs->buffer, NULL, fs->in) == -1) {
            return NULL;
        }
        fs->next_token = strtok(fs->buffer, " \n");
    } else {
        fs->next_token = strtok(NULL, " \n");
    }
    return fs->next_token;
}

void solve(int n, char a[n][n], long P, long Q, FILE *out) {
    long powP[n + 1], powQ[n + 1];
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    long hashRow[n][n], hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    fprintf(out, "%d\n", ans);
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    FILE *out = stdout;

    int n = nextInt(in);
    char a[n][n];
    for (int i = 0; i < n; i++) {
        char *line = next(in);
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j];
        }
    }

    long P = 37, Q = 47;
    solve(n, a, P, Q, out);

    free(in->buffer);
    free(in);
    fclose(out);
    return 0;
}
// End of Code
