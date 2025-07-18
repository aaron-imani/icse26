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

double nextDouble(InputIterator *ii) {
    char *str = next(ii);
    return atof(str);
}

char **nextStrArray(InputIterator *ii) {
    char *str = next(ii);
    char **array = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        array[count++] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(str);
    return array;
}

void freeStrArray(char **array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

void solve(InputIterator *ii) {
    int N = nextInt(ii);
    char **list = nextStrArray(ii);
    int *intList = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        intList[i] = atoi(list[i]);
    }
    freeStrArray(list, N);
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= intList[i]) {
            max = intList[i];
            output++;
        }
    }
    printf("%d\n", output);
    free(intList);
}

int main() {
    InputIterator *ii = createInputIterator();
    solve(ii);
    freeInputIterator(ii);
    return 0;
}
// End of Code
