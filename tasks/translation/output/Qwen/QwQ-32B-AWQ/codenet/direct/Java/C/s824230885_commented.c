#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *array = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] >= max) {
            max = array[i];
            output++;
        }
    }
    printf("%d\n", output);
    free(array);
    return 0;
}
// End of Code
