import sys
from collections import defaultdict

class Solver:
    def __init__(self, mod, maxn):
        self.mod = mod
        self.maxn = maxn
        self.hp = Helper(mod, maxn)
        self.hp.init_io(sys.stdin, sys.stdout)

    def solve(self):
        tc = 1  # Assuming no test cases
        for tce in range(1, tc + 1):
            self.solve_case(tce)
        self.hp.flush()

    def solve_case(self, tc):
        N = self.hp.next_int()
        K = self.hp.next_long()
        A = self.hp.get_int_array(N)

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
            self.hp.println(straight[K] + 1)
        else:
            K -= len(straight)
            self.hp.println(cycle[K % len(cycle)] + 1)

class Helper:
    def __init__(self, mod, maxn):
        self.mod = mod
        self.maxn = maxn
        self.rnd = random.Random()

    def set_sieve(self):
        self.primes = []
        self.sieve = [0] * self.maxn
        for i in range(2, self.maxn):
            if self.sieve[i] == 0:
                self.primes.append(i)
                for j in range(i, self.maxn, i):
                    self.sieve[j] = i

    def set_factorial(self):
        self.factorial = [1] * self.maxn
        for i in range(1, self.maxn):
            self.factorial[i] = self.factorial[i - 1] * i % self.mod

    def get_factorial(self, n):
        if not hasattr(self, 'factorial'):
            self.set_factorial()
        return self.factorial[n]

    def ncr(self, n, r):
        if r > n:
            return 0
        if not hasattr(self, 'factorial'):
            self.set_factorial()
        numerator = self.factorial[n]
        denominator = self.factorial[r] * self.factorial[n - r] % self.mod
        return numerator * pow(denominator, self.mod - 2, self.mod) % self.mod

    def get_long_array(self, size):
        return [self.hp.next_long() for _ in range(size)]

    def get_int_array(self, size):
        return [self.hp.next_int() for _ in range(size)]

    def get_string_array(self, size):
        return [self.hp.next() for _ in range(size)]

    def join_elements(self, ar):
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

    def pow(self, base, exp, mod):
        base %= mod
        ret = 1
        while exp > 0:
            if exp & 1:
                ret = ret * base % mod
            base = base * base % mod
            exp >>= 1
        return ret

    def init_io(self, stdin, stdout):
        self.inp = stdin
        self.out = stdout
        self.buf = []
        self.index = 0
        self.total = 0

    def scan(self):
        if self.index >= self.total:
            self.index = 0
            self.total = self.inp.read(1 << 20)
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

    def next_int(self):
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

    def next_long(self):
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
        self.out.write(str(a))

    def printsp(self, a):
        self.print(a)
        self.print(" ")

    def println(self, a=None):
        if a is not None:
            self.print(a)
        self.out.write("\n")

    def flush(self):
        self.out.flush()

if __name__ == "__main__":
    mod = 10**9 + 7
    maxn = 1000006
    solver = Solver(mod, maxn)
    solver.solve()  # End of Code
