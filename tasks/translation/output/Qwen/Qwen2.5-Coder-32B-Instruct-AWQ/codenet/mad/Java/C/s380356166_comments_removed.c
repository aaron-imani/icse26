#include <stdio.h>

int readInt() {
    int ret = 0;
    char c = getchar();
    int sign = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            sign = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * sign;
}

int main() {
    int ans = 0;
    int K = readInt();
    int S = readInt();
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
