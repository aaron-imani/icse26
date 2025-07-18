#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max = 0;
int cur = 0;

int ni() {
    int val;
    scanf("%d", &val);
    return val;
}

long nl() {
    long val;
    scanf("%ld", &val);
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
    char* line = malloc(1024 * sizeof(char));
    if (!line) return NULL;
    fgets(line, 1024, stdin);
    size_t len = strlen(line);
    if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
    return line;
}

void ia(int a[], int len) {
    for (int i = 0; i < len; i++) a[i] = ni();
}

void la(long a[], int len) {
    for (int i = 0; i < len; i++) a[i] = nl();
}

void fa(float a[], int len) {
    for (int i = 0; i < len; i++) a[i] = nf();
}

void da(double a[], int len) {
    for (int i = 0; i < len; i++) a[i] = nd();
}

void sa(char* a[], int len, int empty) {
    if (empty) {
        for (int i = 0; i < len; i++) {
            a[i] = malloc(1);
            a[i][0] = '\0';
        }
    } else {
        for (int i = 0; i < len; i++) a[i] = ns();
    }
}

void ida(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = ni();
}

void lda(long a[][100], int n, int m) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = nl();
}

void dda(double a[][100], int n, int m) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = nd();
}

int stoi(char* s) { return atoi(s); }
double stod(char* s) { return atof(s); }

long lmin(long a[], int len) {
    long min = LONG_MAX;
    for (int i = 0; i < len; i++) if (a[i] < min) min = a[i];
    return min;
}

int imin(int a[], int len) {
    int min = INT_MAX;
    for (int i = 0; i < len; i++) if (a[i] < min) min = a[i];
    return min;
}

long lmax(long a[], int len) {
    long max = LONG_MIN;
    for (int i = 0; i < len; i++) if (a[i] > max) max = a[i];
    return max;
}

int imax(int a[], int len) {
    int max = INT_MIN;
    for (int i = 0; i < len; i++) if (a[i] > max) max = a[i];
    return max;
}

int compare(const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int ibs(int a[], int len, int toFind) {
    qsort(a, len, sizeof(int), compare);
    int min = 0, max = len-1, found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = 1;
        else if (toFind > a[mid]) min = mid +1;
        else max = mid-1;
    }
    return found;
}

int compareLong(const void *a, const void *b) { return (*(long*)a - *(long*)b); }

int lbs(long a[], int len, long toFind) {
    qsort(a, len, sizeof(long), compareLong);
    int min =0, max = len-1, found=0;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found =1;
        else if (toFind > a[mid]) min = mid+1;
        else max = mid-1;
    }
    return found;
}

int stb(char* s) {
    int sum=0,k=0,l=strlen(s);
    for(int i=l-1; i>=0; i--) {
        int c = s[i] - '0';
        sum += c * pow(2,k++);
    }
    return sum;
}

void solve() {
    int a = ni(), b = ni();
    printf("%d\n", (a>2*b ? a-2*b :0));
}

int main() {
    solve();
    return 0;
}
// End of Code
