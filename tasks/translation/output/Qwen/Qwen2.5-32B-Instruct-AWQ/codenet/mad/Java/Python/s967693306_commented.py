import sys

class FastScanner:
    def __init__(self):
        self.inp = sys.stdin.read().split()

    def nextInt(self):
        return int(self.inp.pop(0))

    def nextLong(self):
        return int(self.inp.pop(0))

class Main:
    INF = float('inf') // 2
    MOD = 1_000_000_007
    SIZE = 1_000_000
    fac = [0] * SIZE
    inv = [0] * SIZE
    finv = [0] * SIZE

    def __init__(self):
        self.sc = FastScanner()

    def solve(self):
        n = self.sc.nextInt()
        m = self.sc.nextInt()
        map_ = {}

        for i in range(m):
            s = self.sc.nextInt()
            c = self.sc.nextInt()
            if s in map_ and map_[s] != c:
                print(-1)
                sys.exit(0)
            map_[s] = c

        for i in range(1000):
            s = str(i)
            flag = True
            if len(s) < n:
                continue
            for j in range(n):
                if (j + 1 in map_ and map_[j + 1] != int(s[j])) or (j + 1 not in map_ and int(s[j]) != 0):
                    if j + 1 not in map_ and j == 0 and int(s[j]) == 1:
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
        return self.pow(a, self.MOD - 2)

    def pow(self, a, r):
        sum_ = 1
        while r > 0:
            if r & 1:
                sum_ *= a
                sum_ %= self.MOD
            a *= a
            a %= self.MOD
            r >>= 1
        return sum_

    def modFact(self, n):
        if n == 0:
            return 1
        return n * self.modFact(n - 1) % self.MOD

    def fact(self, n):
        if n == 0:
            return 1
        return n * self.fact(n - 1)

    def initCOMB(self):
        self.fac[0] = self.fac[1] = 1
        self.inv[1] = 1
        self.finv[0] = self.finv[1] = 1
        for i in range(2, self.SIZE):
            self.fac[i] = self.fac[i - 1] * i % self.MOD
            self.inv[i] = self.MOD - self.inv[self.MOD % i] * (self.MOD // i) % self.MOD
            self.finv[i] = self.finv[i - 1] * self.inv[i] % self.MOD

    def modComb(self, n, r):
        if n < r or n < 0 or r < 0:
            return 0
        return self.fac[n] * self.finv[r] % self.MOD * self.finv[n - r] % self.MOD

    def comb(self, n, r):
        num = 1
        for i in range(1, r + 1):
            num = num * (n - i + 1) // i
        return num

    def isPrime(self, a):
        if a <= 1:
            return False
        for i in range(2, int(a**0.5) + 1):
            if a % i == 0:
                return False
        return True

    def nextPermutation(self, s):
        list_ = list(s)
        pivotPos = -1
        pivot = 0
        for i in range(len(list_) - 2, -1, -1):
            if list_[i] < list_[i + 1]:
                pivotPos = i
                pivot = list_[i]
                break

        if pivotPos == -1 and pivot == 0:
            return None

        L = pivotPos + 1
        R = len(list_) - 1
        minPos = -1
        min_ = chr(127)
        for i in range(R, L - 1, -1):
            if pivot < list_[i]:
                if list_[i] < min_:
                    min_ = list_[i]
                    minPos = i

        list_[pivotPos], list_[minPos] = list_[minPos], list_[pivotPos]
        list_[L:R + 1] = sorted(list_[L:R + 1])

        return ''.join(list_)

    def nextPermutation(self, a):
        for i in range(len(a) - 1, 0, -1):
            if a[i - 1] < a[i]:
                swapIndex = self.find(a[i - 1], a, i, len(a) - 1)
                a[swapIndex], a[i - 1] = a[i - 1], a[swapIndex]
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

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
