class UnionFind:
    def __init__(self, n):  # Initialize by -1
        self.Parent = [-1] * n

    def root(self, A):  # In which tree is A?
        if self.Parent[A] < 0:
            return A
        self.Parent[A] = self.root(self.Parent[A])
        return self.Parent[A]

    def size(self, A):  # size of tree which is include A
        return -self.Parent[self.root(A)]

    def connect(self, A, B):  # Connect A and B
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
        self.inp = iter(input, '')
        self.buffer = []

    def hasNextByte(self):
        if not self.buffer:
            try:
                self.buffer = next(self.inp)
            except StopIteration:
                return False
        return True

    def readByte(self):
        if self.hasNextByte():
            return self.buffer.pop(0)
        return -1

    def hasNext(self):
        while self.hasNextByte() and not self.buffer[0].isprintable():
            self.readByte()
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise StopIteration
        b = self.readByte()
        sb = []
        while b.isprintable():
            sb.append(b)
            b = self.readByte()
        return ''.join(sb)

    def nextLong(self):
        if not self.hasNext():
            raise StopIteration
        minus = False
        b = self.readByte()
        if b == '-':
            minus = True
            b = self.readByte()
        if not b.isdigit():
            raise ValueError
        n = 0
        while True:
            if b.isdigit():
                n = n * 10 + int(b)
            elif b == -1 or not b.isprintable():
                return -n if minus else n
            else:
                raise ValueError
            b = self.readByte()

    def nextInt(self):
        return int(self.nextLong())

    def nextDouble(self):
        return float(self.next())

    def nextchar(self):
        return self.readByte()

mod = 1000000007
eps = 1.0E-14
big = float('inf')
PI = 3.14159265358979323846262338327950288

def modlcm(a, b):
    return a * b * modint(gcd(a, b), mod)

def gcd(a, b):
    return gcd(b, a % b) if b > 0 else a

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
    d = int(n ** 0.5)
    for i in range(3, d + 1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    return a // b + (a % b != 0)

def lupper_division(a, b):
    return a // b + (a % b != 0)

def setArray(a):
    return [FastScanner().nextInt() for _ in range(a)]

def lsetArray(a):
    return [FastScanner().nextLong() for _ in range(a)]

def reverse(str):
    ch = list(str)
    a = len(str)
    for i in range(upper_division(a, 2)):
        ch[i], ch[a - 1 - i] = ch[a - 1 - i], ch[i]
    return ''.join(ch)

def printArray(que):
    for i in range(len(que) - 1):
        print(que[i], end=' ')
    print(que[-1])

def doublesort(a):
    return sorted(a, key=lambda x: x[0])

def ldoublesort(a):
    return sorted(a, key=lambda x: x[0])

def modpow(x, n, mo):
    sum = 1
    while n > 0:
        if n & 1 == 1:
            sum = sum * x % mo
        x = x * x % mo
        n >>= 1
    return sum

def revch(ch):
    ret = ch[::-1]
    return ret

def revint(ch):
    ret = ch[::-1]
    return ret

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
        x = a
        a, b = b, x

        u -= t * v
        x = u
        u, v = v, x
    u %= m
    if u < 0:
        u += m
    return u

def main():
    scan = FastScanner()
    str = scan.next()
    print("Yes" if str[2] == str[3] and str[4] == str[5] else "No")

if __name__ == "__main__":
    main()
# End of Code
