#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max = 0, cur = 0;

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_long(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int ni() {
    int val;
    scanf("%d", &val);
    return val;
}

long long nl() {
    long long val;
    scanf("%lld", &val);
    return val;
}

float nf() {
    float val;
    scanf("%f", &val);
    return val;
}

double nd() {
    double val;
    scanf("%lf", &val);
    return val;
}

char* ns() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    char* result = malloc(len + 1);
    strcpy(result, buffer);
    return result;
}

typedef struct {
    char* str;
    int pos;
} StringTokenizer;

StringTokenizer* nst(char* s) {
    StringTokenizer* st = malloc(sizeof(StringTokenizer));
    st->str = s;
    st->pos = 0;
    return st;
}

void ia(int a[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void la(long long a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = nl();
    }
}

void fa(float a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = nf();
    }
}

void da(double a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = nd();
    }
}

void sa(char** a, int size, int empty) {
    if (empty) {
        for (int i = 0; i < size; i++) {
            a[i] = "";
        }
    } else {
        for (int i = 0; i < size; i++) {
            a[i] = ns();
        }
    }
}

void ida(int a[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i * m + j] = ni();
        }
    }
}

void lda(long long a[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i * m + j] = nl();
        }
    }
}

void dda(double a[], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i * m + j] = nd();
        }
    }
}

int stoi(char* s) {
    return atoi(s);
}

double stod(char* s) {
    return atof(s);
}

long lmin(long a[], int size) {
    long min = LLONG_MAX;
    for (int i = 0; i < size; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int imin(int a[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

long lmax(long a[], int size) {
    long max = LLONG_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int imax(int a[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int ibs(int a[], int size, int toFind) {
    qsort(a, size, sizeof(int), compare_int);
    int min = 0, max = size - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
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

int lbs(long long a[], int size, long long toFind) {
    qsort(a, size, sizeof(long long), compare_long);
    int min = 0, max = size - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
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

int stb(char* s) {
    int sum = 0;
    int k = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        sum += digit * pow(2, k++);
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();
    int result = (a - 2*b) > 0 ? (a - 2*b) : 0;
    printf("%d\n", result);
}

int main() {
    solve();
    return 0;
}
// End of Code
