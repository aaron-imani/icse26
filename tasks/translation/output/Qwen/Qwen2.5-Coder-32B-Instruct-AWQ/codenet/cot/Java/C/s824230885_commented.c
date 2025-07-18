#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

char input[MAX_INPUT][MAX_INPUT];
int inputIndex = 0;
int maxInput = 0;

void readInput() {
    while (fgets(input[inputIndex], MAX_INPUT, stdin) != NULL) {
        inputIndex++;
    }
    maxInput = inputIndex;
}

int hasNext() {
    return (inputIndex < maxInput);
}

char* next() {
    if (hasNext()) {
        return input[inputIndex++];
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
    int* list = (int*)malloc(N * sizeof(int));
    int max = 0;
    int output = 0;
    
    for (int i = 0; i < N; i++) {
        list[i] = nextInt();
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
