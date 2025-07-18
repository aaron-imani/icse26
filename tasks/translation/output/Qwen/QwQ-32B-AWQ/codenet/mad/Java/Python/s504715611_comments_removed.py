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
        A_root = self.root(A)
        B_root = self.root(B)
        if A_root == B_root:
            return False
        if self.size(A_root) < self.size(B_root):
            A_root, B_root = B_root, A_root
        self.Parent[A_root] += self.Parent[B_root]
        self.Parent[B_root] = A_root
        return True

class FastScanner:
    def __init__(self):
        import sys
        self.buf = sys.stdin.read().split()
        self.ptr = 0
        self.len = len(self.buf)
    def hasNext(self):
        return self.ptr < self.len
    def next(self):
        if self.ptr >= self.len:
            raise Exception("No more input")
        self.ptr += 1
        return self.buf[self.ptr - 1]
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())

scan = None

def lower_bound(a, key):
    left, right = 0, len(a)
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    left, right = 0, len(a)
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
    d = int(math.sqrt(n))
    for i in range(3, d+1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    return (a + b -1) // b

def lupper_division(a, b):
    return (a + b -1) // b

def setArray(a):
    return [scan.nextInt() for _ in range(a)]

def lsetArray(a):
    return [scan.nextLong() for _ in range(a)]

def reverse(s):
    return s[::-1]

def printArray(arr):
    print(' '.join(map(str, arr)))

def doublesort(a):
    return sorted(a, key=lambda x: x[0])

def ldoublesort(a):
    return sorted(a, key=lambda x: x[0])

def modpow(x, n, mo):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mo
        x = x * x % mo
        n >>= 1
    return res

def modint(a, m):
    original_m = m
    u, v = 1, 0
    while m != 0:
        q = a // m
        a, m = m, a % m
        u, v = v, u - q * v
    return u % original_m

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def modlcm(a, b):
    g = gcd(a, b)
    return (a * b // g) % mod

mod = 10**9 + 7
eps = 1e-14
big = float('inf')
PI = math.pi

if __name__ == "__main__":
    scan = FastScanner()
    s = scan.next()
    if len(s) >= 6 and s[2] == s[3] and s[4] == s[5]:
        print("Yes")
    else:
        print("No")
# End of Code
