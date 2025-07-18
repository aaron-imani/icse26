#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    FILE *br;
    char *st;
    char *token;
} FastReader;

FastReader* createFastReader() {
    FastReader *fr = (FastReader*)malloc(sizeof(FastReader));
    fr->br = stdin;
    fr->st = NULL;
    fr->token = NULL;
    return fr;
}

char* next(FastReader *fr) {
    if (fr->st == NULL || fr->token == NULL) {
        fr->st = (char*)malloc(MAX * sizeof(char));
        if (fgets(fr->st, MAX, fr->br) == NULL) {
            return NULL;
        }
        fr->token = strtok(fr->st, " \n");
    } else {
        fr->token = strtok(NULL, " \n");
    }
    return fr->token;
}

int nextInt(FastReader *fr) {
    return atoi(next(fr));
}

int main() {
    FastReader *s = createFastReader();
    int i, j;
    int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
    long a, b, sum;

    char str[MAX];

    n = nextInt(s);
    m = nextInt(s);

    int penal[n+1];
    bool solved[n+1];
    for (i = 0; i <= n; i++) {
        solved[i] = false;
    }

    for (i = 0; i < m; i++) {
        num = nextInt(s);
        next(s); // Read the string but not used
        if (str[0] == 'A') {
            solved[num] = true;
        } else {
            if (solved[num] == false) {
                penal[num]++;
            }
        }
    }

    correct_ans = 0;
    num_penal = 0;
    for (i = 1; i <= n; i++) {
        if (solved[i] == true) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    free(s->st);
    free(s);
    return 0;
}
// End of Code
