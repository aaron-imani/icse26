#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char buffer[1 << 20];
    char *current;
    char *end;
} LightScanner;

void light_scanner_init(LightScanner *scanner) {
    scanner->current = scanner->buffer;
    scanner->end = scanner->buffer;
}

void skip_whitespace(LightScanner *scanner) {
    while (scanner->current < scanner->end && isspace(*scanner->current)) {
        scanner->current++;
    }
    if (scanner->current >= scanner->end) {
        if (!fgets(scanner->buffer, sizeof(scanner->buffer), stdin)) {
            return;
        }
        scanner->current = scanner->buffer;
        scanner->end = scanner->current + strlen(scanner->buffer);
        skip_whitespace(scanner);
    }
}

char *light_scanner_next_token(LightScanner *scanner) {
    skip_whitespace(scanner);
    if (scanner->current >= scanner->end) {
        return NULL;
    }
    char *start = scanner->current;
    while (scanner->current < scanner->end && !isspace(*scanner->current)) {
        scanner->current++;
    }
    char *end = scanner->current;
    *end = '\0';
    return start;
}

int light_scanner_int(LightScanner *scanner) {
    char *token = light_scanner_next_token(scanner);
    return atoi(token);
}

long light_scanner_long(LightScanner *scanner) {
    char *token = light_scanner_next_token(scanner);
    return strtoll(token, NULL, 10);
}

int lower_bound(long *a, int len, long t, int min) {
    int max = len;
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

int main() {
    LightScanner scanner;
    light_scanner_init(&scanner);

    int a = light_scanner_int(&scanner);
    int b = light_scanner_int(&scanner);
    int q = light_scanner_int(&scanner);

    long *s = malloc((a + 2) * sizeof(long));
    long *t = malloc((b + 2) * sizeof(long));

    s[0] = -10000000000L;
    t[0] = -10000000000L;

    for (int i = 1; i <= a; i++) {
        s[i] = light_scanner_long(&scanner);
    }
    s[a + 1] = 20000000000L;

    for (int i = 1; i <= b; i++) {
        t[i] = light_scanner_long(&scanner);
    }
    t[b + 1] = 20000000000L;

    for (int i = 0; i < q; i++) {
        long x = light_scanner_long(&scanner);

        int pos_s_plus = lower_bound(s, a + 2, x + 1, 0);
        int s_prev = pos_s_plus > 0 ? pos_s_plus - 1 : 0;
        long sl = x - s[s_prev];

        int pos_t_plus = lower_bound(t, b + 2, x + 1, 0);
        int t_prev = pos_t_plus > 0 ? pos_t_plus - 1 : 0;
        long tl = x - t[t_prev];

        int pos_s = lower_bound(s, a + 2, x, 0);
        long sr = s[pos_s] - x;

        int pos_t = lower_bound(t, b + 2, x, 0);
        long tr = t[pos_t] - x;

        long term1 = (sl > tl) ? sl : tl;
        long term2 = (sr > tr) ? sr : tr;
        long term3 = 2 * sl + tr;
        long term4 = 2 * tl + sr;
        long term5 = sl + 2 * tr;
        long term6 = tl + 2 * sr;

        long min_val = term1;
        if (term2 < min_val) min_val = term2;
        if (term3 < min_val) min_val = term3;
        if (term4 < min_val) min_val = term4;
        if (term5 < min_val) min_val = term5;
        if (term6 < min_val) min_val = term6;

        printf("%ld\n", min_val);
    }

    free(s);
    free(t);
    return 0;
}
// End of Code
