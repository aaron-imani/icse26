import sys
from bisect import bisect_left

class DLazyFaith:
    def solve(self, testNumber, in_, out):
        a = in_.ints()
        b = in_.ints()
        q = in_.ints()
        s = [-10_000_000_000] * (a + 2)
        t = [-10_000_000_000] * (b + 2)
        for i in range(a):
            s[i + 1] = in_.longs()
        for i in range(b):
            t[i + 1] = in_.longs()
        s[a + 1] = 20_000_000_000
        t[b + 1] = 20_000_000_000
        for _ in range(q):
            x = in_.longs()
            sl = x - s[max(0, bisect_left(s, x + 1) - 1)]
            tl = x - t[max(0, bisect_left(t, x + 1) - 1)]
            sr = s[bisect_left(s, x)] - x
            tr = t[bisect_left(t, x)] - x
            out.ansln(min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            ))

class LightScanner:
    def __init__(self, in_):
        self.reader = in_
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
    def __init__(self, out):
        self.out = out
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
        for n1 in n:
            self.ans(n1).ln()
        return self

    def ln(self):
        self.out.write('\n')
        self.breaked = True
        if self.autoflush:
            self.out.flush()
        return self

    def close(self):
        self.out.close()

def main():
    in_ = LightScanner(sys.stdin)
    out = LightWriter(sys.stdout)
    solver = DLazyFaith()
    solver.solve(1, in_, out)
    out.close()

if __name__ == "__main__":
    main()
# End of Code
