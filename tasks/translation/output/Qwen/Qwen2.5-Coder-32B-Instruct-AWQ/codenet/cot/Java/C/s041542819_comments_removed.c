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

void LightScanner_init(LightScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->ptr = scanner->buffer;
    scanner->end = scanner->buffer;
}

int LightScanner_hasNext(LightScanner *scanner) {
    if (scanner->ptr < scanner->end) return 1;
    size_t bytesRead = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->in);
    if (bytesRead == 0) return 0;
    scanner->ptr = scanner->buffer;
    scanner->end = scanner->buffer + bytesRead;
    return 1;
}

char *LightScanner_next(LightScanner *scanner) {
    while (LightScanner_hasNext(scanner)) {
        char *start = scanner->ptr;
        while (scanner->ptr < scanner->end && (*scanner->ptr == ' ' || *scanner->ptr == '\n')) scanner->ptr++;
        if (scanner->ptr >= scanner->end) continue;
        start = scanner->ptr;
        while (scanner->ptr < scanner->end && *scanner->ptr != ' ' && *scanner->ptr != '\n') scanner->ptr++;
        *scanner->ptr++ = '\0';
        return start;
    }
    return NULL;
}

int LightScanner_ints(LightScanner *scanner) {
    return atoi(LightScanner_next(scanner));
}

long LightScanner_longs(LightScanner *scanner) {
    return atol(LightScanner_next(scanner));
}

typedef struct {
    FILE *out;
} LightWriter;

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
    LightWriter_ans(writer, n);
    fprintf(writer->out, "\n");
}

void LightWriter_close(LightWriter *writer) {
    fclose(writer->out);
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

int ArrayUtil_lowerBound(long *a, int n, long t) {
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

typedef struct {
    long *s;
    long *t;
} DLazyFaith;

void DLazyFaith_solve(DLazyFaith *solver, int testNumber, LightScanner *in, LightWriter *out) {
    int a = LightScanner_ints(in), b = LightScanner_ints(in), q = LightScanner_ints(in);
    solver->s = (long *)malloc((a + 2) * sizeof(long));
    solver->t = (long *)malloc((b + 2) * sizeof(long));
    solver->s[0] = solver->t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        solver->s[i + 1] = LightScanner_longs(in);
    }
    for (int i = 0; i < b; i++) {
        solver->t[i + 1] = LightScanner_longs(in);
    }
    solver->s[a + 1] = solver->t[b + 1] = 20000000000L;
    for (int i = 0; i < q; i++) {
        long x = LightScanner_longs(in);
        long sl = x - solver->s[ArrayUtil_lowerBound(solver->s, a + 2, x + 1) - 1];
        long tl = x - solver->t[ArrayUtil_lowerBound(solver->t, b + 2, x + 1) - 1];
        long sr = solver->s[ArrayUtil_lowerBound(solver->s, a + 2, x)] - x;
        long tr = solver->t[ArrayUtil_lowerBound(solver->t, b + 2, x)] - x;
        LightWriter_ansln(out, IntMath_min(sl, tl, IntMath_min(sr, tr, IntMath_min(2 * sl + tr, 2 * tl + sr, IntMath_min(sl + 2 * tr, tl + 2 * sr)))));
    }
    free(solver->s);
    free(solver->t);
}

int main() {
    LightScanner in;
    LightWriter out;
    LightScanner_init(&in, stdin);
    LightWriter_init(&out, stdout);
    DLazyFaith solver;
    DLazyFaith_solve(&solver, 1, &in, &out);
    LightWriter_close(&out);
    return 0;
}
// End of Code
