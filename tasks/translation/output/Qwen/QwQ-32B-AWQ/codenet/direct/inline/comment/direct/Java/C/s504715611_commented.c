#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *Parent;
    int size;
} UnionFind;

UnionFind* create_unionfind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->Parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    uf->size = n;
    return uf;
}

int find_root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = find_root(uf, uf->Parent[A]);
}

int get_size(UnionFind *uf, int A) {
    int rootA = find_root(uf, A);
    return -uf->Parent[rootA];
}

void connect_nodes(UnionFind *uf, int A, int B) {
    int rootA = find_root(uf, A);
    int rootB = find_root(uf, B);
    if (rootA == rootB) return;
    if (get_size(uf, A) < get_size(uf, B)) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }
    uf->Parent[rootA] += uf->Parent[rootB];
    uf->Parent[rootB] = rootA;
}

int lower_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int upper_bound(int a[], int n, int key) {
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) left = mid;
        else right = mid;
    }
    return left;
}

int isPrime(long n) {
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

int* setArray(int a) {
    int *arr = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) scanf("%d", &arr[i]);
    return arr;
}

long* lsetArray(int a) {
    long *arr = (long*)malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) scanf("%ld", &arr[i]);
    return arr;
}

char* reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

void printArray(int *que, int n) {
    for (int i = 0; i < n-1; i++) printf("%d ", que[i]);
    printf("%d\n", que[n-1]);
}

void warshall_floyd(int **v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = k; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][k] + v[k][j] < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
}

long modint(long a, long m) {
    long b = m, u = 1, v = 0;
    while (b != 0) {
        long t = a / b;
        a -= t * b;
        long temp = a;
        a = b;
        b = temp;
        u -= t * v;
        temp = u;
        u = v;
        v = temp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long modpow(long x, long n, long mo) {
    long res = 1;
    x %= mo;
    while (n > 0) {
        if (n % 2 == 1) res = res * x % mo;
        x = x * x % mo;
        n /= 2;
    }
    return res;
}

char* revch(char *ch) {
    int len = strlen(ch);
    for (int i = 0; i < len/2; i++) {
        char temp = ch[i];
        ch[i] = ch[len - i -1];
        ch[len - i -1] = temp;
    }
    return ch;
}

int* revint(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i -1];
        arr[n - i -1] = temp;
    }
    return arr;
}

int main() {
    char str[10];
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] = '\0';
    if (strlen(str) < 6) {
        printf("No\n");
    } else {
        if (str[2] == str[3] && str[4] == str[5]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
// End of Code
