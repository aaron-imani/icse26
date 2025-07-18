// C code with all utility functions and constants
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MOD 1000000007
#define MAX_INT (1 << 30)
#define MAX_LONG (1LL << 61)
#define EPS 1e-10
#define PI 3.14159265358979323846

void solve() {
    char tmp[1024];
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

void reverse_int(int *ar, int len) {
    for (int i = 0; i < len / 2; i++) {
        int t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_long(long *ar, int len) {
    for (int i = 0; i < len / 2; i++) {
        long t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_double(double *ar, int len) {
    for (int i = 0; i < len / 2; i++) {
        double t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse_char(char *ar, int len) {
    for (int i = 0; i < len / 2; i++) {
        char t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

int lowerBound_int(int *a, int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound_int(int *a, int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound_int(int *a, int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound_int(int *a, int len, int x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound_long(long *a, int len, long x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound_long(long *a, int len, long x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound_long(long *a, int len, long x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound_long(long *a, int len, long x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound_double(double *a, int len, double x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound_double(double *a, int len, double x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound_double(double *a, int len, double x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound_double(double *a, int len, double x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int lowerBound_char(char *a, int len, char x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int upperBound_char(char *a, int len, char x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] <= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rlowerBound_char(char *a, int len, char x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] > x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int rupperBound_char(char *a, int len, char x) {
    int l = -1, r = len;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] >= x) {
            l = c;
        } else {
            r = c;
        }
    }
    return r;
}

int max_int(int x, int y) {
    return x > y ? x : y;
}

int min_int(int x, int y) {
    return x < y ? x : y;
}

int max_int3(int x, int y, int z) {
    return max_int(max_int(x, y), z);
}

int min_int3(int x, int y, int z) {
    return min_int(min_int(x, y), z);
}

long max_long(long x, long y) {
    return x > y ? x : y;
}

long min_long(long x, long y) {
    return x < y ? x : y;
}

long max_long3(long x, long y, long z) {
    return max_long(max_long(x, y), z);
}

long min_long3(long x, long y, long z) {
    return min_long(min_long(x, y), z);
}

double max_double(double x, double y) {
    return x > y ? x : y;
}

double min_double(double x, double y) {
    return x < y ? x : y;
}

double max_double3(double x, double y, double z) {
    return max_double(max_double(x, y), z);
}

double min_double3(double x, double y, double z) {
    return min_double(min_double(x, y), z);
}

void sort_int(int *ar, int len) {
    qsort(ar, len, sizeof(int), (int (*)(const void *, const void *))compare_int);
}

void sort_long(long *ar, int len) {
    qsort(ar, len, sizeof(long), (int (*)(const void *, const void *))compare_long);
}

void sort_double(double *ar, int len) {
    qsort(ar, len, sizeof(double), (int (*)(const void *, const void *))compare_double);
}

void sort_char(char *ar, int len) {
    qsort(ar, len, sizeof(char), (int (*)(const void *, const void *))compare_char);
}

void rsort_int(int *ar, int len) {
    sort_int(ar, len);
    reverse_int(ar, len);
}

void rsort_long(long *ar, int len) {
    sort_long(ar, len);
    reverse_long(ar, len);
}

void rsort_double(double *ar, int len) {
    sort_double(ar, len);
    reverse_double(ar, len);
}

void rsort_char(char *ar, int len) {
    sort_char(ar, len);
    reverse_char(ar, len);
}

void fill_int(int *arr, int len, int x) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill_long(long *arr, int len, long x) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill_double(double *arr, int len, double x) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill_char(char *arr, int len, char x) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill_int2(int **arr, int rows, int cols, int x) {
    for (int i = 0; i < rows; i++) {
        fill_int(arr[i], cols, x);
    }
}

void fill_long2(long **arr, int rows, int cols, long x) {
    for (int i = 0; i < rows; i++) {
        fill_long(arr[i], cols, x);
    }
}

void fill_double2(double **arr, int rows, int cols, double x) {
    for (int i = 0; i < rows; i++) {
        fill_double(arr[i], cols, x);
    }
}

void fill_char2(char **arr, int rows, int cols, char x) {
    for (int i = 0; i < rows; i++) {
        fill_char(arr[i], cols, x);
    }
}

long plus(long x, long y) {
    long res = (x + y) % MOD;
    return res < 0 ? res + MOD : res;
}

long sub(long x, long y) {
    long res = (x - y) % MOD;
    return res < 0 ? res + MOD : res;
}

long mul(long x, long y) {
    long res = (x * y) % MOD;
    return res < 0 ? res + MOD : res;
}

long div(long x, long y) {
    long res = x * pow(y, MOD - 2) % MOD;
    return res < 0 ? res + MOD : res;
}

long pow(long x, long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % MOD;
    long root = pow(x, y / 2);
    return root * root % MOD;
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_long(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int compare_double(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    solve();
    return 0;
}
// End of Code
