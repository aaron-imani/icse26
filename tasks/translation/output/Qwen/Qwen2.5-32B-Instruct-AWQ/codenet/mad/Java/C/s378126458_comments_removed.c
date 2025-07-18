#include <stdio.h>
#include <string.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    char s[N+1];
    scanf("%s", s);
    int pre[N+1];
    memset(pre, 0, sizeof(pre));

    for(int i = 1; i < N; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            pre[i] = 1;
        }
    }

    for(int i = 1; i < N; i++) {
        pre[i] += pre[i-1];
    }

    while(Q-- > 0) {
        int l, r;
        scanf("%d %d", &l, &r);
        r--;
        printf("%d\n", pre[r] - pre[l-1]);
    }
}
// End of Code
