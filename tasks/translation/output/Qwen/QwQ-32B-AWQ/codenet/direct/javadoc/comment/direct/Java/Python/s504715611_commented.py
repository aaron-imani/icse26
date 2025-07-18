import sys
import math

mod = 10**9 +7
eps = 1e-14
big = 2**31 -1
PI = 3.14159265358979323846262338327950288

class UnionFind:
    def __init__(self, n):
        self.Parent = [-1]*n
    def root(self, A):
        if self.Parent[A] <0:
            return A
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

class FastScanner:
    def __init__(self):
        import sys
        self.data = sys.stdin.read().split()
        self.ptr = 0
    def next(self):
        if self.ptr >= len(self.data):
            raise IndexError("No more tokens.")
        res = self.data[self.ptr]
        self.ptr +=1
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
    left = 0
    right = len(a)
    while right - left >1:
        mid = (right+left)//2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    left =0
    right = len(a)
    while right -left>1:
        mid = (right+left)//2
        if a[mid]<=key:
            left = mid
        else:
            right = mid
    return left

def isPrime(n):
    if n ==2:
        return True
    if n<2 or n%2 ==0:
        return False
    d = int(math.sqrt(n)) +1
    for i in range(3, d, 2):
        if n%i ==0:
            return False
    return True

def upper_division(a, b):
    return (a +b -1)//b

def lupper_division(a, b):
    return (a +b -1)//b

def setArray(a):
    global scan
    return [int(scan.next()) for _ in range(a)]

def lsetArray(a):
    global scan
    return [int(scan.nextLong()) for _ in range(a)]

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
    ret =1
    while n>0:
        if n%2 ==1:
            ret = ret *x %mo
        x =x*x %mo
        n =n//2
    return ret

def revch(ch):
    return ch[::-1]

def revint(ch):
    return ch[::-1]

def warshall_floyd(v, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                v[i][j] = min(v[i][j], v[i][k]+v[k][j])

def modint(a, m):
    b = m
    u =1
    v =0
    while b !=0:
        t = a//b
        a, b = b, a%b
        u, v = v, u - t*v
    u %=m
    if u <0:
        u +=m
    return u

def modlcm(a, b):
    g = math.gcd(a, b)
    return (a * b * modint(g, mod)) % mod

def gcd(a, b):
    return math.gcd(a, b)

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def lmax(a, b):
    return max(a, b)

def lmin(a, b):
    return min(a, b)

def factorial(i):
    if i ==1:
        return 1
    return i * factorial(i-1)

if __name__ == "__main__":
    scan = FastScanner()
    str_input = scan.next()
    if str_input[2] == str_input[3] and str_input[4] == str_input[5]:
        print("Yes")
    else:
        print("No")
# End of Code
