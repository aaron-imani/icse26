#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int N = nextInt();
    int *list = (int *)malloc(N * sizeof(int));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
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
    return 0;
}
// End of Code
