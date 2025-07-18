import sys
import bisect

class Main:
    def __init__(self):
        self.inp = sys.stdin
        self.out = sys.stdout
        self.in_scanner = LightScanner(self.inp)
        self.out_writer = LightWriter(self.out)
        self.solver = DLazyFaith()
        self.solver.solve(1, self.in_scanner, self.out_writer)
        self.out_writer.close()

class DLazyFaith:
    def solve(self, testNumber, in_scanner, out_writer):
        a = in_scanner.ints()
        b = in_scanner.ints()
        q = in_scanner.ints()
        s = [0] * (a + 2)
        t = [0] * (b + 2)
        s[0] = t[0] = -10_000_000_000
        for i in range(a):
            s[i + 1] = in_scanner.longs()
        for i in range(b):
            t[i + 1] = in_scanner.longs()
        s[a + 1] = t[b + 1] = 20_000_000_000
        for i in range(q):
            x = in_scanner.longs()
            sl = x - s[max(0, bisect.bisect_left(s, x + 1) - 1)]
            tl = x - t[max(0, bisect.bisect_left(t, x + 1) - 1)]
            sr = s[bisect.bisect_left(s, x)] - x
            tr = t[bisect.bisect_left(t, x)] - x
            out_writer.ansln(min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            ))

class LightScanner:
    def __init__(self, inp):
        self.reader = inp
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
        self.out.write('\n')

    def close(self):
        self.out.flush()

if __name__ == "__main__":
    Main()
# End of Code
