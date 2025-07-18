#include <stdio.h>
#include <string.h>

int main() {
    unsigned int N, Q;
    scanf("%u %u", &N, &Q);
    char s[N+1];
    scanf("%s", s);
    int pre[N+1];
    memset(pre, 0, sizeof(pre));
    
    for(size_t i = 1; i < N; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            pre[i] = 1; // initially the prefix sum array is the k array
        }
    }
    
    // Building the psa
    for(size_t i = 1; i < N; i++) {
        pre[i] += pre[i-1];
    }
    
    // Querying
    while(Q-- > 0) {
        unsigned int l, r;
        scanf("%u %u", &l, &r);
        r--;
        printf("%d\n", pre[r] - pre[l-1]);
    }
    
    // End of Code
}
