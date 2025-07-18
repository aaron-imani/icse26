#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int penal[n+1];
    memset(penal, 0, sizeof(penal));
    
    char solved[n+1];
    memset(solved, 0, sizeof(solved));
    
    for(int i=0; i<m; i++) {
        int num;
        char str[2];
        scanf("%d %s", &num, str);
        if(str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (solved[num] == 0) {
                penal[num]++;
            }
        }
    }
    
    int correct_ans = 0;
    int num_penal = 0;
    for(int i=1; i<=n; i++) {
        if(solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }
    
    printf("%d %d\n", correct_ans, num_penal);
    return 0;
}
// End of Code
