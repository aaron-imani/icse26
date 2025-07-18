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
        self.tokens = sys.stdin.read().split()
        self.ptr = 0

    def next(self):
        if self.ptr >= len(self.tokens):
            raise EOFError()
        self.ptr += 1
        return self.tokens[self.ptr - 1]

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextchar(self):
        if self.ptr < len(self.tokens):
            return self.tokens[self.ptr]
        else:
            raise EOFError()

mod = 10**9 + 7
big = float('inf')
eps = 1.0e-14
PI = 3.14159265358979323846262338327950288

def modlcm(a, b):
    return a * b * modint(gcd(a, b), mod)

def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a

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
    return 1 if i == 1 else i * factorial(i-1)

def lower_bound(a, key):
    left, right = 0, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    left, right = # noqa: E265
    0, len(a)
    while right - left > 1:
        mid = (left + right) // 2
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
    return a // b if a % b == 0 else a // b + 1

def lupper_division(a, b):
    return a // b if a % b == 0 else a // b + 1

def setArray(a):
    global scan
    return [int(scan.next()) for _ in range(a)]

def lsetArray(a):
    global scan
    return [scan.nextLong() for _ in range(a)]

def reverse(s):
    ch = list(s)
    a = len(ch)
    for i in range(upper_division(a, 2)):
        ch[i] = s[len(s)-i-1]
        ch[len(ch)-1 -i] = s[i]
    return ''.join(ch)

def printArray(que):
    for i in range(len(que)-1):
        print(que[i], end=' ')
    print(que[-1])

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
    b = m
    u, v = 1, 0
    while b != 0:
        t = a // b
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m
    if u < 0:
        u += m
    return u

def main():
    global scan
    scan = FastScanner()
    str = scan.next()
    print("Yes" if str[2] == str[3] and str[4] == str[5] else "No")

if __name__ == "__main__":
    main()  # End of Code
