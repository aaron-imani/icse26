import sys
import math

class UnionFind:
    def __init__(self, n):
        self.Parent = [-1] * n

    def root(self, A):
        if self.Parent[A] < 0:
            return A
        self.Parent[A] = self.root(self.Parent[A])
        return self.Parent[A]

    def size(self, A):
        return -self.Parent[self.root(A)]

    def connect(self, A, B):
        A = self.root(A)
        B = self.root(B)
        if A == B:
            return False
        if self.size(A) < self.size(B):
            A, B = B, A
        self.Parent[A] += self.Parent[B]
        self.Parent[B] = A
        return True

class FastScanner:
    def __init__(self, file=sys.stdin):
        self.file = file
        self.buffer = []
        self.ptr = 0

    def _next_line(self):
        self.buffer = self.file.readline().split()
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.buffer):
            self._next_line()
        result = self.buffer[self.ptr]
        self.ptr += 1
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

def modlcm(a, b):
    return a * b * modint(gcd(a, b), mod)

def gcd(a, b):
    return b if b > 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def lmax(a, b):
    return max(a, b)

def lmin(a, b):
    return min(a, b)

def factorial(i):
    return 1 if i == 1 else i * factorial(i - 1)

def lower_bound(a, key):
    right = len(a)
    left = 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    right = len(a)
    left = 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] <= key:
            left = mid
        else:
            right = mid
    return left

def isPrime(n):
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    d = math.sqrt(n)
    for i in range(3, int(d) + 1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    return a // b if a % b == 0 else a // b + 1

def lupper_division(a, b):
    return a // b if a % b == 0 else a // b + 1

def setArray(a):
    return [FastScanner().nextInt() for _ in range(a)]

def lsetArray(a):
    return [FastScanner().nextLong() for _ in range(a)]

def reverse(s):
    return s[::-1]

def printArray(que):
    print(" ".join(map(str, que)))

def doublesort(a):
    return sorted(a, key=lambda x: x[0])

def ldoublesort(a):
    return sorted(a, key=lambda x: x[0])

def modpow(x, n, mo):
    sum = 1
    while n > 0:
        if n & 1:
            sum = sum * x % mo
        x = x * x % mo
        n >>= 1
    return sum

def revch(ch):
    return ch[::-1]

def revint(ch):
    return ch[::-1]

def warshall_floyd(v, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                v[i][j] = min(v[i][j], v[i][k] + v[k][j])

def modint(a, m):
    b, u, v = m, 1, 0
    while b != 0:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u

mod = 1000000007
eps = 1.0E-14
big = sys.maxsize
PI = 3.14159265358979323846262338327950288

scan = FastScanner()
str_input = scan.next()
print("Yes" if str_input[2] == str_input[3] and str_input[4] == str_input[5] else "No")

# End of Code
