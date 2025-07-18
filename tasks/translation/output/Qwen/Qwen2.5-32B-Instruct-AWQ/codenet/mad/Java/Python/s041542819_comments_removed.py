import sys
from bisect import bisect_left

class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = iter(self.reader.readline().split())
        return next(self.tokenizer)

    def ints(self):
        return int(self.string())

    def longs(self):
        return int(self.string())

class LightWriter:
    def __init__(self, output_stream):
        self.out = output_stream
        self.autoflush = False
        self.breaked = True

    def print(self, s):
        self.out.write(str(s))
        self.breaked = False
        return self

    def ans(self, s):
        if not self.breaked:
            self.print(' ')
        return self.print(s)

    def ansln(self, *n):
        for num in n:
            self.ans(num).ln()
        return self

    def ln(self):
        self.out.write('\n')
        self.breaked = True
        if self.autoflush:
            self.out.flush()
        return self

    def close(self):
        self.out.close()


def min_value(*v):
    return min(v)

def lower_bound(a, t):
    return bisect_left(a, t)

def solve(test_number, in_stream, out_stream):
    a = in_stream.ints()
    b = in_stream.ints()
    q = in_stream.ints()
    s = [-10_000_000_000] * (a + 2)
    t = [-10_000_000_000] * (b + 2)
    for i in range(a):
        s[i + 1] = in_stream.longs()
    for i in range(b):
        t[i + 1] = in_stream.longs()
    s[a + 1] = 20_000_000_000
    t[b + 1] = 20_000_000_000
    for _ in range(q):
        x = in_stream.longs()
        sl = x - s[max(0, lower_bound(s, x + 1) - 1)]
        tl = x - t[max(0, lower_bound(t, x + 1) - 1)]
        sr = s[lower_bound(s, x)] - x
        tr = t[lower_bound(t, x)] - x
        out_stream.ansln(min_value(
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        ))

if __name__ == "__main__":
    in_stream = LightScanner(sys.stdin)
    out_stream = LightWriter(sys.stdout)
    solve(1, in_stream, out_stream)
    out_stream.close()  # End of Code
