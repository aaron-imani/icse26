import sys

class FastScanner:
    def __init__(self):
        self.tokens = []
        self.n = 0

    def next(self):
        if self.n < len(self.tokens):
            self.n += 1
            return self.tokens[self.n-1]
        else:
            self.tokens = input().split()
            self.n = 1
            return self.tokens[0]

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())


class Main:
    INF = sys.maxsize // 2
    MOD = 1_000_000_007
    SIZE = 1_000_000

    def __init__(self):
        self.fac = [0] * self.SIZE
        self.inv = [0] * self.SIZE
        self.finv = [0] * self.SIZE
        self.sc = FastScanner()

    def solve(self):
        n = self.sc.next_int()
        m = self.sc.next_int()
        map_dict = {}

        for _ in range(m):
            s = self.sc.next_int()
            c = self.sc.next_int()
            if s in map_dict and map_dict[s] != c:
                print(-1)
                sys.exit(0)
            map_dict[s] = c

        for i in range(1000):
            s = str(i)
            flag = True
            if len(s) < n:
                continue
            for j in range(n):
                if (j + 1 in map_dict and map_dict[j + 1] != int(s[j])) or (j + 1 not in map_dict and int(s[j]) != 0):
                    if j == 0 and j + 1 not in map_dict and int(s[j]) == 1:
                        continue
                    flag = False
                    break
            if flag and len(s) == n:
                print(s)
                sys.exit(0)

        print(-1)

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def lcm(self, a, b):
        return a * b // self.gcd(a, b)

    def inv(self, a):
        return pow(a, self.MOD - 2, self.MOD)

    def pow(self, a, r):
        sum_val = 1
        while r > 0:
            if r & 1:
                sum_val = sum_val * a % self.MOD
            a = a * a % self.MOD
            r >>= 1
        return sum_val

    def mod_fact(self, n):
        return 1 if n == 0 else n * self.mod_fact(n - 1) % self.MOD

    def fact(self, n):
        return 1 if n == 0 else n * self.fact(n - 1)

    def init_comb(self):
        self.fac[0] = self.fac[1] = 1
        self.inv[1] = 1
        self.finv[0] = self.finv[1] = 1
        for i in range(2, self.SIZE):
            self.fac[i] = self.fac[i - 1] * i % self.MOD
            self.inv[i] = self.MOD - self.inv[self.MOD % i] * (self.MOD // i) % self.MOD
            self.finv[i] = self.finv[i - 1] * self.inv[i] % self.MOD

    def mod_comb(self, n, r):
        if n < r or n < 0 or r < 0:
            return 0
        return self.fac[n] * self.finv[r] % self.MOD * self.finv[n - r] % self.MOD

    def comb(self, n, r):
        num = 1
        for i in range(1, r + 1):
            num = num * (n - i + 1) // i
        return num

    def is_prime(self, a):
        if a <= 1:
            return False
        for i in range(2, int(a ** 0.5) + 1):
            if a % i ==  0:
                return False
        return True

    def next_permutation(self, s):
        list_s = list(s)
        pivot_pos = -1
        pivot = 0
        for i in range(len(list_s) - 2, -1, -1):
            if list_s[i] < list_s[i + 1]:
                pivot_pos = i
                pivot = list_s[i]
                break

        if pivot_pos == -1 and pivot == 0:
            return None

        l = pivot_pos + 1
        r = len(list_s) - 1
        min_pos = -1
        min_char = chr(ord('z') + 1)
        for i in range(r, l - 1, -1):
            if pivot < list_s[i]:
                if list_s[i] < min_char:
                    min_char = list_s[i]
                    min_pos = i

        list_s[pivot_pos], list_s[min_pos] = list_s[min_pos], list_s[pivot_pos]
        list_s[l:r + 1] = sorted(list_s[l:r + 1])

        return ''.join(list_s)

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


if __name__ == "__main__":
    main = Main()
    main.solve()  # End of Code
