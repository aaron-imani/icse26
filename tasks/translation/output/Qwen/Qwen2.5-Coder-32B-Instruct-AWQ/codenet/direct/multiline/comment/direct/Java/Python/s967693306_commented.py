import sys
from collections import defaultdict

INF = sys.maxsize // 2
MOD = 1_000_000_007
SIZE = 1_000_000

class Main:
    def __init__(self):
        self.fac = [0] * SIZE
        self.inv = [0] * SIZE
        self.finv = [0] * SIZE
        self.sc = FastScanner()

    def solve(self):
        n = self.sc.next_int()
        m = self.sc.next_int()
        map_ = defaultdict(int)

        for _ in range(m):
            s = self.sc.next_int()
            c = self.sc.next_int()
            if map_[s] != 0 and map_[s] != c:
                print(-1)
                sys.exit(0)
            map_[s] = c

        for i in range(1000):
            s = str(i)
            flag = True
            if len(s) < n:
                continue
            for j in range(n):
                if (map_[j + 1] != 0 and map_[j + 1] != int(s[j])) or (map_[j + 1] == 0 and int(s[j]) != 0):
                    if map_[j + 1] == 0 and j == 0 and int(s[j]) == 1:
                        continue
                    flag = False
                    break
            if flag and len(s) == n:
                print(s)
                sys.exit(0)

        print(-1)

    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)

    def lcm(self, a, b):
        return a * b // self.gcd(a, b)

    def inv(self, a):
        return self.pow(a, MOD - 2)

    def pow(self, a, r):
        sum_ = 1
        while r > 0:
            if r & 1:
                sum_ *= a
                sum_ %= MOD
            a *= a
            a %= MOD
            r >>= 1
        return sum_

    def mod_fact(self, n):
        if n == 0:
            return 1
        return n * self.mod_fact(n - 1) % MOD

    def fact(self, n):
        if n == 0:
            return 1
        return n * self.fact(n - 1)

    def init_comb(self):
        self.fac[0] = self.fac[1] = 1
        self.inv[1] = 1
        self.finv[0] = self.finv[1] = 1
        for i in range(2, SIZE):
            self.fac[i] = self.fac[i - 1] * i % MOD
            self.inv[i] = MOD - self.inv[MOD % i] * (MOD // i) % MOD
            self.finv[i] = self.finv[i - 1] * self.inv[i] % MOD

    def mod_comb(self, n, r):
        if n < r or n < 0 or r < 0:
            return 0
        return self.fac[n] * self.finv[r] % MOD * self.finv[n - r] % MOD

    def comb(self, n, r):
        num = 1
        for i in range(1, r + 1):
            num = num * (n - i + 1) // i
        return num

    def is_prime(self, a):
        if a <= 1:
            return False
        for i in range(2, int(a**0.5) + 1):
            if a % i == 0:
                return False
        return True

    def next_permutation(self, s):
        s = list(s)
        pivot_pos = -1
        pivot = 0
        for i in range(len(s) - 2, -1, -1):
            if s[i] < s[i + 1]:
                pivot_pos = i
                pivot = s[i]
                break

        if pivot_pos == -1 and pivot == 0:
            return None

        L = pivot_pos + 1
        R = len(s) - 1
        min_pos = -1
        min_ = chr(ord('z') + 1)
        for i in range(R, L - 1, -1):
            if pivot < s[i]:
                if s[i] < min_:
                    min_ = s[i]
                    min_pos = i

        s[pivot_pos], s[min_pos] = s[min_pos], s[pivot_pos]
        s[L:] = sorted(s[L:])

        return ''.join(s)

    def next_permutation_array(self, a):
        for i in range(len(a) - 1, 0, -1):
            if a[i - 1] < a[i]:
                swap_index = self.find(a[i - 1], a, i, len(a) - 1)
                a[swap_index], a[i - 1] = a[i - 1], a[swap_index]
                a[i:] = sorted(a[i:])
                return True
        return False

    def find(self, dest, a, s, e):
        if s == e:
            return s
        m = (s + e + 1) // 2
        return self.find(dest, a, s, m - 1) if a[m] <= dest else self.find(dest, a, m, e)

    def elimination(self, a, b):
        n = len(a)
        for k in range(n - 1):
            for i in range(k + 1, n):
                f = -a[i][k] / a[k][k]
                for j in range(k + 1, n):
                    a[i][j] += f * a[k][j]
                b[i] += f * b[k]
            for i in range(n - 1, -1, -1):
                for j in range(i + 1, n):
                    b[i] -= a[i][j] * b[j]
                b[i] /= a[i][i]

class FastScanner:
    def __init__(self, file=sys.stdin):
        self.file = file
        self.buffer = []
        self.ptr = 0

    def next(self):
        while not self.buffer:
            line = self.file.readline()
            if not line:
                raise EOFError
            self.buffer = line.split()
        token = self.buffer.pop(0)
        return token

    def next_int(self):
        return int(self.next())

    def next_float(self):
        return float(self.next())

    def next_str(self):
        return self.next()

# End of Code
