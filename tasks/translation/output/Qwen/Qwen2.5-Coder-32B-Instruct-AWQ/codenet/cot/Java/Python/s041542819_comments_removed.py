import sys

class Main:
    def __init__(self):
        self.in_ = LightScanner(sys.stdin)
        self.out = LightWriter(sys.stdout)
        self.solver = DLazyFaith()
        self.solver.solve(1, self.in_, self.out)
        self.out.close()

class DLazyFaith:
    def solve(self, testNumber, in_, out):
        a = in_.ints()
        b = in_.ints()
        q = in_.ints()
        s = [0] * (a + 2)
        t = [0] * (b + 2)
        s[0] = t[0] = -10_000_000_000
        for i in range(a):
            s[i + 1] = in_.longs()
        for i in range(b):
            t[i + 1] = in_.longs()
        s[a + 1] = t[b + 1] = 20_000_000_000
        for i in range(q):
            x = in_.longs()
            sl = x - s[max(0, ArrayUtil.lowerBound(s, x + 1) - 1)]
            tl = x - t[max(0, ArrayUtil.lowerBound(t, x + 1) - 1)]
            sr = s[ArrayUtil.lowerBound(s, x)] - x
            tr = t[ArrayUtil.lowerBound(t, x)] - x
            out.ansln(IntMath.min(
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
        self.buffer = []
        self.index = 0

    def string(self):
        if self.index >= len(self.buffer):
            line = self.reader.readline().strip()
            if not line:
                return None
            self.buffer = line.split()
            self.index = 0
        result = self.buffer[self.index]
        self.index += 1
        return result

    def ints(self):
        return int(self.string())

    def longs(self):
        return int(self.string())

class LightWriter:
    def __init__(self, out):
        self.out = out

    def print(self, s):
        self.out.write(str(s))

    def ans(self, s):
        self.print(s)

    def ansln(self, *n):
        for n1 in n:
            self.ans(n1)
            self.ln()

    def ln(self):
        self.print('\n')

    def close(self):
        self.out.flush()

class IntMath:
    @staticmethod
    def min(*v):
        return min(v)

class ArrayUtil:
    @staticmethod
    def lowerBound(a, t, min=0):
        max_ = len(a)
        while min < max_:
            mid = (min + max_) // 2
            if t <= a[mid]:
                max_ = mid
            else:
                min = mid + 1
        return min

if __name__ == "__main__":
    Main()
# End of Code
