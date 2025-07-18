#include <stdio.h>
#include <string.h>

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    char s[100005];
    scanf("%s", s);
    int pre[100005] = {0};
    
    for(int i = 1; i < N; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            pre[i] = 1; // initially the prefix sum array is the k array
        }
    }
    
    // Building the psa
    for(int i = 1; i < N; i++) {
        pre[i] += pre[i-1];
    }
    
    // Querying
    while(Q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        r--;
        printf("%d\n", pre[r] - pre[l-1]);
    }
} // End of Code
