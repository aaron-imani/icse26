#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INPUT_LINES 1024

char inputLines[MAX_INPUT_LINES][MAX_LINE_LENGTH];
int inputIndex = 0;
int inputMax = 0;

void readInput() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        if (inputIndex < MAX_INPUT_LINES) {
            strncpy(inputLines[inputIndex], line, MAX_LINE_LENGTH);
            inputLines[inputIndex][read - 1] = '\0'; // Remove newline character
            inputIndex++;
        }
    }
    inputMax = inputIndex;
    free(line);
}

int hasNext() {
    return (inputIndex < inputMax);
}

char* next() {
    if (hasNext()) {
        return inputLines[inputIndex++];
    } else {
        fprintf(stderr, "There is no more input\n");
        exit(1);
    }
}

int nextInt() {
    return atoi(next());
}

void solve() {
    int N = nextInt();
    int *list = (int *)malloc(N * sizeof(int));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

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
    free(list);
}

int main() {
    readInput();
    solve();
    return 0;
}
// End of Code
