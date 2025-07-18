import sys
import math
import bisect
from collections import deque, defaultdict, Counter, OrderedDict
from heapq import heappop, heappush

class Solver:
    def __init__(self, input, output):
        self.input = input
        self.output = output

    def solve(self):
        H = self.ni()
        W = self.ni()
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            c = self.ns()
            for j in range(W):
                C[i + 1][j + 1] = c[j]
        if H == 1 and W == 1:
            self.prn("No")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.prn("No")
                    return
        self.prn("Yes")

    def prn(self, s):
        self.output.write(f"{s}\n")

    def prr(self, s):
        self.output.write(s)

    def ni(self):
        return int(self.ns())

    def nl(self):
        return int(self.ns())

    def nd(self):
        return float(self.ns())

    def ns(self):
        return self.input.readline().strip()

    def ndi(self, n):
        return [self.ni() for _ in range(n)]

    def ndl(self, n):
        return [self.nl() for _ in range(n)]

    def ndd(self, n):
        return [self.nd() for _ in range(n)]

    def nds(self, n):
        return [self.ns() for _ in range(n)]

    def nddi(self, n, m):
        return [self.ndi(m) for _ in range(n)]

    def nddl(self, n, m):
        return [self.ndl(m) for _ in range(n)]

class PP:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

class PPP:
    def __init__(self, key, val1, val2):
        self.key = key
        self.val1 = val1
        self.val2 = val2

    def getKey(self):
        return self.key

    def getVal1(self):
        return self.val1

    def getVal2(self):
        return self.val2

class PPL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

class PPDL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def dump(self, output):
        output.write(f"key = {self.key}  val ")
        for v in self.val:
            output.write(f"[{v}] ")
        output.write("\n")

class PPKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def __eq__(self, other):
        if isinstance(other, PPKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

class PPLKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def __eq__(self, other):
        if isinstance(other, PPLKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def getKey(self):
        return self.key

    def getValue(self):
        return self.value

class MyInput:
    def __init__(self, input):
        self.input = input

    def read(self):
        return self.input.read(1)

    def nextInt(self):
        return int(self.ns())

    def nextLong(self):
        return int(self.ns())

    def nextDouble(self):
        return float(self.ns())

    def nextString(self):
        return self.ns().strip()

    def nextDChar(self):
        return list(self.ns())

    def nextChar(self):
        while True:
            c = self.read()
            if c not in ' \r\n\t':
                return c

    def reads(self, len, accept):
        try:
            while True:
                c = self.read()
                if c in accept:
                    break
                if len == len(self.ns):
                    self.ns += self.ns * 3 // 2
                self.ns[len] = c
                len += 1
        except EOFError:
            pass
        return len

    def ns(self):
        while True:
            c = self.read()
            if c not in ' \r\n\t':
                break
        s = c
        while True:
            c = self.read()
            if c in ' \r\n\t':
                break
            s += c
        return s

if __name__ == "__main__":
    input = sys.stdin
    output = sys.stdout
    solver = Solver(input, output)
    solver.solve()
# End of Code
