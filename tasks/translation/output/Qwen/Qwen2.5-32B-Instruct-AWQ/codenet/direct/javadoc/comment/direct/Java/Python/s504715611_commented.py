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
        self.buffer = []
        self.ptr = 0

    def hasNextByte(self):
        if self.ptr < len(self.buffer):
            return True
        try:
            self.buffer = input().strip()
            self.ptr = 0
        except EOFError:
            return False
        return True

    def readByte(self):
        if self.hasNextByte():
            self.ptr += 1
            return ord(self.buffer[self.ptr - 1])
        return -1

    def isPrintableChar(self, c):
        return 33 <= c <= 126

    def hasNext(self):
        while self.hasNextByte() and not self.isPrintableChar(self.buffer[self.ptr]):
            self.ptr += 1
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise NoSuchElementException()
        sb = []
        b = self.readByte()
        while self.isPrintableChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return ''.join(sb)

    def nextLong(self):
        if not self.hasNext():
            raise NoSuchElementException()
        n = 0
        minus = False
        b = self.readByte()
        if b == ord('-'):
            minus = True
            b = self.readByte()
        if b < ord('0') or ord('9') < b:
            raise NumberFormatException()
        while True:
            if ord('0') <= b <= ord('9'):
                n *= 10
                n += b - ord('0')
            elif b == -1 or not self.isPrintableChar(b):
                return -n if minus else n
            else:
                raise NumberFormatException()
            b = self.readByte()

    def nextInt(self):
        nl = self.nextLong()
        if nl < -2**31 or nl > 2**31 - 1:
            raise NumberFormatException()
        return int(nl)

    def nextDouble(self):
        return float(self.next())

    def nextchar(self):
        try:
            return input()[0]
        except Exception as e:
            raise RuntimeError(e)


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

def is_prime(n):
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def upper_division(a, b):
    return a // b + (1 if a % b != 0 else 0)

def lupper_division(a, b):
    return a // b + (1 if a % b != 0 else 0)

def set_array(a):
    return [FastScanner().nextInt() for _ in range(a)]

def lset_array(a):
    return [FastScanner().nextLong() for _ in range(a)]

def reverse(s):
    return s[::-1]

def print_array(que):
    print(" ".join(map(str, que)))

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

if __name__ == "__main__":
    scan = FastScanner()
    str = scan.next()
    print("Yes" if str[2] == str[3] and str[4] == str[5] else "No")  # End of Code
