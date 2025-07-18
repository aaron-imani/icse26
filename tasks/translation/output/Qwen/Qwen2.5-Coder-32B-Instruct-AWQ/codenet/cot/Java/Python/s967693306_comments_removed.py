import sys

INF = sys.maxsize // 2
MOD = 1_000_000_007
SIZE = 1_000_000
fac = [0] * SIZE
inv = [0] * SIZE
finv = [0] * SIZE

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def inv(a):
    return pow(a, MOD - 2)

def pow(a, r):
    sum = 1
    while r > 0:
        if r & 1:
            sum *= a
            sum %= MOD
        a *= a
        a %= MOD
        r >>= 1
    return sum

def modFact(n):
    if n == 0:
        return 1
    return n * modFact(n - 1) % MOD

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

def initCOMB():
    fac[0] = fac[1] = 1
    inv[1] = 1
    finv[0] = finv[1] = 1
    for i in range(2, SIZE):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD

def modComb(n, r):
    if n < r or n < 0 or r < 0:
        return 0
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD

def comb(n, r):
    num = 1
    for i in range(1, r + 1):
        num = num * (n - i + 1) // i
    return num

def isPrime(a):
    if a <= 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

def nextPermutation(s):
    s = list(s)
    pivotPos = -1
    pivot = 0
    for i in range(len(s) - 2, -1, -1):
        if s[i] < s[i + 1]:
            pivotPos = i
            pivot = s[i]
            break

    if pivotPos == -1 and pivot == 0:
        return None

    L = pivotPos + 1
    R = len(s) - 1
    minPos = -1
    min_val = chr(ord('z') + 1)
    for i in range(R, L - 1, -1):
        if pivot < s[i]:
            if s[i] < min_val:
                min_val = s[i]
                minPos = i

    s[pivotPos], s[minPos] = s[minPos], s[pivotPos]
    s[L:] = sorted(s[L:])

    return ''.join(s)

def nextPermutation_arr(a):
    for i in range(len(a) - 1, 0, -1):
        if a[i - 1] < a[i]:
            swapIndex = find(a[i - 1], a, i, len(a) - 1)
            a[swapIndex], a[i - 1] = a[i - 1], a[swapIndex]
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

class Pair:
    def __init__(self, i, j):
        self.a = i
        self.b = j

    def __lt__(self, other):
        return self.b < other.b

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0

    def nextInt():
        nonlocal index
        result = int(data[index])
        index += 1
        return result

    n = nextInt()
    m = nextInt()
    map = {}

    for _ in range(m):
        s = nextInt()
        c = nextInt()
        if s in map and map[s] != c:
            print(-1)
            sys.exit(0)
        map[s] = c

    for i in range(1000):
        s = str(i)
        flag = True
        if len(s) < n:
            continue
        for j in range(n):
            if (j + 1 in map and map[j + 1] != int(s[j])) or (j + 1 not in map and int(s[j]) != 0):
                if j + 1 not in map and j == 0 and int(s[j]) == 1:
                    continue
                flag = False
                break
        if flag and len(s) == n:
            print(s)
            sys.exit(0)

    print(-1)

if __name__ == "__main__":
    solve()
# End of Code
