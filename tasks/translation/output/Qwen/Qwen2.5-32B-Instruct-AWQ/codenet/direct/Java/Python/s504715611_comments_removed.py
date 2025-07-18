import sys
from typing import List

class UnionFind:
    def __init__(self, n: int):
        self.Parent = [-1] * n

    def root(self, A: int) -> int:
        if self.Parent[A] < 0:
            return A
        self.Parent[A] = self.root(self.Parent[A])
        return self.Parent[A]

    def size(self, A: int) -> int:
        return -self.Parent[self.root(A)]

    def connect(self, A: int, B: int) -> bool:
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

    def hasNext(self) -> bool:
        return self.token_index < len(self.buffer)

    def next(self) -> str:
        if not self.hasNext():
            raise Exception("No more tokens")
        token = self.buffer[self.token_index]
        self.token_index += 1
        return token

    def nextInt(self) -> int:
        return int(self.next())

    def nextLong(self) -> int:
        return int(self.next())

    def nextDouble(self) -> float:
        return float(self.next())

def main():
    scan = FastScanner()
    str = scan.next()
    print("Yes" if str[2] == str[3] and str[4] == str[5] else "No")

def lower_bound(a: List[int], key: int) -> int:
    right = len(a)
    left = 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a: List[int], key: int) -> int:
    right = len(a)
    left = 0
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] <= key:
            left = mid
        else:
            right = mid
    return left

def isPrime(n: int) -> bool:
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    d = int(n ** 0.5)
    for i in range(3, d + 1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a: int, b: int) -> int:
    return a // b + (a % b > 0)

def lupper_division(a: int, b: int) -> int:
    return a // b + (a % b > 0)

def setArray(a: int) -> List[int]:
    return [scan.nextInt() for _ in range(a)]

def lsetArray(a: int) -> List[int]:
    return [scan.nextLong() for _ in range(a)]

def reverse(str: str) -> str:
    return str[::-1]

def printArray(que: List[int]):
    print(" ".join(map(str, que)))

def doublesort(a: List[List[int]]) -> List[List[int]]:
    a.sort(key=lambda x: x[0])
    return a

def ldoublesort(a: List[List[int]]) -> List[List[int]]:
    a.sort(key=lambda x: x[0])
    return a

def modpow(x: int, n: int, mo: int) -> int:
    sum = 1
    while n > 0:
        if n & 1 == 1:
            sum = sum * x % mo
        x = x * x % mo
        n >>= 1
    return sum

def revch(ch: List[str]) -> List[str]:
    return ch[::-1]

def revint(ch: List[int]) -> List[int]:
    return ch[::-1]

def warshall_floyd(v: List[List[int]], n: int):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                v[i][j] = min(v[i][j], v[i][k] + v[k][j])

def modint(a: int, m: int) -> int:
    b = m
    u = 1
    v = 0
    while b != 0:
        t = a // b
        a -= t * b
        x = a
        a = b
        b = x
        u -= t * v
        x = u
        u = v
        v = x
    u %= m
    if u < 0:
        u += m
    return u

if __name__ == "__main__":
    main()
# End of Code
