#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    FILE *in;
    char buffer[1024];
    char *ptr;
    char *end;
} LightScanner;

typedef struct {
    FILE *out;
} LightWriter;

void LightScanner_init(LightScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->ptr = scanner->buffer;
    scanner->end = scanner->buffer;
}

char *LightScanner_nextToken(LightScanner *scanner) {
    while (scanner->ptr == scanner->end) {
        scanner->end = fgets(scanner->buffer, sizeof(scanner->buffer), scanner->in);
        if (scanner->end == NULL) {
            return NULL;
        }
        scanner->ptr = scanner->buffer;
    }
    char *start = scanner->ptr;
    while (*scanner->ptr != ' ' && *scanner->ptr != '\n' && *scanner->ptr != '\0') {
        scanner->ptr++;
    }
    if (*scanner->ptr != '\0') {
        *scanner->ptr++ = '\0';
    }
    return start;
}

int LightScanner_ints(LightScanner *scanner) {
    return atoi(LightScanner_nextToken(scanner));
}

long LightScanner_longs(LightScanner *scanner) {
    return atol(LightScanner_nextToken(scanner));
}

void LightWriter_init(LightWriter *writer, FILE *out) {
    writer->out = out;
}

void LightWriter_print(LightWriter *writer, const char *s) {
    fprintf(writer->out, "%s", s);
}

void LightWriter_ans(LightWriter *writer, long l) {
    fprintf(writer->out, "%ld", l);
}

void LightWriter_ansln(LightWriter *writer, long n) {
    fprintf(writer->out, "%ld\n", n);
}

void LightWriter_close(LightWriter *writer) {
    fclose(writer->out);
}

int lowerBound(long *a, int size, long t) {
    int min = 0;
    int max = size;
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

long IntMath_min(long a, long b, long c, long d, long e, long f) {
    long min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    if (f < min) min = f;
    return min;
}

void DLazyFaith_solve(int testNumber, LightScanner *in, LightWriter *out) {
    int a = LightScanner_ints(in), b = LightScanner_ints(in), q = LightScanner_ints(in);
    long s[a + 2], t[b + 2];
    s[0] = t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        s[i + 1] = LightScanner_longs(in);
    }
    for (int i = 0; i < b; i++) {
        t[i + 1] = LightScanner_longs(in);
    }
    s[a + 1] = t[b + 1] = 20000000000L;
    for (int i = 0; i < q; i++) {
        long x = LightScanner_longs(in);
        long sl = x - s[(lowerBound(s, a + 2, x + 1) - 1 > 0 ? lowerBound(s, a + 2, x + 1) - 1 : 0)];
        long tl = x - t[(lowerBound(t, b + 2, x + 1) - 1 > 0 ? lowerBound(t, b + 2, x + 1) - 1 : 0)];
        long sr = s[lowerBound(s, a + 2, x)] - x;
        long tr = t[lowerBound(t, b + 2, x)] - x;
        LightWriter_ansln(out, IntMath_min(
                (sl > tl ? sl : tl),
                (sr > tr ? sr : tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
        ));
    }
}

int main() {
    LightScanner in;
    LightWriter out;
    LightScanner_init(&in, stdin);
    LightWriter_init(&out, stdout);
    DLazyFaith_solve(1, &in, &out);
    LightWriter_close(&out);
    return 0;
}
// End of Code
