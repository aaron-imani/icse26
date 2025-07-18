#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ni() {
    int x;
    scanf("%d", &x);
    return x;
}

long nl() {
    long x;
    scanf("%ld", &x);
    return x;
}

float nf() {
    float x;
    scanf("%f", &x);
    return x;
}

double nd() {
    double x;
    scanf("%lf", &x);
    return x;
}

char* ns() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    char *result = malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(result, buffer);
    return result;
}

void ia(int *a, int length) {
    for (int i = 0; i < length; i++) {
        a[i] = ni();
    }
}

void la(long *a, int length) {
    for (int i = 0; i < length; i++) {
        a[i] = nl();
    }
}

void fa(float *a, int length) {
    for (int i = 0; i < length; i++) {
        a[i] = nf();
    }
}

void da(double *a, int length) {
    for (int i = 0; i < length; i++) {
        a[i] = nd();
    }
}

void sa(char **a, int length, int empty) {
    if (empty) {
        for (int i = 0; i < length; i++) {
            a[i] = "";
        }
    } else {
        for (int i = 0; i < length; i++) {
            a[i] = ns();
        }
    }
}

void ida(int *a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i*m + j] = ni();
        }
    }
}

void lda(long *a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i*m + j] = nl();
        }
    }
}

void dda(double *a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i*m + j] = nd();
        }
    }
}

int stoi(char *s) {
    return atoi(s);
}

double stod(char *s) {
    return atof(s);
}

long lmin(long a[], int length) {
    long min = LONG_MAX;
    for (int i = 0; i < length; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int imin(int a[], int length) {
    int min = INT_MAX;
    for (int i = 0; i < length; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

long lmax(long a[], int length) {
    long max = LONG_MIN;
    for (int i = 0; i < length; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int imax(int a[], int length) {
    int max = INT_MIN;
    for (int i = 0; i < length; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int compareInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareLong(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int ibs(int a[], int length, int toFind) {
    qsort(a, length, sizeof(int), compareInt);
    int min = 0;
    int max = length -1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) {
            found = 1;
        } else if (toFind > a[mid]) {
            min = mid +1;
        } else {
            max = mid -1;
        }
    }
    return found;
}

int lbs(long a[], int length, long toFind) {
    qsort(a, length, sizeof(long), compareLong);
    int min = 0;
    int max = length -1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) {
            found = 1;
        } else if (toFind > a[mid]) {
            min = mid +1;
        } else {
            max = mid -1;
        }
    }
    return found;
}

int stb(char *s) {
    int sum =0;
    int len = strlen(s);
    for (int i = len-1; i >=0; i--) {
        int digit = s[i] - '0';
        sum += digit * pow(2, len-1 -i);
    }
    return sum;
}

typedef struct {
    char *string;
} StringTokenizer;

StringTokenizer *nst(char *s) {
    StringTokenizer *tok = malloc(sizeof(StringTokenizer));
    tok->string = strdup(s);
    return tok;
}

void solve() {
    int a = ni();
    int b = ni();
    int result = (a - 2*b > 0) ? a - 2*b : 0;
    printf("%d\n", result);
}

int main() {
    solve();
    return 0;
}
// End of Code
