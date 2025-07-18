import sys

class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.buffer = []
        self.index = 0

    def _read(self):
        line = self.reader.readline().strip()
        if line:
            self.buffer.extend(line.split())
        else:
            self.buffer = []

    def string(self):
        if self.index >= len(self.buffer):
            self._read()
        if self.index < len(self.buffer):
            result = self.buffer[self.index]
            self.index += 1
            return result
        else:
            raise EOFError

    def ints(self):
        return int(self.string())

    def longs(self):
        return int(self.string())  # In Python, int can handle long values

class LightWriter:
    def __init__(self, output_stream):
        self.out = output_stream
        self.autoflush = False
        self.breaked = True

    def print(self, s):
        self.out.write(s)
        self.breaked = False

    def ans(self, s):
        if not self.breaked:
            self.print(' ')
        self.print(str(s))

    def ansln(self, *n):
        for n1 in n:
            self.ans(n1)
            self.ln()

    def ln(self):
        self.print('\n')
        self.breaked = True
        if self.autoflush:
            self.out.flush()

    def close(self):
        self.out.close()

class IntMath:
    @staticmethod
    def min(*v):
        if not v:
            raise ValueError("min() arg is an empty sequence")
        return min(v)

class ArrayUtil:
    @staticmethod
    def lower_bound(a, t, min_index=0):
        max_index = len(a)
        while min_index < max_index:
            mid = (min_index + max_index) // 2
            if t <= a[mid]:
                max_index = mid
            else:
                min_index = mid + 1
        return min_index

class DLazyFaith:
    def solve(self, test_number, in_stream, out_stream):
        a = in_stream.ints()
        b = in_stream.ints()
        q = in_stream.ints()
        s = [-10_000_000_000] * (a + 2)
        t = [-10_000_000_000] * (b + 2)
        for i in range(a):
            s[i + 1] = in_stream.longs()
        for i in range(b):
            t[i + 1] = in_stream.longs()
        s[a + 1] = t[b + 1] = 20_000_000_000
        for _ in range(q):
            x = in_stream.longs()
            sl = x - s[max(0, ArrayUtil.lower_bound(s, x + 1) - 1)]
            tl = x - t[max(0, ArrayUtil.lower_bound(t, x + 1) - 1)]
            sr = s[ArrayUtil.lower_bound(s, x)] - x
            tr = t[ArrayUtil.lower_bound(t, x)] - x
            out_stream.ansln(IntMath.min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            ))

def main():
    in_stream = LightScanner(sys.stdin)
    out_stream = LightWriter(sys.stdout)
    solver = DLazyFaith()
    solver.solve(1, in_stream, out_stream)
    out_stream.close()

if __name__ == "__main__":
    main()
# End of Code
