#include <stdio.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    char s[N+1];
    scanf("%s", s);
    int *pre = (int*)malloc((N + 1)*sizeof(int));
    for (int i = 0; i <= N; i++) pre[i] = 0;
    for (int i = 1; i < N; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            pre[i] = 1;
        }
    }
    for (int i = 1; i < N; i++) {
        pre[i] += pre[i - 1];
    }
    while (Q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        r--;
        printf("%d\n", pre[r] - pre[l - 1]);
    }
    free(pre);
    return 0;
}
// End of Code
