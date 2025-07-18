#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define SIZE 1000000

long long fac[SIZE];
long long inv[SIZE];
long long finv[SIZE];

typedef struct {
    int key;
    int value;
} MapEntry;

typedef struct {
    MapEntry *entries;
    int size;
} HashMap;

HashMap *createHashMap(int size) {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->entries = (MapEntry *)malloc(size * sizeof(MapEntry));
    map->size = 0;
    return map;
}

int get(MapEntry *entries, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (entries[i].key == key) {
            return entries[i].value;
        }
    }
    return -1;
}

void put(MapEntry *entries, int *size, int key, int value) {
    entries[*size].key = key;
    entries[*size].value = value;
    (*size)++;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    HashMap *map = createHashMap(m);
    map->size = 0;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (get(map->entries, map->size, s) != -1 && get(map->entries, map->size, s) != c) {
            printf("-1\n");
            exit(0);
        }
        put(map->entries, &map->size, s, c);
    }

    for (int i = 0; i < 1000; i++) {
        char s[4];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((get(map->entries, map->size, j + 1) != -1 && get(map->entries, map->size, j + 1) != s[j] - '0') || (get(map->entries, map->size, j + 1) == -1 && s[j] - '0' != 0)) {
                if (get(map->entries, map->size, j + 1) == -1 && j == 0 && s[j] - '0' == 1) {
                    continue;
                }
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

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long inv(long long a) {
    return pow(a, MOD - 2);
}

long long pow(long long a, long long r) {
    long long sum = 1;
    while (r > 0) {
        if ((r & 1) == 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return sum;
}

long long modFact(long long n) {
    if (n == 0) return 1;
    return n * modFact(n - 1) % MOD;
}

long long fact(long long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void initCOMB() {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long modComb(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

long long comb(long long n, long long r) {
    long long num = 1;
    for (long long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int isPrime(long long a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main() {
    solve();
    return 0;
}
// End of Code
