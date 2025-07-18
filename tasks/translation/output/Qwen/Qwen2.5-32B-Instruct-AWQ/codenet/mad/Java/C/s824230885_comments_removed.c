#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    char **inputLine;
    int index;
    int max;
} InputIterator;

InputIterator *createInputIterator() {
    InputIterator *ii = (InputIterator *)malloc(sizeof(InputIterator));
    ii->inputLine = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));
    ii->index = 0;
    ii->max = 0;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        ii->inputLine[ii->max++] = strdup(line);
    }
    free(line);
    return ii;
}

int hasNext(InputIterator *ii) {
    return (ii->index < ii->max);
}

char *next(InputIterator *ii) {
    if (hasNext(ii)) {
        return ii->inputLine[ii->index++];
    } else {
        fprintf(stderr, "There is no more input\n");
        exit(1);
    }
}

void freeInputIterator(InputIterator *ii) {
    for (int i = 0; i < ii->max; i++) {
        free(ii->inputLine[i]);
    }
    free(ii->inputLine);
    free(ii);
}

int nextInt(InputIterator *ii) {
    char *str = next(ii);
    return atoi(str);
}

char **splitString(char *str, char delimiter) {
    char *token;
    char **tokens = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));
    int count = 0;
    token = strtok(str, &delimiter);
    while (token != NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    tokens[count] = NULL;
    return tokens;
}

int *nextIntArray(InputIterator *ii, int *size) {
    char *str = next(ii);
    char **tokens = splitString(str, ' ');
    int *array = (int *)malloc(MAX_INPUT_SIZE * sizeof(int));
    *size = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        array[(*size)++] = atoi(tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    free(str);
    return array;
}

void solve() {
    InputIterator *ii = createInputIterator();
    int N = nextInt(ii);
    int size;
    int *list = nextIntArray(ii, &size);
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
    freeInputIterator(ii);
}

int main() {
    solve();
    return 0;
}
// End of Code
