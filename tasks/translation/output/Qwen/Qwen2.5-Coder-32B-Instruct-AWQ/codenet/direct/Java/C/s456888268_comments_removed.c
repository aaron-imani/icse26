#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXN 100005

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int inf = 1000000000 / 2;
long long linf = 1000000000000000000LL / 3;
double dinf = 1e10 / 3;
double eps = 1e-10;
double pi = 3.14159265358979323846;

void reverse_int(int ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_long(long long ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        long long t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_double(double ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        double t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_char(char ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        char t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

char* getReverse(char s[]) {
    int len = strlen(s);
    reverse_char(s, len);
    return s;
}

void solve() {
    char tmp[MAXN];
    scanf("%s", tmp);
    int n = strlen(tmp);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
