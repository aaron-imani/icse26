import sys

class FastScanner:
    def __init__(self):
        self.buf = ''
        self.ptr = 0
    def input(self):
        while self.ptr >= len(self.buf):
            self.buf = sys.stdin.read(1024)
            self.ptr = 0
            if not self.buf:
                self.buf = ''
                break
    def next(self):
        while self.buf.strip() == '':
            self.input()
        res = []
        while self.ptr < len(self.buf) and self.buf[self.ptr] in ' \t\n\r':
            self.ptr +=1
        while self.ptr < len(self.buf) and self.buf[self.ptr] not in ' \t\n\r':
            res.append(self.buf[self.ptr])
            self.ptr +=1
        return ''.join(res)
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())
    def nextchar(self):
        self.input()
        while self.ptr < len(self.buf) and self.buf[self.ptr] in ' \t\n\r':
            self.ptr +=1
        if self.ptr >= len(self.buf):
            return ''
        c = self.buf[self.ptr]
        self.ptr +=1
        return c

scan = FastScanner()

mod = 1000000007
eps = 1.0e-14
big = (1 << 31) - 1
PI = 3.14159265358979323846262338327950288

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

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
    if i == 1:
        return 1
    else:
        return i * factorial(i-1)

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
    d = int(n ** 0.5) + 1
    for i in range(3, d, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1

def lupper_division(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1

def setArray(a):
    arr = []
    for _ in range(a):
        arr.append(scan.nextInt())
    return arr

def lsetArray(a):
    arr = []
    for _ in range(a):
        arr.append(scan.nextLong())
    return arr

def reverse(s):
    return s[::-1]

def revch(ch):
    return ch[::-1]

def revint(ch):
    return ch[::-1]

def printArray(que):
    print(' '.join(map(str, que)))

def doublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def ldoublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def modpow(x, n, mo):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mo
        x = x * x % mo
        n >>= 1
    return res

def warshall_floyd(v, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if v[i][j] > v[i][k] + v[k][j]:
                    v[i][j] = v[i][k] + v[k][j]

def modint(a, m):
    b, u, v = m, 1, 0
    while b != 0:
        t = a // b
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m
    if u < 0:
        u += m
    return u

class UnionFind:
    def __init__(self, n):
        self.Parent = [-1] * n

    def root(self, A):
        if self.Parent[A] < 0:
            return A
        else:
            self.Parent[A] = self.root(self.Parent[A])
            return self.Parent[A]

    def size(self, A):
        return -self.Parent[self.root(A)]

    def connect(self, A, B):
        rootA = self.root(A)
        rootB = self.root(B)
        if rootA == rootB:
            return False
        if self.size(rootA) < self.size(rootB):
            rootA, rootB = rootB, rootA
        self.Parent[rootA] += self.Parent[rootB]
        self.Parent[rootB] = rootA
        return True

if __name__ == "__main__":
    s = scan.next()
    if len(s) >=6 and s[2] == s[3] and s[4] == s[5]:
        print("Yes")
    else:
        print("No")
# End of Code
