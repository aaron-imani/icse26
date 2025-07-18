import sys

class Solver:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.MAXN = 1000006
        self.hp = Helper(self.MOD, self.MAXN)

    def solve(self):
        tc = 1 if not self.TESTCASES else self.hp.nextInt()
        for tce in range(1, tc + 1):
            self.solve_case(tce)
        self.hp.flush()

    def solve_case(self, tc):
        N = self.hp.nextInt()
        K = self.hp.nextLong()
        A = self.hp.getIntArray(N)

        straight, cycle = [], []
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


class Helper:
    def __init__(self, mod, maxn):
        self.MOD = mod
        self.MAXN = maxn
        self.rnd = random.Random()

    def set_sieve(self):
        self.primes = []
        self.sieve = [0] * self.MAXN
        for i in range(2, self.MAXN):
            if self.sieve[i] == 0:
                self.primes.append(i)
                for j in range(i, self.MAXN, i):
                    self.sieve[j] = i

    def set_factorial(self):
        self.factorial = [1] * self.MAXN
        for i in range(1, self.MAXN):
            self.factorial[i] = self.factorial[i - 1] * i % self.MOD

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
        denominator = self.factorial[r] * self.factorial[n - r] % self.MOD
        return numerator * pow(denominator, self.MOD - 2, self.MOD) % self.MOD

    def get_long_array(self, size):
        return [self.nextLong() for _ in range(size)]

    def get_int_array(self, size):
        return [self.nextInt() for _ in range(size)]

    def get_string_array(self, size):
        return [self.next() for _ in range(size)]

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
        import random
        random.shuffle(ar)

    def reverse(self, ar):
        ar.reverse()

    def pow(self, base, exp, MOD):
        base %= MOD
        ret = 1
        while exp > 0:
            if exp & 1:
                ret = ret * base % MOD
            base = base * base % MOD
            exp >>= 1
        return ret

    def init_io(self, input_stream=sys.stdin, output_stream=sys.stdout):
        self.reader = input_stream
        self.writer = output_stream

    def next(self):
        return next(self.reader).strip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def print(self, a):
        self.writer.write(str(a))

    def printsp(self, a):
        self.print(a)
        self.print(" ")

    def println(self, a=None):
        if a is not None:
            self.print(a)
        self.writer.write("\n")

    def flush(self):
        self.writer.flush()


if __name__ == "__main__":
    solver = Solver()
    solver.solve()  # End of Code
