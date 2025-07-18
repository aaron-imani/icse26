import sys
import bisect

class LightScanner:
    def __init__(self, input):
        self.input = input
        self.buffer = []
        self.index = 0

    def _read(self):
        if not self.buffer:
            line = self.input.readline()
            if not line:
                raise EOFError
            self.buffer = line.split()
            self.index = 0
        return self.buffer[self.index]

    def string(self):
        return self._read()

    def ints(self):
        return int(self._read())

    def longs(self):
        return int(self._read())

class LightWriter:
    def __init__(self, output):
        self.output = output

    def print(self, s):
        self.output.write(str(s))

    def ans(self, s):
        self.print(s)

    def ansln(self, *n):
        for n1 in n:
            self.ans(n1)
            self.ln()

    def ln(self):
        self.output.write('\n')

    def close(self):
        self.output.close()

class IntMath:
    @staticmethod
    def min(*v):
        return min(v)

class ArrayUtil:
    @staticmethod
    def lower_bound(a, t):
        return bisect.bisect_left(a, t)

def main():
    input = sys.stdin
    output = sys.stdout
    in_ = LightScanner(input)
    out = LightWriter(output)
    solver = DLazyFaith()
    solver.solve(1, in_, out)
    out.close()

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
        s[a + 1] = t[b + 1] = 20_000_000_000
        for _ in range(q):
            x = in_.longs()
            sl = x - s[max(0, ArrayUtil.lower_bound(s, x + 1) - 1)]
            tl = x - t[max(0, ArrayUtil.lower_bound(t, x + 1) - 1)]
            sr = s[ArrayUtil.lower_bound(s, x)] - x
            tr = t[ArrayUtil.lower_bound(t, x)] - x
            out.ansln(IntMath.min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            ))

if __name__ == "__main__":
    main()
# End of Code
