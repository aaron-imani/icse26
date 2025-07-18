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
    char *read = (char *)malloc(1024 * sizeof(char));
    while (fgets(read, 1024, stdin) != NULL) {
        ii->inputLine[ii->max] = strdup(read);
        ii->max++;
    }
    free(read);
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

int nextInt(InputIterator *ii) {
    return atoi(next(ii));
}

char **myconv(char *str, int no) {
    char *splitString = (no == 0) ? "" : (no == 8) ? " " : "\n";
    char *token = strtok(str, splitString);
    char **ret = (char **)malloc(sizeof(char *));
    int i = 0;
    while (token != NULL) {
        ret[i] = strdup(token);
        token = strtok(NULL, splitString);
        i++;
        ret = (char **)realloc(ret, (i + 1) * sizeof(char *));
    }
    return ret;
}

void solve(InputIterator *ii) {
    int N = nextInt(ii);
    char **list = myconv(next(ii), 8);
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        int num = atoi(list[i]);
        if (max <= num) {
            max = num;
            output++;
        }
    }
    printf("%d\n", output);
}

int main() {
    InputIterator *ii = createInputIterator();
    solve(ii);
    return 0;
} // End of Code
