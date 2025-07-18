import bisect
import sys

class LightScanner:
    def __init__(self, stdin):
        self.tokens = []
        for line in stdin:
            self.tokens.extend(line.split())
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.tokens):
            raise Exception("No more tokens")
        token = self.tokens[self.ptr]
        self.ptr += 1
        return token

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

class LightWriter:
    def __init__(self):
        self.answers = []

    def ansln(self, value):
        self.answers.append(str(value))

    def close(self):
        print('\n'.join(self.answers))

def main():
    in_stream = sys.stdin
    scanner = LightScanner(in_stream)
    out = LightWriter()

    a = scanner.next_int()
    b = scanner.next_int()
    q = scanner.next_int()

    s = [-10_000_000_000]
    for _ in range(a):
        s.append(scanner.next_long())
    s.append(20_000_000_000)

    t = [-10_000_000_000]
    for _ in range(b):
        t.append(scanner.next_long())
    t.append(20_000_000_000)

    for _ in range(q):
        x = scanner.next_long()
        # Compute sl and tl
        idx_s = bisect.bisect_left(s, x + 1)
        prev_s_idx = max(0, idx_s - 1)
        sl = x - s[prev_s_idx]

        idx_t = bisect.bisect_left(t, x + 1)
        prev_t_idx = max(0, idx_t - 1)
        tl = x - t[prev_t_idx]

        # Compute sr and tr
        next_s_idx = bisect.bisect_left(s, x)
        sr = s[next_s_idx] - x

        next_t_idx = bisect.bisect_left(t, x)
        tr = t[next_t_idx] - x

        # Calculate all possible values and find the minimum
        val1 = max(sl, tl)
        val2 = max(sr, tr)
        val3 = 2 * sl + tr
        val4 = 2 * tl + sr
        val5 = sl + 2 * tr
        val6 = tl + 2 * sr
        min_val = min(val1, val2, val3, val4, val5, val6)

        out.ansln(min_val)

    out.close()

if __name__ == "__main__":
    main()  # End of Code
