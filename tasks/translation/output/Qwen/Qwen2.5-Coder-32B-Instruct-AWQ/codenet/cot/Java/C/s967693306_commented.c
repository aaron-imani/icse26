#include <stdio.h>
#include <stdlib.h>

#define INF (1L << 62)
#define MOD 1000000007
#define SIZE 1000000

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

typedef struct {
    long a, b;
} Pair;

int compare_pairs(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    return (pa.b < pb.b) ? -1 : (pa.b > pb.b) ? 1 : 0;
}

int next_int(FILE *fp) {
    int n = 0;
    int c;
    while ((c = fgetc(fp)) != EOF && (c < '0' || c > '9'));
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = fgetc(fp);
    }
    return n;
}

void solve() {
    FILE *fp = stdin;
    int n = next_int(fp);
    int m = next_int(fp);
    int map[SIZE] = {0};

    for (int i = 0; i < m; i++) {
        int s = next_int(fp);
        int c = next_int(fp);
        if (map[s] != 0 && map[s] != c) {
            printf("-1\n");
            exit(0);
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[11];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != 0 && map[j + 1] != s[j] - '0') || (map[j + 1] == 0 && s[j] - '0' != 0)) {
                if (map[j + 1] == 0 && j == 0 && s[j] - '0' == 1) continue;
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            exit(0);
        }
    }

    printf("-1\n");
}

int main() {
    solve();
    return 0;
}
// End of Code
