#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Consume the newline after reading N

    char line[100000];
    fgets(line, sizeof(line), stdin);

    int *arr = malloc(N * sizeof(int));
    if (!arr) return 1;

    char *token = strtok(line, " ");
    for (int i = 0; i < N; i++) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    int max = 0, output = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            output++;
        }
    }

    printf("%d\n", output);
    free(arr);
    return 0;
}
// End of Code
