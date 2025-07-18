import sys
from typing import List

class Helper:
    def __init__(self, mod: int, maxn: int):
        self.MOD = mod
        self.MAXN = maxn
        self.initIO(sys.stdin, sys.stdout)

    def initIO(self, input_stream, output_stream):
        self.in_stream = input_stream
        self.out_stream = output_stream
        self.buf = bytearray()
        self.index = 0
        self.total = 0

    def scan(self):
        if self.index >= self.total:
            self.index = 0
            self.total = self.in_stream.readinto(self.buf)
            if self.total <= 0:
                return -1
        byte = self.buf[self.index]
        self.index += 1
        return byte

    def next(self):
        c = self.scan()
        while c <= 32:
            c = self.scan()
        sb = []
        while c > 32:
            sb.append(chr(c))
            c = self.scan()
        return ''.join(sb)

    def nextInt(self):
        c = self.scan()
        while c <= 32:
            c = self.scan()
        neg = c == b'-'
        if c == b'-' or c == b'+':
            c = self.scan()
        val = 0
        while c >= b'0' and c <= b'9':
            val = (val << 3) + (val << 1) + (c - b'0')
            c = self.scan()
        return -val if neg else val

    def nextLong(self):
        c = self.scan()
        while c <= 32:
            c = self.scan()
        neg = c == b'-'
        if c == b'-' or c == b'+':
            c = self.scan()
        val = 0
        while c >= b'0' and c <= b'9':
            val = (val << 3) + (val << 1) + (c - b'0')
            c = self.scan()
        return -val if neg else val

    def print(self, a):
        self.out_stream.write(str(a))

    def println(self, a=None):
        if a is not None:
            self.print(a)
        self.out_stream.write("\n")

    def flush(self):
        self.out_stream.flush()


class Solver:
    def __init__(self):
        self.hp = Helper(1000000007, 1000006)
        self.MAXN = 1000006
        self.MOD = 1000000007
        self.TESTCASES = False

    def solve(self):
        tc = self.hp.nextInt() if self.TESTCASES else 1
        for tce in range(1, tc + 1):
            self.solve(tce)
        self.hp.flush()

    def solve(self, tc):
        N = self.hp.nextInt()
        K = self.hp.nextLong()
        A = [self.hp.nextInt() for _ in range(N)]

        straight = []
        cycle = []
        vis = [False] * N
        curr = 0
        while not vis[curr]:
            vis[curr] = True
            straight.append(curr)
            curr = A[curr] - 1

        st = 0
        while st != curr:
            straight.append(st)
            st = A[st] - 1

        cycle.append(curr)
        curr = A[curr] - 1
        while curr != cycle[0]:
            cycle.append(curr)
            curr = A[curr] - 1

        if K < len(straight):
            self.hp.println(straight[int(K)] + 1)
        else:
            K -= len(straight)
            self.hp.println(cycle[int(K % len(cycle))] + 1)

if __name__ == "__main__":
    solver = Solver()
    solver.solve()
# End of Code
