#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_LINE_LENGTH 1024

typedef struct {
    char inputLine[MAX_INPUT_SIZE][MAX_LINE_LENGTH];
    int index;
    int max;
} InputIterator;

InputIterator ii;

void initInputIterator() {
    ii.index = 0;
    ii.max = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (ii.max < MAX_INPUT_SIZE) {
            strcpy(ii.inputLine[ii.max], line);
            ii.max++;
        }
    }
}

int hasNext() {
    return (ii.index < ii.max);
}

char* next() {
    if (hasNext()) {
        return ii.inputLine[ii.index++];
    } else {
        fprintf(stderr, "There is no more input\n");
        exit(1);
    }
}

int nextInt() {
    char* str = next();
    return atoi(str);
}

void solve() {
    int N = nextInt();
    int list[N];
    for (int i = 0; i < N; i++) {
        list[i] = nextInt();
    }
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list[i]) {
            max = list[i];
            output++;
        }
    }
    printf("%d\n", output);
}

int main() {
    initInputIterator();
    solve();
    return 0;
}
// End of Code
