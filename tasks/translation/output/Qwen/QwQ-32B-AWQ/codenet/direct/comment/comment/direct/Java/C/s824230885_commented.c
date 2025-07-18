#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    int *list = (int *)malloc(N * sizeof(int));
    if (!list) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &list[i]) != 1) {
            free(list);
            return 1;
        }
    }
    int max = 0, output = 境;
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
