#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define LARGE_NEG -10000000000LL
#define LARGE_POS 20000000000LL

typedef struct {
    FILE *file;
} LightScanner;

typedef struct {
    FILE *file;
    int breaked;
} LightWriter;

LightScanner* LightScanner_new(FILE *in) {
    LightScanner *scanner = (LightScanner*)malloc(sizeof(LightScanner));
    scanner->file = in;
    return scanner;
}

int LightScanner_ints(LightScanner *scanner) {
    int value;
    fscanf(scanner->file, "%d", &value);
    return value;
}

long long LightScanner_longs(LightScanner *scanner) {
    long long value;
    fscanf(scanner->file, "%lld", &value);
    return value;
}

LightWriter* LightWriter_new(FILE *out) {
    LightWriter *writer = (LightWriter*)malloc(sizeof(LightWriter));
    writer->file = out;
    writer->breaked = 1;
    return writer;
}

void LightWriter_print(LightWriter *writer, const char *s) {
    fprintf(writer->file, "%s", s);
    writer->breaked = 0;
}

void LightWriter_ans(LightWriter *writer, long long l) {
    if (!writer->breaked) {
        LightWriter_print(writer, " ");
    }
    fprintf(writer->file, "%lld", l);
}

void LightWriter_ansln(LightWriter *writer, long long l) {
    LightWriter_ans(writer, l);
    LightWriter_print(writer, "\n");
    writer->breaked = 1;
}

void LightWriter_close(LightWriter *writer) {
    fclose(writer->file);
    free(writer);
}

int lowerBound(long long *a, int length, long long t) {
    int min = 0, max = length;
    while (min < max) {
        int mid = (min + max) / 2;
        if (t <= a[mid]) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    return min;
}

long long IntMath_min(long long *v, int length) {
    long long min = LLONG_MAX;
    for (int i = 0; i < length; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

void DLazyFaith_solve(int testNumber, LightScanner *in, LightWriter *out) {
    int a = LightScanner_ints(in), b = LightScanner_ints(in), q = LightScanner_ints(in);
    long long *s = (long long*)malloc((a + 2) * sizeof(long long));
    long long *t = (long long*)malloc((b + 2) * sizeof(long long));
    s[0] = t[0] = LARGE_NEG;
    for (int i = 0; i < a; i++) {
        s[i + 1] = LightScanner_longs(in);
    }
    for (int i = 0; i < b; i++) {
        t[i + 1] = LightScanner_longs(in);
    }
    s[a + 1] = t[b + 1] = LARGE_POS;
    for (int i = 0; i < q; i++) {
        long long x = LightScanner_longs(in);
        long long sl = x - s[MAX(0, lowerBound(s, a + 2, x + 1) - 1)];
        long long tl = x - t[MAX(0, lowerBound(t, b + 2, x + 1) - 1)];
        long long sr = s[lowerBound(s, a + 2, x)] - x;
        long long tr = t[lowerBound(t, b + 2, x)] - x;
        long long values[] = {
            MAX(sl, tl),
            MAX(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        };
        LightWriter_ansln(out, IntMath_min(values, 6));
    }
    free(s);
    free(t);
}

int main() {
    LightScanner *in = LightScanner_new(stdin);
    LightWriter *out = LightWriter_new(stdout);
    DLazyFaith_solve(1, in, out);
    LightWriter_close(out);
    free(in);
    return 0;
}
// End of Code
