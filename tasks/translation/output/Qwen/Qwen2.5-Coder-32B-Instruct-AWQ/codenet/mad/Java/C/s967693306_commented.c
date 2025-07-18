#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (LONG_MAX / 2)
#define MOD 1000000007
#define SIZE 1000000

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair *pairs;
    int size;
    int capacity;
} HashMap;

HashMap* createHashMap() {
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));
    map->size = 0;
    map->capacity = 100;
    map->pairs = (Pair*)malloc(map->capacity * sizeof(Pair));
    return map;
}

void put(HashMap *map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->pairs[i].key == key) {
            map->pairs[i].value = value;
            return;
        }
    }
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->pairs = (Pair*)realloc(map->pairs, map->capacity * sizeof(Pair));
    }
    map->pairs[map->size].key = key;
    map->pairs[map->size].value = value;
    map->size++;
}

int get(HashMap *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->pairs[i].key == key) {
            return map->pairs[i].value;
        }
    }
    return -1;
}

void freeHashMap(HashMap *map) {
    free(map->pairs);
    free(map);
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
        if (r & 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return sum;
}

long inv(long a) {
    return pow(a, MOD - 2);
}

long modFact(long n) {
    if (n == 0) return 1;
    return n * modFact(n - 1) % MOD;
}

long fact(long n) {
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

long modComb(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
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
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int find(long dest, long *a, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
}

int compareLong(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int nextPermutation(long *a, int length) {
    for (int i = length - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int swapIndex = find(a[i - 1], a, i, length - 1);
            long temp = a[swapIndex];
            a[swapIndex] = a[i - 1];
            a[i - 1] = temp;
            qsort(a + i, length - i, sizeof(long), compareLong);
            return 1;
        }
    }
    return 0;
}

void elimination(int **a, int *b, int n) {
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = -a[i][k] / (double)a[k][k];
            for (int j = k + 1; j < n; j++) {
                a[i][j] += f * a[k][j];
            }
            b[i] += f * b[k];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                b[i] -= a[i][j] * b[j];
            }
            b[i] = b[i] / a[i][i];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    HashMap *map = createHashMap();

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        int existingValue = get(map, s);
        if (existingValue != -1 && existingValue != c) {
            printf("-1\n");
            freeHashMap(map);
            return 0;
        }
        put(map, s, c);
    }

    for (int i = 0; i < 1000; i++) {
        char s[11];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int mapValue = get(map, j + 1);
            if ((mapValue != -1 && mapValue != s[j] - '0') || (mapValue == -1 && s[j] - '0' != 0)) {
                if (mapValue == -1 && j == 0 && s[j] - '0' == 1) continue;
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            freeHashMap(map);
            return 0;
        }
    }

    printf("-1\n");
    freeHashMap(map);
    return 0;
}

// End of Code
