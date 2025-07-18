#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* next() {
    static char buffer[100];
    scanf("%99s", buffer);
    return buffer;
}

int nextInt() {
    int val;
    scanf("%d", &val);
    return val;
}

long nextLong() {
    long val;
    scanf("%ld", &val);
    return val;
}

double nextDouble() {
    double val;
    scanf("%lf", &val);
    return val;
}

char** splitString(char* s) {
    int len = strlen(s);
    char** arr = malloc((len + 1) * sizeof(char*));
    for (int i = 0; i < len; i++) {
        arr[i] = malloc(2);
        arr[i][0] = s[i];
        arr[i][1] = '\0';
    }
    arr[len] = NULL;
    return arr;
}

char* splitChar(char* s) {
    return strdup(s);
}

int charToInt(char c) {
    return c - '0';
}

int maxInt(int a[], int lng) {
    int max = a[0];
    for (int i = 1; i < lng; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int minInt(int a[], int lng) {
    int min = a[0];
    for (int i = 1; i < lng; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

long maxLong(long a[], int lng) {
    long max = a[0];
    for (int i = 1; i < lng; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

long minLong(long a[], int lng) {
    long min = a[0];
    for (int i = 1; i < lng; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int main() {
    long n = nextLong();
    long a = nextLong();
    long b = nextLong();

    long sa = labs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = ( (n - a) < (a - 1) ) ? (n - a) : (a - 1);
        long BBB = ( (n - b) < (b - 1) ) ? (n - b) : (b - 1);

        ans = (AAA < BBB) ? AAA : BBB;

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    printf("%ld\n", ans);

    return 0;
}
// End of Code
