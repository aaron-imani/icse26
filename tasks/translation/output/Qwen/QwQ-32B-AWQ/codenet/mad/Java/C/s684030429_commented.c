#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void solve() {
    int a = ni();
    int b = ni();
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
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return NULL;
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
    return strdup(buffer);
}

void ia(int a[], int length) {
    for (int i = 0; i < length; i++)
        scanf("%d", &a[i]);
}

void la(long a[], int length) {
    for (int i = 0; i < length; i++)
        scanf("%ld", &a[i]);
}

void fa(float a[], int length) {
    for (int i = 0; i < length; i++)
        scanf("%f", &a[i]);
}

void da(double a[], int length) {
    for (int i = 0; i < length; i++)
        scanf("%lf", &a[i]);
}

void sa(char *a[], int length, int empty) {
    if (empty) {
        for (int i = 0; i < length; i++)
            a[i] = "";
    } else {
        for (int i = 0; i < length; i++)
            a[i] = ns();
    }
}

int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int ibs(int a[], int length, int toFind) {
    int sorted[length];
    for (int i = 0; i < length; i++) sorted[i] = a[i];
    qsort(sorted, length, sizeof(int), compareInts);
    int min = 0, max = length - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min) / 2;
        if (sorted[mid] == toFind)
            found = 1;
        else if (toFind > sorted[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }
    return found;
}

int compareLongs(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int lbs(long a[], int length, long toFind) {
    long sorted[length];
    for (int i = 0; i < length; i++) sorted[i] = a[i];
    qsort(sorted, length, sizeof(long), compareLongs);
    int min = 0, max = length - 1;
    int found = 0;
    while (min <= max && !found) {
        int mid = min + (max - min) / 2;
        if (sorted[mid] == toFind)
            found = 1;
        else if (toFind > sorted[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }
    return found;
}

int stb(char *s) {
    int sum = 0, k = 0;
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        sum += digit * (1 << k++);
    }
    return sum;
}

int main() {
    solve();
    return 0;
}

// End of Code
