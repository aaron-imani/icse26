import sys
from typing import List

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
    def __init__(self):
        self.tokens = []
        self.token_index = 0
        self.buffer = sys.stdin.read().split()

    def hasNext(self):
        return self.token_index < len(self.buffer)

    def next(self):
        if not self.hasNext():
            raise Exception("No more tokens")
        token = self.buffer[self.token_index]
        self.token_index += 1
        return token

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

def modpow(x, n, mo):
    sum_val = 1
    while n > 0:
        if n & 1 == 1:
            sum_val = sum_val * x % mo
        x = x * x % mo
        n >>= 1
    return sum_val

def modint(a, m):
    b, u, v = m, 1, 0
    while b != 0:
        t = a // b
        a -= t * b
        x = a
        a, b = b, x

        u -= t * v
        x = u
        u, v = v, x
    u %= m
    if u < 0:
        u += m
    return u

def lower_bound(a: List[int], key: int):
    right, left = len(a), 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a: List[int], key: int):
    right, left = len(a), 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] <= key:
            left = mid
        else:
            right = mid
    return left

def isPrime(n: int):
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    d = int(n ** 0.5)
    for i in range(3, d + 1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a: int, b: int):
    return a // b + (a % b > 0)

def lupper_division(a: int, b: int):
    return a // b + (a % b > 0)

def setArray(a: int):
    return [int(FastScanner().next()) for _ in range(a)]

def lsetArray(a: int):
    return [int(FastScanner().nextLong()) for _ in range(a)]

def reverse(s: str):
    ch = list(s)
    a = len(s)
    for i in range(upper_division(a, 2)):
        ch[i], ch[a - i - 1] = ch[a - i - 1], ch[i]
    return ''.join(ch)

def printArray(que: List[int]):
    for i in range(len(que) - 1):
        print(que[i], end=" ")
    print(que[-1])

def doublesort(a: List[List[int]]):
    a.sort(key=lambda x: x[0])
    return a

def ldoublesort(a: List[List[int]]):
    a.sort(key=lambda x: x[0])
    return a

def warshall_floyd(v: List[List[int]], n: int):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                v[i][j] = min(v[i][j], v[i][k] + v[k][j])

if __name__ == "__main__":
    scan = FastScanner()
    str = scan.next()
    print("Yes" if str[2] == str[3] and str[4] == str[5] else "No")  # End of Code
