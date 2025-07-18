#include <stdio.h>
#include <stdlib.h>

int max = 0, cur = 0;

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (a - 2 * b > 0) ? a - 2 * b : 0);
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

char* ns() {
    char* str = malloc(100 * sizeof(char));
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    return str;
}

void ia(int a[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void la(long a[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%ld", &a[i]);
    }
}

void fa(float a[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%f", &a[i]);
    }
}

void da(double a[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%lf", &a[i]);
    }
}

void sa(char* a[], int size, int empty) {
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

void ida(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void lda(long a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%ld", &a[i][j]);
        }
    }
}

void dda(double a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
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
    long min = LONG_MAX;
    for (int i = 0; i < size; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

int imin(int a[], int size) {
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

long lmax(long a[], int size) {
    long max = LONG_MIN;
    for (int i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int imax(int a[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int ibs(int a[], int size, int toFind) {
    qsort(a, size, sizeof(int), compareInt);
    int min = 0;
    int max = size - 1;
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

int lbs(long a[], int size, long toFind) {
    qsort(a, size, sizeof(long), compareLong);
    int min = 0;
    int max = size - 1;
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

int stb(char* s) {
    int sum = 0;
    int k = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        sum += (s[i] - '0') * pow(2, k++);
    }
    return sum;
}

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareLong(const void* a, const void* b) {
    return (*(long*)a - *(long*)b);
}

int main() {
    solve();
    return 0;
}
// End of Code
