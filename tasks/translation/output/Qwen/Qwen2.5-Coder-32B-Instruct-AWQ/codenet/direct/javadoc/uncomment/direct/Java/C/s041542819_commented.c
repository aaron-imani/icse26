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

void LightScanner_init(LightScanner *scanner, FILE *in) {
    scanner->in = in;
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

void LightWriter_init(LightWriter *writer, FILE *out) {
    writer->out = out;
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

long long min_of_array(long long *arr, int size) {
    long long min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

void solve(int testNumber, LightScanner *in, LightWriter *out) {
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
        long long sl = x - s[(lowerBound(s, a + 2, x + 1) - 1 > 0 ? lowerBound(s, a + 2, x + 1) - 1 : 0)];
        long long tl = x - t[(lowerBound(t, b + 2, x + 1) - 1 > 0 ? lowerBound(t, b + 2, x + 1) - 1 : 0)];
        long long sr = s[lowerBound(s, a + 2, x)] - x;
        long long tr = t[lowerBound(t, b + 2, x)] - x;
        long long values[] = { 
            (sl > tl ? sl : tl),
            (2 * sl + tr),
            (2 * tl + sr),
            (sl + 2 * tr),
            (tl + 2 * sr)
        };
        LightWriter_ansln(out, min_of_array(values, 5));
    }
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
