import sys

class FastScanner:
    def __init__(self):
        self.tokens = []
        self.token_index = 0
        self.input_stream = sys.stdin

    def next(self):
        while not self.tokens:
            self.tokens = self.input_stream.readline().strip().split()
            self.token_index = 0
        token = self.tokens[self.token_index]
        self.token_index += 1
        return token

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())


INF = float('inf') // 2
MOD = 1_000_000_007
SIZE = 1_000_000


def gcd(a, b):  # return a and b's greatest common divisor
    if b == 0:
        return a
    return gcd(b, a % b)


def lcm(a, b):  # return a and b's least common multiple
    return a * b // gcd(a, b)


def inv(a):  # return a's inverse modulo MOD
    return pow(a, MOD - 2, MOD)


def pow_mod(a, r):  # return a^r modulo MOD
    result = 1
    while r > 0:
        if r & 1:  # if the last bit is 1
            result = result * a % MOD
        a = a * a % MOD
        r >>= 1
    return result


def mod_fact(n):  # return n! modulo MOD
    if n == 0:
        return 1
    return n * mod_fact(n - 1) % MOD


def fact(n):  # return n!
    if n == 0:
        return 1
    return n * fact(n - 1)


def init_comb():
    global fac, inv, finv
    fac = [1] * SIZE
    inv = [1] * SIZE
    finv = [1] * SIZE
    for i in range(2, SIZE):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD


def mod_comb(n, r):  # return nCr modulo MOD (init_comb must be called first)
    if n < r or n < 0 or r < 0:
        return 0
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD


def comb(n, r):  # return nCr
    num = 1
    for i in range(1, r + 1):
        num = num * (n - i + 1) // i
    return num


def is_prime(a):  # prime check for a
    if a <= 1:
        return False
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return False
    return True


def next_permutation(s):  # return the next permutation of s
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


def next_permutation_array(a):
    for i in range(len(a) - 1, 0, -1):
        if a[i - 1] < a[i]:
            swap_index = find(a[i - 1], a, i, len(a) - 1)
            a[swap_index], a[i - 1] = a[i - 1], a[swap_index]
            a[i:] = sorted(a[i:])
            return True
    return False


def find(dest, a, s, e):
    if s == e:
        return s
    m = (s + e + 1) // 2
    return find(dest, a, s, m - 1) if a[m] <= dest else find(dest, a, m, e)


def elimination(a, b):
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


class Main:
    def __init__(self):
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
                exit(0)
            map_dict[s] = c

        for i in range(1000):
            s = str(i)
            flag = True
            if len(s) < n:
                continue
            for j in range(n):
                if (j + 1 in map_dict and map_dict[j + 1] != int(s[j])) or (j + 1 not in map_dict and int(s[j]) != 0):
                    if j + 1 not in map_dict and j == 0 and int(s[j]) == 1:
                        continue
                    flag = False
                    break
            if flag and len(s) == n:
                print(s)
                exit(0)

        print(-1)


if __name__ == "__main__":
    main = Main()
    main.solve()

# End of Code
