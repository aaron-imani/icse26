#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef long long ll;

ll powP[MAX_N + 1], powQ[MAX_N + 1];
char a[MAX_N][MAX_N];
ll hashRow[MAX_N][MAX_N], hashCol[MAX_N][MAX_N];

void solve(int n) {
    ll P = 37, Q = 47;
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}
// End of Code
