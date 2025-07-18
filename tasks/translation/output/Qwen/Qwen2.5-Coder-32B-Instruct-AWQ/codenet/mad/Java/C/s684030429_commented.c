#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ni() {
    int a;
    scanf("%d", &a);
    return a;
}

long nl() {
    long a;
    scanf("%ld", &a);
    return a;
}

float nf() {
    float a;
    scanf("%f", &a);
    return a;
}

double nd() {
    double a;
    scanf("%lf", &a);
    return a;
}

void ia(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = ni();
    }
}

void la(long a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nl();
    }
}

void fa(float a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nf();
    }
}

void da(double a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = nd();
    }
}

int stoi(const char *s) {
    return atoi(s);
}

double stod(const char *s) {
    return atof(s);
}

long lmin(long a[], int n) {
    long min = LONG_MAX;
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

int imin(int a[], int n) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

long lmax(long a[], int n) {
    long max = LONG_MIN;
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int imax(int a[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_long(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int ibs(int a[], int n, int toFind) {
    qsort(a, n, sizeof(int), compare_int);
    int min = 0;
    int max = n - 1;
    int found = 0;

    while (min <= max && !found) {
        int mid = min + (max - min) / 2;
        if (a[mid] == toFind) {
            found = 1;
        } else if (toFind > a[mid]) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return found;
}

int lbs(long a[], int n, long toFind) {
    qsort(a, n, sizeof(long), compare_long);
    int min = 0;
    int max = n - 1;
    int found = 0;

    while (min <= max && !found) {
        int mid = min + (max - min) / 2;
        if (a[mid] == toFind) {
            found = 1;
        } else if (toFind > a[mid]) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return found;
}

int stb(const char *s) {
    int sum = 0;
    int k = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        sum += (s[i] - '0') * (1 << k++);
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();

    printf("%d\n", max(0, a - 2 * b));
}

int main() {
    solve();
    return 0;
}
// End of Code
