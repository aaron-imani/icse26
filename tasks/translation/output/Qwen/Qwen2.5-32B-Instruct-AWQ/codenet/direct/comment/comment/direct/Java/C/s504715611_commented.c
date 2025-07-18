#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *parent;
} UnionFind;

UnionFind* union_find_create(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = -1;
    }
    return uf;
}

int union_find_root(UnionFind *uf, int A) {
    if (uf->parent[A] < 0) return A;
    return uf->parent[A] = union_find_root(uf, uf->parent[A]);
}

int union_find_size(UnionFind *uf, int A) {
    return -uf->parent[union_find_root(uf, A)];
}

int union_find_connect(UnionFind *uf, int A, int B) {
    A = union_find_root(uf, A);
    B = union_find_root(uf, B);
    if (A == B) return 0;
    if (union_find_size(uf, A) < union_find_size(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->parent[A] += uf->parent[B];
    uf->parent[B] = A;
    return 1;
}

void fast_scan_init() {}

char* fast_scan_next() {
    static char buffer[1024];
    scanf("%s", buffer);
    return strdup(buffer);
}

int fast_scan_next_int() {
    int value;
    scanf("%d", &value);
    return value;
}

double fast_scan_next_double() {
    double value;
    scanf("%lf", &value);
    return value;
}

char fast_scan_next_char() {
    char value;
    scanf(" %c", &value);
    return value;
}

int main() {
    fast_scan_init();
    char *str = fast_scan_next();
    printf("%s\n", (str[2] == str[3] && str[4] == str[5]) ? "Yes" : "No");
    free(str);
    return 0;
}

int lower_bound(int a[], int key, int length) {
    int right = length;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(int a[], int key, int length) {
    int right = length;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int is_prime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long d = sqrt(n);
    for (int i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

int* set_array(int a) {
    int *b = malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        b[i] = fast_scan_next_int();
    }
    return b;
}

long* lset_array(int a) {
    long *b = malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) {
        b[i] = fast_scan_next_long();
    }
    return b;
}

char* reverse_string(const char *str) {
    int len = strlen(str);
    char *ch = malloc(len * sizeof(char));
    for (int i = 0; i < upper_division(len, 2); i++) {
        ch[i] = str[len - i - 1];
        ch[len - 1 - i] = str[i];
    }
    return ch;
}

void print_array(int *que, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[length - 1]);
}

int** doublesort(int **a, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (a[i][0] > a[j][0]) {
                int *temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

long** ldoublesort(long **a, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (a[i][0] > a[j][0]) {
                long *temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            sum = sum * x % mo;
        }
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

char* revch(char *ch, int length) {
    char *ret = malloc(length * sizeof(char));
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

int* revint(int *ch, int length) {
    int *ret = malloc(length * sizeof(int));
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

void warshall_floyd(int **v, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = v[i][j] < v[i][k] + v[k][j] ? v[i][j] : v[i][k] + v[k][j];
            }
        }
    }
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

// End of Code
