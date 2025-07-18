#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int first;
    scanf("%d", &first);
    int max = first;
    int min = first;
    int in;
    for (int i = 1; i < N; i++) {
        scanf("%d", &in);
        if (in > max) max = in;
        if (in < min) min = in;
    }
    printf("%d\n", max - min);
    return 0;
}
// End of Code
