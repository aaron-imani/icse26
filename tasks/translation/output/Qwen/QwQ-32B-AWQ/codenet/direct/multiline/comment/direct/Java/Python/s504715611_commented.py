mod = 10**9 +7

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
        A_root = self.root(A)
        B_root = self.root(B)
        if A_root == B_root:
            return False
        if self.size(A) < self.size(B):
            A_root, B_root = B_root, A_root
        self.Parent[A_root] += self.Parent[B_root]
        self.Parent[B_root] = A_root
        return True

def gcd(a, b):
    while b !=0:
        a, b = b, a%b
    return a

def modint(a, m):
    b = m
    u = 1
    v = 0
    while b !=0:
        t = a // b
        rem = a - t * b
        a, b = b, rem
        temp_u = u - t * v
        u, v = v, temp_u
    u %= m
    if u <0:
        u += m
    return u

def modlcm(a, b):
    g = gcd(a, b)
    return (a * b * modint(g, mod)) % mod

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
    return i * factorial(i-1)

def lower_bound(a, key):
    right = len(a)
    left =0
    while right - left >1:
        mid = (right + left)//2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    right = len(a)
    left =0
    while right - left >1:
        mid = (right + left)//2
        if a[mid] <= key:
            left = mid
        else:
            right = mid
    return left

import math

def isPrime(n):
    if n ==2:
        return True
    if n <2 or n%2 ==0:
        return False
    d = math.sqrt(n)
    for i in range(3, int(d)+1, 2):
        if n%i ==0:
            return False
    return True

def upper_division(a, b):
    return (a + b -1) // b

def lupper_division(a, b):
    return (a + b -1) // b

def setArray(a):
    res = [0]*a
    for i in range(a):
        res[i] = scan.nextInt()
    return res

def lsetArray(a):
    res = [0]*a
    for i in range(a):
        res[i] = scan.nextLong()
    return res

def reverse(s):
    ch = list(s)
    a = len(ch)
    for i in range( (a +1)//2 ):
        ch[i], ch[a-1 -i] = ch[a-1 -i], ch[i]
    return ''.join(ch)

def printArray(arr):
    for i in range(len(arr)-1):
        print(arr[i], end=' ')
    print(arr[-1])

def doublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def ldoublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def modpow(x, n, mo):
    res = 1
    while n >0:
        if n &1:
            res = res * x % mo
        x = x * x % mo
        n >>=1
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

class FastScanner:
    def __init__(self):
        import sys
        self.tokens = []
        self.ptr = 0
        self.buf = sys.stdin.read().split()
    def next(self):
        if self.ptr >= len(self.buf):
            raise Exception("No more tokens")
        res = self.buf[self.ptr]
        self.ptr +=1
        return res
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())

def main():
    global scan
    scan = FastScanner()
    str = scan.next()
    if str[2] == str[3] and str[4] == str[5]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()  # End of Code
