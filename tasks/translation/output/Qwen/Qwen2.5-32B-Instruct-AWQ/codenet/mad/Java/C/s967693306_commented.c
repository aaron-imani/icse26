#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define SIZE 1000000

#define INF (LONG_MAX / 2)

typedef struct {
    int key;
    int value;
} MapEntry;

typedef struct {
    MapEntry *entries;
    int size;
} Map;

Map *createMap(int size) {
    Map *map = (Map *)malloc(sizeof(Map));
    map->entries = (MapEntry *)malloc(size * sizeof(MapEntry));
    map->size = 0;
    return map;
}

int get(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return -1;
}

void put(Map *map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long inv(long a) {
    return pow(a, MOD - 2);
}

long pow(long a, long r) {
    long sum = 1;
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

long modFact(long n) {
    if (n == 0) {
        return 1;
    }
    return n * modFact(n - 1) % MOD;
}

long fact(long n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

void initCOMB(long *fac, long *inv, long *finv) {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long modComb(int n, int r, long *fac, long *finv) {
    if (n < r || n < 0 || r < 0) {
        return 0;
    }
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

long comb(long n, long r) {
    long num = 1;
    for (long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int isPrime(long a) {
    if (a <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    Map *map = createMap(m);

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (get(map, s) != -1 && get(map, s) != c) {
            printf("-1\n");
            exit(0);
        }
        put(map, s, c);
    }

    for (int i = 0; i < 1000; i++) {
        char s[5];
        sprintf(s, "%d", i);
        int flag = 1;
        if (strlen(s) < n) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if ((get(map, j + 1) != -1 && get(map, j + 1) != s[j] - '0') || (get(map, j + 1) == -1 && s[j] - '0' != 0)) {
                if (get(map, j + 1) == -1 && j == 0 && s[j] - '0' == 1) {
                    continue;
                }
                flag = 0;
                break;
            }
        }
        if (flag && strlen(s) == n) {
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
