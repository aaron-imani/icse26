#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *list = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &list[i]);
    }
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (list[i] >= max) {
            max = list[i];
            output++;
        }
    }
    printf("%d\n", output);
    free(list);
    return 0;
}
// End of Code
