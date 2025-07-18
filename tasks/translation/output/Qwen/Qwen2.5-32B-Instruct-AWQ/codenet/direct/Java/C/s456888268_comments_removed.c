#include <stdio.h>
#include <string.h>

#define mod 1000000007
#define dx {-1, 0, 1, 0}
#define dy {0, -1, 0, 1}
#define dx8 {-1, -1, -1, 0, 0, 1, 1, 1}
#define dy8 {-1, 0, 1, -1, 1, -1, 0, 1}
#define inf (int)1e9 / 2
#define linf (long long)1e18 / 3
#define dinf (double)1e308 / 3
#define eps 1e-10
#define pi 3.14159265358979323846

void reverse(int ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(long ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        long t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(double ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        double t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

void reverse(char ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        char t = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = t;
    }
}

char* getReverse(char* s) {
    int len = strlen(s);
    reverse((int*)s, len);
    return s;
}

void sbnl() {
    printf("\n");
}

int lowerBound(int a[], int x, int len) {
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

int upperBound(int a[], int x, int len) {
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

int rlowerBound(int a[], int x, int len) {
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

int rupperBound(int a[], int x, int len) {
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

int lowerBound(long a[], long x, int len) {
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

int upperBound(long a[], long x, int len) {
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

int rlowerBound(long a[], long x, int len) {
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

int rupperBound(long a[], long x, int len) {
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

int lowerBound(double a[], double x, int len) {
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

int upperBound(double a[], double x, int len) {
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

int rlowerBound(double a[], double x, int len) {
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

int rupperBound(double a[], double x, int len) {
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

int lowerBound(char a[], char x, int len) {
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

int upperBound(char a[], char x, int len) {
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

int rlowerBound(char a[], char x, int len) {
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

int rupperBound(char a[], char x, int len) {
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

int* concat(int x, int arr[], int len) {
    int* ret = (int*)malloc((len + 1) * sizeof(int));
    memcpy(ret + 1, arr, len * sizeof(int));
    ret[0] = x;
    return ret;
}

int* concat(int arr[], int x, int len) {
    int* ret = (int*)malloc((len + 1) * sizeof(int));
    memcpy(ret, arr, len * sizeof(int));
    ret[len] = x;
    return ret;
}

long* concat(long x, long arr[], int len) {
    long* ret = (long*)malloc((len + 1) * sizeof(long));
    memcpy(ret + 1, arr, len * sizeof(long));
    ret[0] = x;
    return ret;
}

long* concat(long arr[], long x, int len) {
    long* ret = (long*)malloc((len + 1) * sizeof(long));
    memcpy(ret, arr, len * sizeof(long));
    ret[len] = x;
    return ret;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int max(int x, int y, int z) {
    return max(max(x, y), z);
}

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

long max(long x, long y) {
    return x > y ? x : y;
}

long min(long x, long y) {
    return x < y ? x : y;
}

long max(long x, long y, long z) {
    return max(max(x, y), z);
}

long min(long x, long y, long z) {
    return min(min(x, y), z);
}

double max(double x, double y) {
    return x > y ? x : y;
}

double min(double x, double y) {
    return x < y ? x : y;
}

double max(double x, double y, double z) {
    return max(max(x, y), z);
}

double min(double x, double y, double z) {
    return min(min(x, y), z);
}

void sort(int ar[], int len) {
    qsort(ar, len, sizeof(int), (int(*)(const void*, const void*))strcmp);
}

void sort(long ar[], int len) {
    qsort(ar, len, sizeof(long), (int(*)(const void*, const void*))strcmp);
}

void sort(double ar[], int len) {
    qsort(ar, len, sizeof(double), (int(*)(const void*, const void*))strcmp);
}

void sort(char ar[], int len) {
    qsort(ar, len, sizeof(char), (int(*)(const void*, const void*))strcmp);
}

void rsort(int ar[], int len) {
    qsort(ar, len, sizeof(int), (int(*)(const void*, const void*))strcmp);
    reverse(ar, len);
}

void rsort(long ar[], int len) {
    qsort(ar, len, sizeof(long), (int(*)(const void*, const void*))strcmp);
    reverse(ar, len);
}

void rsort(double ar[], int len) {
    qsort(ar, len, sizeof(double), (int(*)(const void*, const void*))strcmp);
    reverse(ar, len);
}

void rsort(char ar[], int len) {
    qsort(ar, len, sizeof(char), (int(*)(const void*, const void*))strcmp);
    reverse(ar, len);
}

void fill(int arr[], int x, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill(long arr[], long x, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill(bool arr[], bool x, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill(double arr[], double x, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill(int arr[][100], int x, int len) {
    for (int i = 0; i < len; i++) {
        fill(arr[i], x, 100);
    }
}

void fill(long arr[][100], long x, int len) {
    for (int i = 0; i < len; i++) {
        fill(arr[i], x, 100);
    }
}

void fill(double arr[][100], double x, int len) {
    for (int i = 0; i < len; i++) {
        fill(arr[i], x, 100);
    }
}

void fill(bool arr[][100], bool x, int len) {
    for (int i = 0; i < len; i++) {
        fill(arr[i], x, 100);
    }
}

long plus(long x, long y) {
    long res = (x + y) % mod;
    return res < 0 ? res + mod : res;
}

long sub(long x, long y) {
    long res = (x - y) % mod;
    return res < 0 ? res + mod : res;
}

long mul(long x, long y) {
    long res = (x * y) % mod;
    return res < 0 ? res + mod : res;
}

long div(long x, long y) {
    long res = x * pow(y, mod - 2) % mod;
    return res < 0 ? res + mod : res;
}

long pow(long x, long y) {
    if (y < 0) return 0;
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * pow(x, y - 1)) % mod;
    long root = pow(x, y / 2);
    return root * root % mod;
}

void solve() {
    char tmp[100000];
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
