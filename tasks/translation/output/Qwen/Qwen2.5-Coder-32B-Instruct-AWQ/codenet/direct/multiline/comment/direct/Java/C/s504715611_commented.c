#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int *Parent;
} UnionFind;

void UnionFind_Init(UnionFind *uf, int n) {
    uf->Parent = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->Parent[i] = -1;
    }
}

int UnionFind_Root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = UnionFind_Root(uf, uf->Parent[A]);
}

int UnionFind_Size(UnionFind *uf, int A) {
    return -uf->Parent[UnionFind_Root(uf, A)];
}

bool UnionFind_Connect(UnionFind *uf, int A, int B) {
    A = UnionFind_Root(uf, A);
    B = UnionFind_Root(uf, B);
    if (A == B) return false;
    if (UnionFind_Size(uf, A) < UnionFind_Size(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return true;
}

void UnionFind_Free(UnionFind *uf) {
    free(uf->Parent);
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

int lower_bound(int a[], int n, int key) {
    int right = n;
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

int upper_bound(int a[], int n, int key) {
    int right = n;
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

bool isPrime(long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    double d = sqrt(n);
    for (int i = 3; i <= d; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int upper_division(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

long lupper_division(long a, long b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int *setArray(int a) {
    int *b = (int *)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }
    return b;
}

long *lsetArray(int a) {
    long *b = (long *)malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) {
        scanf("%ld", &b[i]);
    }
    return b;
}

char *reverse(char *str) {
    int a = strlen(str);
    char *ch = (char *)malloc(a + 1);
    strcpy(ch, str);
    for (int i = 0; i < upper_division(a, 2); i++) {
        char temp = ch[i];
        ch[i] = ch[a - i - 1];
        ch[a - i - 1] = temp;
    }
    return ch;
}

void printArray(int *que, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[length - 1]);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void doublesort(int **a, int n) {
    qsort(*a, n, sizeof(int), compare);
}

void ldoublesort(long **a, int n) {
    qsort(*a, n, sizeof(long), compare);
}

void warshall_floyd(int **v, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((*v)[i * n + j] > (*v)[i * n + k] + (*v)[k * n + j]) {
                    (*v)[i * n + j] = (*v)[i * n + k] + (*v)[k * n + j];
                }
            }
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    return 0;
}
// End of Code
