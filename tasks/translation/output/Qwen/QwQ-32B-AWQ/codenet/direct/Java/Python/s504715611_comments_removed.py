import math

mod = 10**9 +7
eps = 1e-14
big = 2**31 -1
PI = 3.14159265358979323846262338327950288

class UnionFind:
    def __init__(self, n):
        self.Parent = [-1] * n
    def root(self, A):
        if self.Parent[A] < 0:
            return A
        self.Parent[A] = self.root(self.Parent[A])
        return self.Parent[A]
    def size(self, A):
        r = self.root(A)
        return -self.Parent[r]
    def connect(self, A, B):
        ra = self.root(A)
        rb = self.root(B)
        if ra == rb:
            return False
        if self.size(ra) < self.size(rb):
            ra, rb = rb, ra
        self.Parent[ra] += self.Parent[rb]
        self.Parent[rb] = ra
        return True

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
    d = int(math.sqrt(n)) + 1
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
    return [int(input()) for _ in range(a)]

def lsetArray(a):
    return [int(input()) for _ in range(a)]

def reverse(s):
    return s[::-1]

def printArray(arr):
    print(' '.join(map(str, arr)))

def doublesort(arr):
    arr.sort(key=lambda x: x[0])
    return arr

def ldoublesort(arr):
    arr.sort(key=lambda x: x[0])
    return arr

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
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m
    if u < 0:
        u += m
    return u

def gcd(a, b):
    return gcd(b, a % b) if b !=0 else a

def modlcm(a, b):
    g = gcd(a, b)
    return a * b * modint(g, mod)

if __name__ == "__main__":
    s = input().strip()
    if len(s) >=6:
        if s[2] == s[3] and s[4] == s[5]:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
# End of Code
