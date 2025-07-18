#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

void solve() {
    char tmp[100005];
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

void fill(double arr[], double x, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = x;
    }
}

void fill(char arr[], char x, int len) {
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

void fill(char arr[][100], char x, int len) {
    for (int i = 0; i < len; i++) {
        fill(arr[i], x, 100);
    }
}

int main() {
    solve();
    return 0;
}

// End of Code
