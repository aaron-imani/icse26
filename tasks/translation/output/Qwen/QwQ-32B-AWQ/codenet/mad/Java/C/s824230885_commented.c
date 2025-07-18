#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    char buffer[100000];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 1;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    char *token = strtok(buffer, " ");
    int *arr = malloc(N * sizeof(int));
    if (!arr) {
        return 1;
    }
    int i;
    for (i = 0; i < N; i++) {
        if (!token) {
            free(arr);
            return 1;
        }
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    int max = 0;
    int output = 表达了 0;
    for (i = 0; i < N; i++) {
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
