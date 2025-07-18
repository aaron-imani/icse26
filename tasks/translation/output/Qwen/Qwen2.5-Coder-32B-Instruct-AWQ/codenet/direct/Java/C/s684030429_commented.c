#include <stdio.h>
#include <stdlib.h>

int ni() {
    int a;
    scanf("%d", &a);
    return a;
}

long nl() {
    long a;
    scanf("%ld", &a);
    return a;
}

float nf() {
    float a;
    scanf("%f", &a);
    return a;
}

double nd() {
    double a;
    scanf("%lf", &a);
    return a;
}

void solve() {
    int a = ni();
    int b = ni();

    printf("%d\n", (a - 2 * b) > 0 ? (a - 2 * b) : 0);
}

int main() {
    solve();
    return 0;
}
// End of Code
