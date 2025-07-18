Here's the Python code translated from the provided Java code:


import sys

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
        A_root = self.root(A)
        B_root = self.root(B)
        if A_root == B_root:
            return False
        if self.size(A) < self.size(B):
            A_root, B_root = B_root, A_root
        self.Parent[A_root] += self.Parent[B_root]
        self.Parent[B_root] = A_root
        return True

class FastScanner:
    def __init__(self):
        self.tokens = []
        self.pos = 0
        self.buffer = ''

    def next(self):
        while self.pos >= len(self.tokens):
            self.buffer = sys.stdin.readline()
            if not self.buffer:
                raise EOFError()
            self.tokens = self.buffer.split()
            self.pos = 0
        res = self.tokens[self.pos]
        self.pos += 1
        return res

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextchar(self):
        return self.next()[0]

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
    d = int(n**0.5) + 1
    for i in range(3, d, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    return (a + b - 1) // b

def lupper_division(a, b):
    return (a + b - 1) // b

def setArray(a):
    global scan
    return [scan.nextInt() for _ in range(a)]

def lsetArray(a):
    global scan
    return [scan.nextLong() for _ in range(a)]

def reverse(s):
    return s[::-1]

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
        if n % 2 == 1:
            res = res * x % mo
        x = x * x % mo
        n = n // 2
    return res

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
        a, b = b, a % b
        u, v = v, u - t * v
    u %= m
    if u < 0:
        u += m
    return u

mod = 10**9 + 7
eps = 1e-14
big = float('inf')
PI = 3.14159265358979323846262338327950288

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def lmax(a, b):
    return max(a, b)

def lmin(a, b):
    return min(a, b)

def factorial(i):
    return 1 if i == 0 else i * factorial(i-1)

def main():
    global scan
    scan = FastScanner()
    str_val = scan.next()
    if str_val[2] == str_val[3] and str_val[4] == str_val[5]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
#End of Code
