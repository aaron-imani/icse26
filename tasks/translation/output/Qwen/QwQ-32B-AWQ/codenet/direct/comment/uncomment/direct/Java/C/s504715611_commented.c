#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int *parent;
    int size;
} UnionFind;

UnionFind* create_union_find(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->size = n;
    uf->parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->parent[i] = -1;
    return uf;
}

int root(UnionFind *uf, int A) {
    if (uf->parent[A] < 0) return A;
    return uf->parent[A] = root(uf, uf->parent[A]);
}

int size_of(UnionFind *uf, int A) {
    return -uf->parent[root(uf, A)];
}

int connect(UnionFind *uf, int A, int B) {
    int rootA = root(uf, A);
    int rootB = root(uf, B);
    if (rootA == rootB) return 0;
    if (size_of(uf, A) < size_of(uf, B)) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }
    uf->parent[rootA] += uf->parent[rootB];
    uf->parent[rootB] = rootA;
    return 1;
}

const long mod = 1000000007;
double eps = 1.0e-14;
int big = INT_MAX;
double PI = 3.14159265358979323846262338327950288;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

long modlcm(long a, long b) {
    long g = gcd(a, b);
    return a * b * modint(g, mod);
}

long modint(long a, long m) {
    long b = m, u = 1, v = 0;
    while (b != 0) {
        long t = a / b;
        a -= t * b;
        long x = a;
        a = b;
        b = x;
        u -= t * v;
        x = u;
        u = v;
        v = x;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

long lmax(long a, long b) { return a > b ? a : b; }

long lmin(long a, long b) { return a < b ? a : b; }

long factorial(int i) {
    if (i == 1) return 1;
    return i * factorial(i - 1);
}

long modpow(long x, long n, long mo) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mo;
        x = (x * x) % mo;
        n >>= 1;
    }
    return res;
}

char* reverse_string(const char *str) {
    int len = strlen(str);
    char *result = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}

int upper_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] <= key) left = mid;
        else right = mid;
    }
    return left;
}

int lower_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int is_prime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long d = sqrt(n);
    for (long i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int upper_division(int a, int b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

int* set_array(int a) {
    int *b = malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }
    return b;
}

long* lset_array(int a) {
    long *b = malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) {
        scanf("%ld", &b[i]);
    }
    return b;
}

char* revch(char ch[]) {
    int len = strlen(ch);
    char *ret = malloc(len + 1);
    for (int i = 0, j = len - 1; j >= 0; i++, j--) {
        ret[i] = ch[j];
    }
    ret[len] = '\0';
    return ret;
}

int* revint(int ch[], int len) {
    int *ret = malloc(len * sizeof(int));
    for (int i = 0, j = len - 1; j >= 0; i++, j--) {
        ret[i] = ch[j];
    }
    return ret;
}

int main() {
    char str[10];
    scanf("%9s", str);
    if (str[2] == str[3] && str[4] == str[5]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// End of Code
