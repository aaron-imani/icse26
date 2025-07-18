import sys
from bisect import bisect_left

class DLazyFaith:
    def solve(self, testNumber, in_stream, out_stream):
        a, b, q = map(int, in_stream.readline().split())
        s = [-10_000_000_000]
        t = [-10_000_000_000]
        for _ in range(a):
            s.append(int(in_stream.readline()))
        for _ in range(b):
            t.append(int(in_stream.readline()))
        s.append(20_000_000_000)
        t.append(20_000_000_000)
        
        for _ in range(q):
            x = int(in_stream.readline())
            idx_s = bisect_left(s, x)
            idx_t = bisect_left(t, x)
            
            sl = x - s[idx_s - 1]
            tl = x - t[idx_t - 1]
            sr = s[idx_s] - x
            tr = t[idx_t] - x
            
            out_stream.write(f"{min(max(sl, tl), max(sr, tr), 2 * sl + tr, 2 * tl + sr, sl + 2 * tr, tl + 2 * sr)}\n")

class LightScanner:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = iter(self.in_stream.readline().split())
        return next(self.tokenizer)

    def ints(self):
        return int(self.string())

    def longs(self):
        return int(self.string())

class LightWriter:
    def __init__(self, out_stream):
        self.out_stream = out_stream
        self.autoflush = False
        self.breaked = True

    def print(self, s):
        self.out_stream.write(str(s))
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
        self.out_stream.write('\n')
        self.breaked = True
        if self.autoflush:
            self.out_stream.flush()
        return self

    def close(self):
        self.out_stream.close()

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    scanner = LightScanner(in_stream)
    writer = LightWriter(out_stream)
    solver = DLazyFaith()
    solver.solve(1, scanner, writer)
    writer.close()

if __name__ == "__main__":
    main()

# End of Code
