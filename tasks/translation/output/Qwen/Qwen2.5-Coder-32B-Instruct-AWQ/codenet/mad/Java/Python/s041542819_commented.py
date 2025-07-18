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
        return int(self.string())  # In Python, int can handle long integers

class LightWriter:
    def __init__(self, output_stream):
        self.out = output_stream

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

class IntMath:
    @staticmethod
    def min(*v):
        return min(v)

class ArrayUtil:
    @staticmethod
    def lowerBound(a, t, min_index=0):
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
            sl = x - s[max(0, ArrayUtil.lowerBound(s, x + 1) - 1)]
            tl = x - t[max(0, ArrayUtil.lowerBound(t, x + 1) - 1)]
            sr = s[ArrayUtil.lowerBound(s, x)] - x
            tr = t[ArrayUtil.lowerBound(t, x)] - x
            result = IntMath.min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            )
            out_stream.ansln(result)

def main():
    in_stream = LightScanner(sys.stdin)
    out_stream = LightWriter(sys.stdout)
    solver = DLazyFaith()
    solver.solve(1, in_stream, out_stream)
    out_stream.close()

if __name__ == "__main__":
    main()
# End of Code
