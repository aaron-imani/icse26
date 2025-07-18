#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_LINE_LENGTH 1024

char inputLines[MAX_INPUT][MAX_LINE_LENGTH];
int index = 0;
int maxIndex = 0;

void readInput() {
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        strcpy(inputLines[index++], line);
    }
    maxIndex = index;
    free(line);
}

int hasNext() {
    return (index < maxIndex);
}

char* next() {
    if (hasNext()) {
        return inputLines[index++];
    } else {
        fprintf(stderr, "There is no more input\n");
        exit(1);
    }
}

int nextInt() {
    return atoi(next());
}

int* nextIntArray(int *size) {
    char *line = next();
    int count = 0;
    int *arr = (int*)malloc(MAX_INPUT * sizeof(int));
    char *token = strtok(line, " ");
    while (token != NULL) {
        arr[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    *size = count;
    return arr;
}

void solve() {
    int N = nextInt();
    int size;
    int *list = nextIntArray(&size);
    int max = 0;
    int output = 0;
    for (int i = 0; i < size; i++) {
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
