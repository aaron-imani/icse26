import sys
from collections import deque
from math import gcd

class Helper:
    def __init__(self, mod, maxn):
        self.MOD = mod
        self.MAXN = maxn
        self.rnd = random.Random()
        self.sieve = [0] * self.MAXN
        self.primes = []
        self.factorial = [0] * self.MAXN
        self.setSieve()
        self.setFactorial()
        self.initIO(sys.stdin, sys.stdout)

    def setSieve(self):
        for i in range(2, self.MAXN):
            if self.sieve[i] == 0:
                self.primes.append(i)
                for j in range(i, self.MAXN, i):
                    self.sieve[j] = i

    def setFactorial(self):
        self.factorial[0] = 1
        for i in range(1, self.MAXN):
            self.factorial[i] = self.factorial[i - 1] * i % self.MOD

    def getFactorial(self, n):
        return self.factorial[n]

    def ncr(self, n, r):
        if r > n:
            return 0
        numerator = self.factorial[n]
        denominator = self.factorial[r] * self.factorial[n - r] % self.MOD
        return numerator * pow(denominator, self.MOD - 2, self.MOD) % self.MOD

    def getLongArray(self, size):
        return [self.nextLong() for _ in range(size)]

    def getIntArray(self, size):
        return [self.nextInt() for _ in range(size)]

    def getStringArray(self, size):
        return [self.next() for _ in range(size)]

    def joinElements(self, *ar):
        return ' '.join(map(str, ar))

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def max(self, *ar):
        return max(ar)

    def min(self, *ar):
        return min(ar)

    def sum(self, *ar):
        return sum(ar)

    def shuffle(self, ar):
        for i in range(len(ar)):
            r = self.rnd.randint(0, len(ar) - 1)
            if r != i:
                ar[i], ar[r] = ar[r], ar[i]

    def reverse(self, ar):
        for i in range(len(ar) // 2):
            ar[i], ar[len(ar) - 1 - i] = ar[len(ar) - 1 - i], ar[i]

    def pow(self, base, exp, MOD):
        base %= MOD
        ret = 1
        while exp > 0:
            if exp & 1:
                ret = ret * base % MOD
            base = base * base % MOD
            exp >>= 1
        return ret

    def initIO(self, is_, os_):
        self.in_ = is_
        self.bw = os_

    def scan(self):
        if self.index >= self.total:
            self.index = 0
            self.total = self.in_.read(self.BUFSIZE)
            if self.total <= 0:
                return -1
        return self.total[self.index]

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
        neg = c == '-'
        if c == '-' or c == '+':
            c = self.scan()
        val = 0
        while c >= '0' and c <= '9':
            val = (val << 3) + (val << 1) + (c & 15)
            c = self.scan()
        return -val if neg else val

    def nextLong(self):
        c = self.scan()
        while c <= 32:
            c = self.scan()
        neg = c == '-'
        if c == '-' or c == '+':
            c = self.scan()
        val = 0
        while c >= '0' and c <= '9':
            val = (val << 3) + (val << 1) + (c & 15)
            c = self.scan()
        return -val if neg else val

    def print(self, a):
        self.bw.write(str(a))

    def printsp(self, a):
        self.print(a)
        self.print(' ')

    def println(self, a=None):
        if a is not None:
            self.print(a)
        self.bw.write('\n')

    def flush(self):
        self.bw.flush()


class Solver:
    def __init__(self):
        self.hp = Helper(10**9 + 7, 1000_006)
        self.TESTCASES = False

    def solve(self):
        tc = self.hp.nextInt() if self.TESTCASES else 1
        for tce in range(1, tc + 1):
            self.solve(tce)
        self.hp.flush()

    def solve(self, tc):
        N = self.hp.nextInt()
        K = self.hp.nextLong()
        A = self.hp.getIntArray(N)

        straight = []
        cycle = []
        vis = [False] * N
        curr = 0
        while not vis[curr]:
            vis[curr] = True
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


def main():
    solver = Solver()
    solver.solve()


if __name__ == '__main__':
    main()
# End of Code
