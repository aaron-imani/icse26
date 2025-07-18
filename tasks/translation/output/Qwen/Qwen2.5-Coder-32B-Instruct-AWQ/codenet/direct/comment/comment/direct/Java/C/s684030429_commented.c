#include <stdio.h>
#include <stdlib.h>

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

char* ns() {
    char* str = (char*)malloc(1000 * sizeof(char));
    scanf(" %[^\n]", str);
    return str;
}

void ia(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void la(long a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
}

void fa(float a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
}

void da(double a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
}

void sa(char* a[], int n, int empty) {
    if (empty) {
        for (int i = 0; i < n; i++) {
            a[i] = "";
        }
    } else {
        for (int i = 0; i < n; i++) {
            a[i] = ns();
        }
    }
}

void ida(int a[][1000], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void lda(long a[][1000], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%ld", &a[i][j]);
        }
    }
}

void dda(double a[][1000], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}

int stoi(const char* s) {
    return atoi(s);
}

double stod(const char* s) {
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

int ibs(int a[], int n, int toFind) {
    qsort(a, n, sizeof(int), (int (*)(const void*, const void*))strcmp);
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
    qsort(a, n, sizeof(long), (int (*)(const void*, const void*))strcmp);
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

int stb(const char* s) {
    int sum = 0;
    int k = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        sum += (s[i] - '0') * pow(2, k++);
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();

    printf("%d\n", (a - 2 * b) > 0 ? (a - 2 * b) : 0);
}

int main() {
    solve();
    return 0;
}
// End of Code
