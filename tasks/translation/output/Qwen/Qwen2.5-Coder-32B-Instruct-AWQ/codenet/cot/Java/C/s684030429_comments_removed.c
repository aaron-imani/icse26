#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ni(FILE *sc) {
    int a;
    fscanf(sc, "%d", &a);
    return a;
}

void solve(FILE *sc) {
    int a = ni(sc);
    int b = ni(sc);

    printf("%d\n", max(0, a - 2 * b));
}

int main() {
    FILE *sc = stdin;
    if (!sc) {
        printf("Error opening input.\n");
        return 1;
    }
    solve(sc);
    fclose(sc);
    return 0;
}
// End of Code
