#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int max = 0, cur = 0;

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
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    char* result = (char*)malloc(strlen(buffer)+1);
    strcpy(result, buffer);
    return result;
}

char** nst(char *s) {
    char* str = strdup(s);
    char* token;
    char** tokens = (char**)malloc(100 * sizeof(char*));
    int count = 0;
    token = strtok(str, " ");
    while (token != NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, " ");
    }
    tokens[count] = NULL;
    return tokens;
}

void ia(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = ni();
    }
}

void la(long a[], int size) {
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

void sa(char *a[], int size, int empty) {
    for (int i = 0; i < size; i++) {
        if (empty) {
            a[i] = (char*)malloc(1);
            a[i][0] = '\0';
        } else {
            a[i] = ns();
        }
    }
}

void ida(int a[][m], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = ni();
        }
    }
}

void lda(long a[][m], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = nl();
        }
    }
}

void dda(double a[][m], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = nd();
        }
    }
}

int imin(int a[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

long lmin(long a[], int size) {
    long min = LONG_MAX;
    for (int i = 0; i < size; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int imax(int a[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

long lmax(long a[], int size) {
    long max = LONG_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int ibs(int a[], int size, int toFind) {
    qsort(a, size, sizeof(int), compare_int);
    int min = 0, max = size - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = 1;
        else if (toFind > a[mid]) min = mid + 1;
        else max = mid - 1;
    }
    return found;
}

int compare_long(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int lbs(long a[], int size, long toFind) {
    qsort(a, size, sizeof(long), compare_long);
    int min = 0, max = size - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = 1;
        else if (toFind > a[mid]) min = mid + 1;
        else max = mid - 1;
    }
    return found;
}

int stb(char *s) {
    int sum = 0;
    int k = 0;
    int len = strlen(s);
    for (int i = len -1; i >= 0; i--) {
        int digit = s[i] - '0';
        sum += digit * (int)pow(2, k++);
    }
    return sum;
}

void solve() {
    int a = ni();
    int b = ni();
    printf("%d\n", (a - 2*b > 0) ? (a - 2*b) : 0);
}

int main() {
    solve();
    return 0;
}
// End of Code
