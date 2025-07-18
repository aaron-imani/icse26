#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005
#define INF 10000000000LL

typedef struct {
    FILE *in;
} LightScanner;

typedef struct {
    FILE *out;
} LightWriter;

LightScanner* LightScanner_new(FILE *in) {
    LightScanner *scanner = (LightScanner*)malloc(sizeof(LightScanner));
    scanner->in = in;
    return scanner;
}

char* LightScanner_string(LightScanner *scanner) {
    static char buffer[1024];
    fscanf(scanner->in, "%s", buffer);
    return buffer;
}

int LightScanner_ints(LightScanner *scanner) {
    return atoi(LightScanner_string(scanner));
}

long long LightScanner_longs(LightScanner *scanner) {
    return atoll(LightScanner_string(scanner));
}

void LightScanner_free(LightScanner *scanner) {
    free(scanner);
}

LightWriter* LightWriter_new(FILE *out) {
    LightWriter *writer = (LightWriter*)malloc(sizeof(LightWriter));
    writer->out = out;
    return writer;
}

void LightWriter_print(LightWriter *writer, const char *s) {
    fprintf(writer->out, "%s", s);
}

void LightWriter_ans(LightWriter *writer, long long l) {
    fprintf(writer->out, "%lld", l);
}

void LightWriter_ansln(LightWriter *writer, long long n) {
    LightWriter_ans(writer, n);
    fprintf(writer->out, "\n");
}

void LightWriter_close(LightWriter *writer) {
    fclose(writer->out);
    free(writer);
}

int lowerBound(long long *a, int n, long long t) {
    int min = 0, max = n;
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

long long IntMath_min(long long a, long long b, long long c, long long d, long long e, long long f) {
    long long min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    if (d < min_val) min_val = d;
    if (e < min_val) min_val = e;
    if (f < min_val) min_val = f;
    return min_val;
}

void DLazyFaith_solve(int testNumber, LightScanner *in, LightWriter *out) {
    int a = LightScanner_ints(in), b = LightScanner_ints(in), q = LightScanner_ints(in);
    long long s[MAX_N + 2], t[MAX_N + 2];
    s[0] = t[0] = -INF;
    for (int i = 0; i < a; i++) {
        s[i + 1] = LightScanner_longs(in);
    }
    for (int i = 0; i < b; i++) {
        t[i + 1] = LightScanner_longs(in);
    }
    s[a + 1] = t[b + 1] = INF;
    for (int i = 0; i < q; i++) {
        long long x = LightScanner_longs(in);
        long long sl = x - s[lowerBound(s, a + 2, x + 1) - 1];
        long long tl = x - t[lowerBound(t, b + 2, x + 1) - 1];
        long long sr = s[lowerBound(s, a + 2, x)] - x;
        long long tr = t[lowerBound(t, b + 2, x)] - x;
        LightWriter_ansln(out, IntMath_min(sl, tl, sr, tr, 2 * sl + tr, 2 * tl + sr));
    }
}

int main() {
    LightScanner *in = LightScanner_new(stdin);
    LightWriter *out = LightWriter_new(stdout);
    DLazyFaith_solve(1, in, out);
    LightWriter_close(out);
    LightScanner_free(in);
    return 0;
}
// End of Code
