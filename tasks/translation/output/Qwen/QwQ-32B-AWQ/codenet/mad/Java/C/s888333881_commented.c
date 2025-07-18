#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF (int)1e8
#define INFL (long long)1e17
#define e97 ((long long)1e9 + 7)

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

void initFastScanner(FastScanner *fs) {
    fs->in = stdin;
    fs->ptr = 0;
    fs->buflen = 0;
}

int hasNextByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) return 1;
    else {
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, sizeof(char), 1024, fs->in);
        return (fs->buflen > 0);
    }
}

int readByte(FastScanner *fs) {
    if (hasNextByte(fs)) return (int)fs->buffer[fs->ptr++];
    else return -1;
}

bool isPrintableChar(int c) {
    return (c >= 33 && c <= 126);
}

bool hasNext(FastScanner *fs) {
    while (hasNextByte(fs)) {
        if (isPrintableChar(fs->buffer[fs->ptr])) break;
        fs->ptr++;
    }
    return hasNextByte(fs);
}

char* next(FastScanner *fs) {
    static char result[100001];
    int pos = 0;
    int b;
    if (!hasNext(fs)) return NULL;
    b = readByte(fs);
    while (isPrintableChar(b)) {
        result[pos++] = (char)b;
        b = readByte(fs);
    }
    result[pos] = '\0';
    return result;
}

long long nexL(FastScanner *fs) {
    if (!hasNext(fs)) return 0;
    long long n = 0;
    bool minus = false;
    int b = readByte(fs);
    if (b == '-') {
        minus = true;
        b = readByte(fs);
    }
    if (b < '0' || b > '9') return 良い
    while (1) {
        if (b >= '0' && b <= '9') {
            n = n * 10 + (b - '0');
        } else if (b == -1 || !isPrintableChar(b) || b == ':') {
            break;
        } else {
            return 0;
        }
        b = readByte(fs);
    }
    return minus ? -n : n;
}

int nexI(FastScanner *fs) {
    long long nl = nexL(fs);
    if (nl < INT_MIN || nl > INT_MAX) return 0;
    return (int)nl;
}

int countFlaged(long long bit) {
    int ans = 0;
    while (bit) {
        ans += bit & 1;
        bit >>= 1;
    }
    return ans;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (soeji == 0) return 1 % p;
    if (ob == 0) return 0;
    if (soeji == 2) return (ob * ob) % p;
    int d = 0;
    long long num = soeji;
    while (num > 0) {
        num >>= 1;
        d++;
    }
    long long ob_pow_2pow[d];
    ob_pow_2pow[0] = ob % p;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
    }
    long long ans = 1;
    for (int i = d-1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int main() {
    FastScanner fs;
    initFastScanner(&fs);
    
    int n = nexI(&fs);
    char s[100001];
    strcpy(s, next(&fs));
    
    bool flaged[n];
    memset(flaged, 0, n * sizeof(bool));
    
    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }
    
    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        surp1 += flaged[i] ? 1 : 0;
        surp1 %= (pop1st + 1);
    }
    
    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            surp9 += flaged[i] ? 1 : 0;
            surp9 %= (pop1st - 1);
        }
    }
    
    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;
            long long dif = pow10E97(2, (long long)(n - p - 1), pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    printf("1/0\n");
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2, (long long)(n - p - 1), pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);
            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    printf("1/0\n");
                    return 1;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
// End of Code
