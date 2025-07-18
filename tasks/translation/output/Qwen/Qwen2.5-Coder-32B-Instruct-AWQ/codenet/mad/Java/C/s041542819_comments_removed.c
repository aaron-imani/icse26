#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    char *next_token;
} LightScanner;

typedef struct {
    FILE *file;
    int breaked;
} LightWriter;

void LightScanner_init(LightScanner *scanner, FILE *file) {
    scanner->file = file;
    scanner->next_token = NULL;
}

char* LightScanner_string(LightScanner *scanner) {
    if (scanner->next_token == NULL) {
        if (fgets(scanner->buffer, MAX_LINE_LENGTH, scanner->file) == NULL) {
            return NULL;
        }
        scanner->next_token = strtok(scanner->buffer, " \t\n");
    }
    char *result = scanner->next_token;
    scanner->next_token = strtok(NULL, " \t\n");
    return result;
}

int LightScanner_ints(LightScanner *scanner) {
    char *str = LightScanner_string(scanner);
    return str ? atoi(str) : 0;
}

long LightScanner_longs(LightScanner *scanner) {
    char *str = LightScanner_string(scanner);
    return str ? atol(str) : 0;
}

void LightWriter_init(LightWriter *writer, FILE *file) {
    writer->file = file;
    writer->breaked = 1;
}

void LightWriter_print_char(LightWriter *writer, char c) {
    fputc(c, writer->file);
    writer->breaked = 0;
}

void LightWriter_print_string(LightWriter *writer, const char *s) {
    fputs(s, writer->file);
    writer->breaked = 0;
}

void LightWriter_ans_string(LightWriter *writer, const char *s) {
    if (!writer->breaked) {
        LightWriter_print_char(writer, ' ');
    }
    LightWriter_print_string(writer, s);
}

void LightWriter_ans_long(LightWriter *writer, long l) {
    char buffer[21];
    snprintf(buffer, sizeof(buffer), "%ld", l);
    LightWriter_ans_string(writer, buffer);
}

void LightWriter_ansln_long(LightWriter *writer, long n) {
    LightWriter_ans_long(writer, n);
    LightWriter_print_char(writer, '\n');
    writer->breaked = 1;
}

void LightWriter_close(LightWriter *writer) {
    fclose(writer->file);
}

int lowerBound(long *a, int length, long t) {
    int min = 0;
    int max = length;
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

long min_of_six(long a, long b, long c, long d, long e, long f) {
    long min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    if (d < min_val) min_val = d;
    if (e < min_val) min_val = e;
    if (f < min_val) min_val = f;
    return min_val;
}

long max(long a, long b) {
    return (a > b) ? a : b;
}

void solve(int testNumber, LightScanner *in, LightWriter *out) {
    int a = LightScanner_ints(in);
    int b = LightScanner_ints(in);
    int q = LightScanner_ints(in);
    long *s = (long *)malloc((a + 2) * sizeof(long));
    long *t = (long *)malloc((b + 2) * sizeof(long));
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
        long sl = x - s[(lowerBound(s, a + 2, x + 1) - 1 > 0) ? lowerBound(s, a + 2, x + 1) - 1 : 0];
        long tl = x - t[(lowerBound(t, b + 2, x + 1) - 1 > 0) ? lowerBound(t, b + 2, x + 1) - 1 : 0];
        long sr = s[lowerBound(s, a + 2, x)] - x;
        long tr = t[lowerBound(t, b + 2, x)] - x;
        LightWriter_ansln_long(out, min_of_six(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
        ));
    }
    free(s);
    free(t);
}

int main() {
    LightScanner in;
    LightWriter out;
    LightScanner_init(&in, stdin);
    LightWriter_init(&out, stdout);
    solve(1, &in, &out);
    LightWriter_close(&out);
    return 0;
}
// End of Code
